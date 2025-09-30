#include "referee_pkg/msg/detail/object__struct.hpp"
#include "referee_pkg/referee_pkg.hpp"
#include "utils.hpp"
#include <boost/smart_ptr/detail/local_counted_base.hpp>
#include <geometry_msgs/msg/detail/point__struct.hpp>
#include <opencv2/calib3d.hpp>
#include <std_msgs/msg/detail/header__struct.hpp>

void Referee::callback_Object(
    const referee_pkg::msg::MultiObject::SharedPtr msg) {
  object_pose_infos.clear();
  // 处理每个物体
  auto PnPSolve = [this](const referee_pkg::msg::Object object,
                         const std::vector<cv::Point3f> object_points)
      -> referee_pkg::ObjectPoseInfo {
    referee_pkg::ObjectPoseInfo object_info;

    // 提取2D图像坐标
    std::vector<cv::Point2f> image_points;
    for (const auto &corner : object.corners) {
      image_points.push_back(cv::Point2f(corner.x, corner.y));
    }

    // 执行PnP解算
    cv::Mat rvec, tvec;
    bool success = cv::solvePnP(
        object_points, image_points, referee_pkg::CAMERA_MATRIX,
        referee_pkg::DIST_COEFFS, rvec, tvec, false, cv::SOLVEPNP_ITERATIVE);

    if (success) {
      object_info.target_type = object.target_type;
      object_info.rvec = rvec.clone();
      object_info.tvec = tvec.clone();

      // 填充位置信息
      // 此处相机被设在坐标原点 故而可以这么直接使用 tvec
      object_info.pose.position.x = tvec.at<double>(0);
      object_info.pose.position.y = tvec.at<double>(1);
      object_info.pose.position.z = tvec.at<double>(2);

      // 将旋转向量转换为四元数
      cv::Mat rotation_matrix; // solvepnp 返回的 rvec 是旋转向量
      cv::Rodrigues(rvec, rotation_matrix);

      // 从旋转矩阵转换为四元数
      // 使用 tf2 命名空间
      tf2::Matrix3x3 tf_rotation_matrix(
          rotation_matrix.at<double>(0, 0), rotation_matrix.at<double>(0, 1),
          rotation_matrix.at<double>(0, 2), rotation_matrix.at<double>(1, 0),
          rotation_matrix.at<double>(1, 1), rotation_matrix.at<double>(1, 2),
          rotation_matrix.at<double>(2, 0), rotation_matrix.at<double>(2, 1),
          rotation_matrix.at<double>(2, 2));

      tf2::Quaternion tf_quaternion;
      tf_rotation_matrix.getRotation(tf_quaternion);

      object_info.pose.orientation.x = tf_quaternion.x();
      object_info.pose.orientation.y = tf_quaternion.y();
      object_info.pose.orientation.z = tf_quaternion.z();
      object_info.pose.orientation.w = tf_quaternion.w();
      // 计算距离
      object_info.distance = cv::norm(tvec);

      // 查找对应的Gazebo模型名称
      auto it = referee_pkg::TARGET_DIMENSIONS.find(object.target_type);
      if (it != referee_pkg::TARGET_DIMENSIONS.end()) {
        object_info.model_name = it->first;
      }
    }
    return object_info;
  };

  auto RectifyCirclePoint = [](referee_pkg::msg::Object &Circle) {
    Circle.corners[0].set__y(Circle.corners[1].y);
    Circle.corners[1].set__x(Circle.corners[2].x);
    Circle.corners[2].set__y(Circle.corners[3].y);
    Circle.corners[3].set__x(Circle.corners[0].x);
    return Circle;
  };
  auto STAGE1Function = [&]() -> bool {
    if (msg->objects.size() != 2) {
      return 0;
    }
    if (referee_pkg::DetectModel[RaceStage::STAGE_1].find(
            msg->objects[0].target_type) ==
        referee_pkg::DetectModel[RaceStage::STAGE_1].end()) {
      return 0;
    }
    if (referee_pkg::DetectModel[RaceStage::STAGE_1].find(
            msg->objects[1].target_type) ==
        referee_pkg::DetectModel[RaceStage::STAGE_1].end()) {
      return 0;
    }
    auto &Circle1 = msg->objects[0];
    auto &Circle2 = msg->objects[1];
    // 检查角点数量
    if (Circle1.corners.size() != 4) {
      return 0;
    }
    RectifyCirclePoint(Circle1);
    // 获取该目标类型的3D坐标点
    std::vector<cv::Point3f> Circle1_points;
    auto dims_it = referee_pkg::TARGET_DIMENSIONS.find(Circle1.target_type);
    if (dims_it != referee_pkg::TARGET_DIMENSIONS.end()) {
      const auto &dims = dims_it->second;
      Circle1_points = {
          cv::Point3f(-dims.width * referee_pkg::RINGRATIO / 2, 0,
                      -dims.height * referee_pkg::RINGRATIO / 2), // 左下
          cv::Point3f(dims.width * referee_pkg::RINGRATIO / 2, 0,
                      -dims.height * referee_pkg::RINGRATIO / 2), // 右下
          cv::Point3f(dims.width * referee_pkg::RINGRATIO / 2, 0,
                      dims.height * referee_pkg::RINGRATIO / 2), // 右上
          cv::Point3f(-dims.width * referee_pkg::RINGRATIO / 2, 0,
                      dims.height * referee_pkg::RINGRATIO / 2) // 左上
      };
    } else {
      return 0;
    }
    // 存储到vector中

    object_pose_infos.push_back(PnPSolve(Circle1, Circle1_points));
    if (Circle2.corners.size() != 4) {
      return 0;
    }
    RectifyCirclePoint(Circle2);
    // 获取该目标类型的3D坐标点
    std::vector<cv::Point3f> Circle2_points;
    dims_it = referee_pkg::TARGET_DIMENSIONS.find(Circle2.target_type);
    if (dims_it != referee_pkg::TARGET_DIMENSIONS.end()) {
      const auto &dims = dims_it->second;
      Circle2_points = {
          cv::Point3f(-dims.width / 2, 0, -dims.height / 2), // 左下
          cv::Point3f(dims.width / 2, 0, -dims.height / 2),  // 右下
          cv::Point3f(dims.width / 2, 0, dims.height / 2),   // 右上
          cv::Point3f(-dims.width / 2, 0, dims.height / 2)   // 左上
      };
    } else {
      return 0;
    }
    // 存储到vector中
    object_pose_infos.push_back(PnPSolve(Circle2, Circle2_points));

    // RCLCPP_INFO(this->get_logger(),
    //             "Object %zu (%s): Position [%.3f, %.3f, %.3f], Distance:
    //             %.3f", i, object.target_type.c_str(),
    //             object_info.pose.position.x,
    //             object_info.pose.position.y,
    //             object_info.pose.position.z,
    //             object_info.distance);

    data_matcher_->addObjectData(msg->header.stamp, object_pose_infos);
    addError(Errorresults); // 接受到一次信息就计算一次信息的误差而非到最后计算

    return true;
  };
  auto STAGE2Function = [&]() -> bool {
    for (size_t i = 0; i < msg->objects.size(); ++i) {
      const auto &object = msg->objects[i];
      if (referee_pkg::DetectModel[RaceStage::STAGE_2].find(
              object.target_type) ==
          referee_pkg::DetectModel[RaceStage::STAGE_2].end()) {
        return 0;
      }
      // 检查角点数量
      if (object.corners.size() != 4) {
        RCLCPP_WARN(this->get_logger(),
                    "Object %zu '%s' has %zu corners, expected 4", i,
                    object.target_type.c_str(), object.corners.size());
        continue;
      }

      // 获取该目标类型的3D坐标点
      std::vector<cv::Point3f> object_points;
      auto dims_it = referee_pkg::TARGET_DIMENSIONS.find(object.target_type);
      if (dims_it != referee_pkg::TARGET_DIMENSIONS.end()) {
        const auto &dims = dims_it->second;
        object_points = {
            cv::Point3f(-dims.width / 2, 0, -dims.height / 2), // 左下
            cv::Point3f(dims.width / 2, 0, -dims.height / 2),  // 右下
            cv::Point3f(dims.width / 2, 0, dims.height / 2),   // 右上
            cv::Point3f(-dims.width / 2, 0, dims.height / 2)   // 左上
        };
      } else {
        return 0;
      }
      object_pose_infos.push_back(PnPSolve(object, object_points));
    }
    for (const auto &object_info : object_pose_infos) {
      data_matcher_->addObjectData(msg->header.stamp, object_info);
      // RCLCPP_INFO(this->get_logger(),"Add succes");
      addError(
          Errorresults); // 接受到一次信息就计算一次信息的误差而非到最后计算
    }
    return true;
  };
  auto STAGE3Function = [&]() -> bool {
    for (size_t i = 0; i < msg->objects.size(); ++i) {
      const auto &object = msg->objects[i];
      if (referee_pkg::DetectModel[RaceStage::STAGE_2].find(
              object.target_type) ==
          referee_pkg::DetectModel[RaceStage::STAGE_2].end()) {
        return 0;
      }
      // 检查角点数量
      if (object.corners.size() != 4) {
        RCLCPP_WARN(this->get_logger(),
                    "Object %zu '%s' has %zu corners, expected 4", i,
                    object.target_type.c_str(), object.corners.size());
        continue;
      }
      // 获取该目标类型的3D坐标点
      std::vector<cv::Point3f> object_points;
      auto dims_it = referee_pkg::TARGET_DIMENSIONS.find(object.target_type);
      if (dims_it != referee_pkg::TARGET_DIMENSIONS.end()) {
        const auto &dims = dims_it->second;
        object_points = {
            cv::Point3f(-dims.width / 2, 0, -dims.height / 2), // 左下
            cv::Point3f(dims.width / 2, 0, -dims.height / 2),  // 右下
            cv::Point3f(dims.width / 2, 0, dims.height / 2),   // 右上
            cv::Point3f(-dims.width / 2, 0, dims.height / 2)   // 左上
        };
      } else {
        continue;
      }
      object_pose_infos.push_back(PnPSolve(object, object_points));
    }
    for (const auto &object_info : object_pose_infos) {
      data_matcher_->addObjectData(msg->header.stamp, object_info);
      // RCLCPP_INFO(this->get_logger(),"Add succes");
      addError(
          Errorresults); // 接受到一次信息就计算一次信息的误差而非到最后计算
    }
    return true;
  };
  bool ret = false;
  if (data_matcher_->model_data_map_.empty()) {
    return;
  }
  switch (stage) {
  case RaceStage::STAGE_1:
    // RCLCPP_INFO(this->get_logger(),"-----------------------");
    ret = STAGE1Function();
    break;
  case RaceStage::STAGE_2:
    ret = STAGE2Function();
    break;
  case RaceStage::STAGE_3:
    ret = STAGE3Function();
    break;
  case RaceStage::STAGE_4:
    ret = STAGE3Function();
    break;
  case RaceStage::STAGE_5:
    // ret = STAGE4Function();
    break;
  }
}

// 解密函数
std::vector<unsigned char>
Referee::decryptData(const std::vector<unsigned char> &ciphertext) {
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (!ctx) {
    throw std::runtime_error("Failed to create cipher context");
  }

  if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, encryption_key,
                              encryption_iv)) {
    EVP_CIPHER_CTX_free(ctx);
    throw std::runtime_error("Failed to initialize decryption");
  }

  std::vector<unsigned char> plaintext(ciphertext.size() + AES_BLOCK_SIZE);
  int len;
  int plaintext_len;

  if (1 != EVP_DecryptUpdate(ctx, plaintext.data(), &len, ciphertext.data(),
                             ciphertext.size())) {
    EVP_CIPHER_CTX_free(ctx);
    throw std::runtime_error("Decryption update failed");
  }
  plaintext_len = len;

  if (1 != EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len)) {
    EVP_CIPHER_CTX_free(ctx);
    throw std::runtime_error("Decryption finalization failed");
  }
  plaintext_len += len;

  plaintext.resize(plaintext_len);
  EVP_CIPHER_CTX_free(ctx);
  return plaintext;
}

pose_msg::msg::ModelPoseArray
Referee::deserializeModelStates(const std::vector<unsigned char> &data) {
  pose_msg::msg::ModelPoseArray msg;
  size_t offset = 0;

  // 反序列化时间戳
  int64_t sec, nanosec;
  memcpy(&sec, data.data() + offset, sizeof(sec));
  offset += sizeof(sec);
  memcpy(&nanosec, data.data() + offset, sizeof(nanosec));
  offset += sizeof(nanosec);

  msg.header.stamp.sec = sec;
  msg.header.stamp.nanosec = nanosec;

  // 反序列化帧ID
  size_t frame_id_length;
  memcpy(&frame_id_length, data.data() + offset, sizeof(frame_id_length));
  offset += sizeof(frame_id_length);
  msg.header.frame_id = std::string(data.begin() + offset,
                                    data.begin() + offset + frame_id_length);
  offset += frame_id_length;

  // 反序列化模型数量
  size_t model_count;
  memcpy(&model_count, data.data() + offset, sizeof(model_count));
  offset += sizeof(model_count);

  // 反序列化每个模型数据
  for (size_t i = 0; i < model_count; ++i) {
    pose_msg::msg::ModelPose model_pose;

    // 反序列化模型名称
    size_t name_length;
    memcpy(&name_length, data.data() + offset, sizeof(name_length));
    offset += sizeof(name_length);
    model_pose.name =
        std::string(data.begin() + offset, data.begin() + offset + name_length);
    offset += name_length;

    // 反序列化位置
    memcpy(&model_pose.pose.position.x, data.data() + offset, sizeof(double));
    offset += sizeof(double);
    memcpy(&model_pose.pose.position.y, data.data() + offset, sizeof(double));
    offset += sizeof(double);
    memcpy(&model_pose.pose.position.z, data.data() + offset, sizeof(double));
    offset += sizeof(double);

    // 反序列化姿态
    memcpy(&model_pose.pose.orientation.x, data.data() + offset,
           sizeof(double));
    offset += sizeof(double);
    memcpy(&model_pose.pose.orientation.y, data.data() + offset,
           sizeof(double));
    offset += sizeof(double);
    memcpy(&model_pose.pose.orientation.z, data.data() + offset,
           sizeof(double));
    offset += sizeof(double);
    memcpy(&model_pose.pose.orientation.w, data.data() + offset,
           sizeof(double));
    offset += sizeof(double);

    msg.models.push_back(model_pose);
  }

  return msg;
}

void Referee::callback_Status(
    const pose_msg::msg::ModelPoseArray::SharedPtr msg) {
  // // 输出接收到的消息的时间戳信息
  // RCLCPP_INFO(this->get_logger(), "Received message - stamp: sec=%d,
  // nanosec=%u, is_encrypted=%d, encrypted_data_size=%zu",
  //             msg->header.stamp.sec, msg->header.stamp.nanosec,
  //             msg->is_encrypted, msg->encrypted_data.size());
  auto Contructmodelstates =
      [&](const pose_msg::msg::ModelPoseArray::SharedPtr &msg,
          gazebo_msgs::msg::ModelStates &models,
          std_msgs::msg::Header &header) -> bool {
    if (msg->is_encrypted && !msg->encrypted_data.empty()) {
      try {
        // 解密数据
        std::vector<unsigned char> decrypted_data =
            decryptData(msg->encrypted_data);

        // 反序列化
        pose_msg::msg::ModelPoseArray decrypted_msg =
            deserializeModelStates(decrypted_data);

        // 处理解密后的消息
        gazebo_msgs::msg::ModelStates model_states;
        for (const auto &model : decrypted_msg.models) {
          model_states.name.push_back(model.name);
          model_states.pose.push_back(model.pose);
          RCLCPP_INFO(this->get_logger(), " - %s", model.name.c_str());
        }
        // RCLCPP_INFO(this->get_logger(), "Received message - stamp:
        // sec=%d",
        //     decrypted_msg.header.stamp.sec);
        models = model_states;
        header = decrypted_msg.header;
        // std::cout << rclcpp::Time(header.stamp).nanoseconds() << std::endl;
        return true;
      } catch (const std::exception &e) {
        RCLCPP_ERROR(this->get_logger(), "Decryption error: %s", e.what());
        return false;
      }
    } else {
      // 处理未加密的消息
      gazebo_msgs::msg::ModelStates model_states;
      for (const auto &model : msg->models) {
        if (referee_pkg::DetectModel[stage].find(model.name) !=
            referee_pkg::DetectModel[stage].end()) {
          model_states.name.push_back(model.name);
          model_states.pose.push_back(model.pose);
          RCLCPP_INFO(this->get_logger(), " - %s", model.name.c_str());
        }
      }
      models = model_states;
      header = msg->header;
      return true;
    }
  };
  gazebo_msgs::msg::ModelStates models;
  std_msgs::msg::Header header;
  if (Contructmodelstates(msg, models, header)) {
    data_matcher_->addModelData(header.stamp, models);
  }
  if (stage == RaceStage::STAGE_5) {
    for (size_t i = 0; i < models.name.size(); i++) {
      std::vector<geometry_msgs::msg::Point> model_points;
      auto dims_it = referee_pkg::TARGET_DIMENSIONS.find(models.name[i]);
      if (dims_it != referee_pkg::TARGET_DIMENSIONS.end()) {
        const auto &dims = dims_it->second;
        auto point = geometry_msgs::msg::Point();
        point.x = -dims.width / 2;
        point.y = 0;
        point.z = -dims.height / 2;
        model_points.push_back(point); // 左下
        point.x = dims.width / 2;
        point.y = 0;
        point.z = -dims.height / 2;
        model_points.push_back(point); // 右下
        point.x = dims.width / 2;
        point.y = 0;
        point.z = dims.height / 2;
        model_points.push_back(point); // 右上
        point.x = -dims.width / 2;
        point.y = 0;
        point.z = dims.height / 2;
        model_points.push_back(point); // 左上
        HitArrorSendRequest(model_points, header, referee_pkg::g);
      }
    }
  }
}
void Referee::HitArrorReponse_Callback(
    rclcpp::Client<referee_pkg::srv::HitArror>::SharedFuture result_future) {
  auto response = result_future.get();
  geometry_msgs::msg::Pose ModelCurrentPose =
      data_matcher_->model_data_map_.rbegin()->second.pose[0];
  cv::Mat r = (cv::Mat_<double>(3, 1) << response->yaw, response->pitch,
               response->roll);
  cv::Mat R;
  cv::Rodrigues(r, R);
  auto quaternionToRotationMatrix = [&](const cv::Mat &quaternion) -> cv::Mat {
    double w = quaternion.at<double>(0);
    double x = quaternion.at<double>(1);
    double y = quaternion.at<double>(2);
    double z = quaternion.at<double>(3);

    cv::Mat R = (cv::Mat_<double>(3, 3) << 1 - 2 * y * y - 2 * z * z,
                 2 * x * y - 2 * w * z, 2 * x * z + 2 * w * y,
                 2 * x * y + 2 * w * z, 1 - 2 * x * x - 2 * z * z,
                 2 * y * z - 2 * w * x, 2 * x * z - 2 * w * y,
                 2 * y * z + 2 * w * x, 1 - 2 * x * x - 2 * y * y);

    return R;
  };
  auto transformToArmorFrame =
      [&](const cv::Point3d &world_point, const cv::Mat &armor_position,
          const cv::Mat &armor_orientation) -> cv::Point3d {
    // 将四元数转换为旋转矩阵
    cv::Mat R_armor = quaternionToRotationMatrix(armor_orientation);

    // 世界坐标系到装甲板坐标系的变换
    cv::Mat point_world =
        (cv::Mat_<double>(3, 1) << world_point.x, world_point.y, world_point.z);
    cv::Mat armor_pos =
        (cv::Mat_<double>(3, 1) << armor_position.at<double>(0),
         armor_position.at<double>(1), armor_position.at<double>(2));

    // 变换到装甲板坐标系：R_armor^T * (point - armor_position)
    cv::Mat point_relative = point_world - armor_pos;
    cv::Mat point_armor = R_armor.t() * point_relative;

    return cv::Point3d(point_armor.at<double>(0), point_armor.at<double>(1),
                       point_armor.at<double>(2));
  };
  auto isPointInArmor = [&](const cv::Point3d &point_in_armor,
                            double &accuracy_distance) -> bool {
    // 在装甲板坐标系中，装甲板通常位于XY平面
    double half_width = 0.705 / 2.0;
    double half_height = 0.520 / 2.0;

    // 检查是否在装甲板矩形范围内
    bool in_width = std::abs(point_in_armor.x) <= half_width;
    bool in_height = std::abs(point_in_armor.y) <= half_height;
    bool in_depth = std::abs(point_in_armor.z) <= 0.1; // 假设装甲板有一定厚度

    // 计算与装甲板中心的偏差距离（在装甲板平面上的投影）
    accuracy_distance = sqrt(point_in_armor.x * point_in_armor.x +
                             point_in_armor.y * point_in_armor.y);

    return in_width && in_height && in_depth;
  };

  auto getAccuracyLevel = [&](double distance_to_center) -> int {
    double max_dimension = std::max(0.705, 0.520);

    if (distance_to_center < max_dimension * 0.1) {
      return 4;
    } else if (distance_to_center < max_dimension * 0.3) {
      return 3;
    } else if (distance_to_center < max_dimension * 0.5) {
      return 2;
    } else {
      return 1;
    }
  };
  auto rotationMatrixToQuaternion = [&](const cv::Mat &R) -> cv::Mat {
    double m00 = R.at<double>(0, 0), m01 = R.at<double>(0, 1),
           m02 = R.at<double>(0, 2);
    double m10 = R.at<double>(1, 0), m11 = R.at<double>(1, 1),
           m12 = R.at<double>(1, 2);
    double m20 = R.at<double>(2, 0), m21 = R.at<double>(2, 1),
           m22 = R.at<double>(2, 2);

    double tr = m00 + m11 + m22;
    double w, x, y, z;

    if (tr > 0) {
      double S = sqrt(tr + 1.0) * 2.0;
      w = 0.25 * S;
      x = (m21 - m12) / S;
      y = (m02 - m20) / S;
      z = (m10 - m01) / S;
    } else if ((m00 > m11) && (m00 > m22)) {
      double S = sqrt(1.0 + m00 - m11 - m22) * 2.0;
      w = (m21 - m12) / S;
      x = 0.25 * S;
      y = (m01 + m10) / S;
      z = (m02 + m20) / S;
    } else if (m11 > m22) {
      double S = sqrt(1.0 + m11 - m00 - m22) * 2.0;
      w = (m02 - m20) / S;
      x = (m01 + m10) / S;
      y = 0.25 * S;
      z = (m12 + m21) / S;
    } else {
      double S = sqrt(1.0 + m22 - m00 - m11) * 2.0;
      w = (m10 - m01) / S;
      x = (m02 + m20) / S;
      y = (m12 + m21) / S;
      z = 0.25 * S;
    }

    return (cv::Mat_<double>(4, 1) << w, x, y, z);
  };
  auto solveBallisticEquation = [&](double distance, double height_diff,
                                    double &pitch,
                                    cv::Point3d &hit_point) -> bool {
    // 初始猜测：直线弹道角度
    pitch = atan2(height_diff, distance);
    const int max_iterations = 20;
    const double tolerance = 0.001;

    for (int i = 0; i < max_iterations; ++i) {
      double cos_pitch = cos(pitch);
      double sin_pitch = sin(pitch);

      // 飞行时间
      double t = distance / (referee_pkg::v0 * cos_pitch);

      // 计算实际下落高度
      double actual_height =
          referee_pkg::v0 * sin_pitch * t - 0.5 * referee_pkg::g * t * t;

      // 高度误差
      double height_error = actual_height - height_diff;

      // 如果误差足够小，收敛
      if (std::abs(height_error) < tolerance) {
        // 计算命中点
        hit_point.x = distance * cos_pitch;
        hit_point.y = 0; // 假设水平面内运动
        hit_point.z = actual_height;
        return true;
      }

      // 计算导数（雅可比矩阵）
      double dtdp =
          (distance * sin_pitch) / (referee_pkg::v0 * cos_pitch * cos_pitch);
      double dhdp = referee_pkg::v0 * sin_pitch * dtdp +
                    referee_pkg::v0 * cos_pitch * t - referee_pkg::g * t * dtdp;

      // 牛顿迭代更新
      if (std::abs(dhdp) > 1e-10) {
        pitch -= height_error / dhdp;
      } else {
        break; // 避免除零
      }
    }

    return false; // 未收敛
  };
  auto checkHit =
      [&](const cv::Mat &armor_position, const cv::Mat &armor_orientation,
          const cv::Mat &gun_position, const cv::Mat &gun_orientation,
          double &accuracy_distance) -> bool {
    // 1. 计算重力弹道下的命中点
    double required_pitch;
    cv::Point3d predicted_hit_point;

    // if (!calculateGravityTrajectory(armor_position, gun_position,
    //                                 required_pitch, predicted_hit_point)) {
    //   return false; // 弹道解算失败
    // }

    // 2. 将预测命中点转换到装甲板坐标系
    cv::Point3d hit_in_armor_frame = transformToArmorFrame(
        predicted_hit_point, armor_position, armor_orientation);

    // 3. 检查命中点是否在装甲板范围内
    bool is_hit = isPointInArmor(hit_in_armor_frame, accuracy_distance);

    return is_hit;
  };

  std::thread AddError_t(
      [&](unordered_map<std::string, vector<referee_pkg::ComparisonResult>>
              &Errorresults) {
        unique_lock<mutex> lock(AddError_mutex);
        AddError_cv.wait(lock, [this]() {
          return !data_matcher_->object_data_map_.empty() &&
                 !data_matcher_->model_data_map_
                      .empty(); // 这里返回为为真则往下执行
        });
        referee_pkg::ComparisonResult ArrorError;
        cv::Mat ArrorPosition =
            (cv::Mat_<double>(3, 1) << ModelCurrentPose.position.x,
             ModelCurrentPose.position.y, ModelCurrentPose.position.z);
        cv::Mat ArrorOrientation =
            (cv::Mat_<double>(4, 1) << ModelCurrentPose.orientation.w,
             ModelCurrentPose.orientation.x, ModelCurrentPose.orientation.y,
             ModelCurrentPose.orientation.z);
        cv::Mat CameraPosition = (cv::Mat_<double>(3, 1) << 0.0, 0.0, 0.0);
        cv::Mat CameraOrientation = rotationMatrixToQuaternion(R);
        double AccuraryDistance = 0.0;
        ArrorError.found_in_gazebo =
            checkHit(ArrorPosition, ArrorOrientation, CameraPosition,
                     CameraOrientation, AccuraryDistance);
        if (ArrorError.found_in_gazebo) {
          ArrorError.HitArrorPrecision = getAccuracyLevel(AccuraryDistance);
        }
        Errorresults
            [referee_pkg::DetectModel[RaceStage::STAGE_5].cbegin()->data()]
                .emplace_back(ArrorError);
      },
      std::ref(Errorresults)); // ref 构造能输入线程的引用量
  AddError_t.join();
}
void Referee::processModelStates(const pose_msg::msg::ModelPoseArray &msg) {

  gazebo_msgs::msg::ModelStates model_states;
  for (const auto &model : msg.models) {
    model_states.name.push_back(model.name);
    model_states.pose.push_back(model.pose);
    // RCLCPP_INFO(this->get_logger(), " - %s", model.name.c_str());
  }

  data_matcher_->addModelData(msg.header.stamp, model_states);
}

void Referee::addError(
    unordered_map<std::string, vector<referee_pkg::ComparisonResult>>
        &Errorresults) {
  // 多线程 加快运算速度
  std::thread AddError_t(
      [this](unordered_map<std::string, vector<referee_pkg::ComparisonResult>>
                 &Errorresults) {
        auto STAGE1Function = [&]() {
          unique_lock<mutex> lock(AddError_mutex);
          AddError_cv.wait(lock, [this]() {
            return !data_matcher_->object_dataarray_map_
                        .empty(); // 这里返回为为真则往下执行
          });
          if (data_matcher_->model_data_map_.empty()) {
            return;
          }
          gazebo_msgs::msg::ModelStates model_states;
          referee_pkg::ObjectPoseInfo object1_info;
          referee_pkg::ObjectPoseInfo object2_info;
          std::vector<referee_pkg::ObjectPoseInfo> object_info;

          if (data_matcher_->findMatchingData(object_info, model_states) &&
              object_info.size() == 2) {
            object1_info = object_info[0];
            object2_info = object_info[1];

            for (int i = 0; i < model_states.name.size(); i++) {

              if (model_states.name[i] == object1_info.target_type) {
                object1_info.position_error = calculatePositionError(
                    model_states.pose[i].position, object1_info.pose.position);

              } else
                continue;

              if (model_states.name[i] == object2_info.target_type) {
                object2_info.position_error = calculatePositionError(
                    model_states.pose[i].position, object2_info.pose.position);
              } else
                continue;
              object1_info.orientation_error = calculateOrientationError(
                  object2_info.pose.orientation, object1_info.pose.orientation);
              referee_pkg::ComparisonResult result(
                  object1_info.target_type, object1_info.model_name,
                  object1_info.pose, model_states.pose[i],
                  std::min(object1_info.position_error,
                           object2_info.position_error),
                  std::min(object1_info.orientation_error,
                           object2_info.orientation_error),
                  true);
              result.RingCirclePositionError = calculateRingError(
                  object1_info.pose.position, object2_info.pose.position);
              Errorresults[object1_info.target_type].push_back(result);

              log_ << result; // 日志输出
              log_ << referee_pkg::ComparisonResult(
                  object1_info.target_type, object1_info.model_name,
                  object2_info.pose, model_states.pose[i],
                  std::min(object1_info.position_error,
                           object2_info.position_error),
                  object1_info.orientation_error, true);

              break;
            }

          } else {
            RCLCPP_INFO(this->get_logger(), "圆环的两个圆的时间戳不匹配");
            return;
          }
        };
        auto STAGE2Function = [&]() {
          unique_lock<mutex> lock(AddError_mutex);
          AddError_cv.wait(lock, [this]() {
            return !data_matcher_->object_data_map_
                        .empty(); // 这里返回为为真则往下执行
          });
          if (data_matcher_->model_data_map_.empty()) {
            return;
          }
          gazebo_msgs::msg::ModelStates model_states;
          referee_pkg::ObjectPoseInfo object_info;
          data_matcher_->findMatchingData(
              object_info, model_states); // 在这里 object_info
                                          // model_states被赋予时间戳匹配的值
          for (int i = 0; i < model_states.name.size(); i++) {
            if (model_states.name[i] == object_info.target_type) {
              object_info.position_error = calculatePositionError(
                  model_states.pose[i].position, object_info.pose.position);
              tf2::Quaternion q1(model_states.pose[i].orientation.w,
                                 model_states.pose[i].orientation.x,
                                 model_states.pose[i].orientation.y,
                                 model_states.pose[i].orientation.z),
                  q2(object_info.pose.orientation.w,
                     object_info.pose.orientation.x,
                     object_info.pose.orientation.y,
                     object_info.pose.orientation.z);
              q1.normalize();
              q2.normalize();
              q1 = q2 * q1;
              q1.normalize();
              q2 = tf2::Quaternion(1, 0, 0, 0);
              object_info.orientation_error = calculateOrientationError(q1, q2);
            } else
              continue;
            referee_pkg::ComparisonResult result(
                object_info.target_type, object_info.model_name,
                object_info.pose, model_states.pose[i],
                object_info.position_error, object_info.orientation_error,
                true);
            Errorresults[object_info.target_type].push_back(result);
            log_ << result; // 日志输出
            break;
          }
          return;
        };
        auto STAGE3Function = [&]() {
          unique_lock<mutex> lock(AddError_mutex);
          AddError_cv.wait(lock, [this]() {
            return !data_matcher_->object_data_map_
                        .empty(); // 这里返回为为真则往下执行
          });
          if (data_matcher_->model_data_map_.empty()) {
            return;
          }
          gazebo_msgs::msg::ModelStates model_states;
          referee_pkg::ObjectPoseInfo object_info;
          data_matcher_->findMatchingData(
              object_info, model_states); // 在这里 object_info
                                          // model_states被赋予时间戳匹配的值
          for (int i = 0; i < model_states.name.size(); i++) {
            if (model_states.name[i] == object_info.target_type) {
              object_info.position_error = calculatePositionError(
                  model_states.pose[i].position, object_info.pose.position);
              object_info.orientation_error =
                  calculateOrientationError(model_states.pose[i].orientation,
                                            object_info.pose.orientation);
            } else
              continue;
            referee_pkg::ComparisonResult result(
                object_info.target_type, object_info.model_name,
                object_info.pose, model_states.pose[i],
                object_info.position_error, object_info.orientation_error,
                true);
            Errorresults[object_info.target_type].push_back(result);
            log_ << result; // 日志输出
            break;
          }
          return;
        };
        switch (stage) {
        case RaceStage::STAGE_1:
          STAGE1Function();
          break;
        case RaceStage::STAGE_2:
          STAGE2Function();
          break;
        case RaceStage::STAGE_3:
          STAGE3Function();
          break;
        case RaceStage::STAGE_4:
          STAGE3Function();
          break;
        case RaceStage::STAGE_5:
          break;
        }
      },
      std::ref(Errorresults)); // ref 构造能输入线程的引用量
  AddError_t.join();
}

void Referee::CulculateScores(
    unordered_map<std::string, vector<referee_pkg::ComparisonResult>>
        &Errorresults,
    unordered_map<std::string, referee_pkg::ErrorStatistics> &results,
    double scores) {
  auto STAGE1Function = [&]() {
    for (auto Errorresult_ : Errorresults) {
      vector<referee_pkg::ComparisonResult> Errorresult = Errorresult_.second;
      std::string target_type = Errorresult_.first;
      if (referee_pkg::DetectModel[RaceStage::STAGE_1].find(target_type) ==
          referee_pkg::DetectModel[RaceStage::STAGE_1].end())
        continue;
      if (!Errorresult.empty()) // 理论上不会空 如果正常执行的话  防呆
      {
        RCLCPP_WARN(this->get_logger(), "CulculateScores");
        double total_position = 0.0, total_orientation = 0.0,
               total_ringerror = 0.0;
        int n = Errorresult.size(); // 用于计算后续的平均值
        for (auto i : Errorresult) {
          if (i.found_in_gazebo &&
              results.find(i.target_type) != results.end()) {
            total_position += i.position_error;
            total_orientation += i.orientation_error;
            total_ringerror += i.RingCirclePositionError;
            results[target_type].valid_comparisons++;
          } else {
            continue;
          }
        }
        results[target_type].average_position_error = total_position / n;
        results[target_type].average_orientation_error = total_orientation / n;
        results[target_type].average_ringcenter_error = total_ringerror / n;

        sort(Errorresult.begin(), Errorresult.end(),
             [](referee_pkg::ComparisonResult &a,
                referee_pkg::ComparisonResult &b) {
               return a.position_error > b.position_error;
             }); // 基于位置误差从大到小排列

        results[target_type].max_position_error =
            Errorresult.front().position_error; // 最大值

        sort(Errorresult.begin(), Errorresult.end(),
             [](referee_pkg::ComparisonResult &a,
                referee_pkg::ComparisonResult &b) {
               return a.orientation_error > b.orientation_error;
             }); // 基于位置误差从大到小排列

        results[target_type].max_orientation_error =
            Errorresult.front().orientation_error; // 最大值

        referee_pkg::RingPositionError =
            results[target_type].average_position_error;
        referee_pkg::RingCenterError =
            results[target_type].average_ringcenter_error;
        referee_pkg::RingUnitTimeDetectCount = n / (ContinueTime * StageCount);
        Json.JsonGenerate(
            scores, TEAMNAME, target_type, stage,
            referee_pkg::RingUnitTimeDetectCount,
            referee_pkg::RingPositionError,
            results[target_type].average_orientation_error,
            referee_pkg::RingCenterError,
            results[target_type].max_position_error,
            results[target_type].max_orientation_error); // 构造json 以及 sha256

      } else {
        Json.JsonGenerate(
            scores, TEAMNAME, target_type, stage,
            referee_pkg::RingUnitTimeDetectCount,
            referee_pkg::RingPositionError,
            results[target_type].average_orientation_error,
            referee_pkg::RingCenterError,
            results[target_type].max_position_error,
            results[target_type].max_orientation_error); // 构造json 以及 sha256
      }
    }
    data_matcher_->clear();
  };
  auto STAGE2Function = [&]() {
    for (auto Errorresult_ : Errorresults) {
      vector<referee_pkg::ComparisonResult> Errorresult = Errorresult_.second;
      std::string target_type = Errorresult_.first;
      if (referee_pkg::DetectModel[RaceStage::STAGE_2].find(target_type) ==
          referee_pkg::DetectModel[RaceStage::STAGE_2].end())
        continue;
      if (!Errorresult.empty()) // 理论上不会空 如果正常执行的话  防呆
      {
        RCLCPP_INFO(this->get_logger(), "CulculateScores");
        double total_position, total_orientation;
        int n = Errorresult.size(); // 用于计算后续的平均值
        for (auto i : Errorresult) {
          if (i.found_in_gazebo &&
              results.find(i.target_type) != results.end()) {
            total_position += i.position_error;
            total_orientation += i.orientation_error;
            results[target_type].valid_comparisons++;
          } else {
            continue;
          }
        }
        results[target_type].average_position_error = total_position / n;
        results[target_type].average_orientation_error = total_orientation / n;

        sort(Errorresult.begin(), Errorresult.end(),
             [](referee_pkg::ComparisonResult &a,
                referee_pkg::ComparisonResult &b) {
               return a.position_error > b.position_error;
             }); // 基于位置误差从大到小排列

        results[target_type].max_position_error =
            Errorresult.front().position_error; // 最大值

        sort(Errorresult.begin(), Errorresult.end(),
             [](referee_pkg::ComparisonResult &a,
                referee_pkg::ComparisonResult &b) {
               return a.orientation_error > b.orientation_error;
             }); // 基于位置误差从大到小排列

        results[target_type].max_orientation_error =
            Errorresult.front().orientation_error; // 最大值

        referee_pkg::ArrowPositionRrror =
            results[target_type].average_position_error;
        referee_pkg::ArrowDirectRrror =
            results[target_type].average_orientation_error;
        referee_pkg::ArrowUnitTimeDetectCount = n / (ContinueTime * StageCount);

        Json.JsonGenerate(
            scores, TEAMNAME, target_type, stage,
            results[target_type].valid_comparisons,
            results[target_type].average_position_error,
            results[target_type].average_orientation_error,
            results[target_type].max_position_error,
            results[target_type].max_orientation_error); // 构造json 以及 sha256

      } else {
        Json.JsonGenerate(
            scores, TEAMNAME, target_type, stage,
            results[target_type].valid_comparisons,
            results[target_type].average_position_error,
            results[target_type].average_orientation_error,
            results[target_type].max_position_error,
            results[target_type].max_orientation_error); // 构造json 以及 sha256
      }
    }
    data_matcher_->clear();
  };
  auto STAGE3Function = [&]() {
    for (auto Errorresult_ : Errorresults) {
      vector<referee_pkg::ComparisonResult> Errorresult = Errorresult_.second;
      std::string target_type = Errorresult_.first;
      if (!Errorresult.empty()) // 理论上不会空 如果正常执行的话  防呆
      {
        RCLCPP_INFO(this->get_logger(), "CulculateScores");
        double total_position, total_orientation;
        int n = Errorresult.size(); // 用于计算后续的平均值
        for (auto i : Errorresult) {
          if (i.found_in_gazebo &&
              results.find(i.target_type) != results.end()) {
            total_position += i.position_error;
            total_orientation += i.orientation_error;
            results[target_type].valid_comparisons++;
          } else {
            continue;
          }
        }
        results[target_type].average_position_error = total_position / n;
        results[target_type].average_orientation_error = total_orientation / n;

        sort(Errorresult.begin(), Errorresult.end(),
             [](referee_pkg::ComparisonResult &a,
                referee_pkg::ComparisonResult &b) {
               return a.position_error > b.position_error;
             }); // 基于位置误差从大到小排列

        results[target_type].max_position_error =
            Errorresult.front().position_error; // 最大值

        sort(Errorresult.begin(), Errorresult.end(),
             [](referee_pkg::ComparisonResult &a,
                referee_pkg::ComparisonResult &b) {
               return a.orientation_error > b.orientation_error;
             }); // 基于位置误差从大到小排列

        results[target_type].max_orientation_error =
            Errorresult.front().orientation_error; // 最大值

        referee_pkg::ArrorPositionError =
            results[target_type].average_position_error;
        referee_pkg::ArrorUnitTimeDetectCount = n / (ContinueTime * StageCount);

        Json.JsonGenerate(
            scores, TEAMNAME, target_type, stage,
            results[target_type].valid_comparisons,
            results[target_type].average_position_error,
            results[target_type].average_orientation_error,
            results[target_type].max_position_error,
            results[target_type].max_orientation_error); // 构造json 以及 sha256

      } else {
        Json.JsonGenerate(
            scores, TEAMNAME, target_type, stage,
            results[target_type].valid_comparisons,
            results[target_type].average_position_error,
            results[target_type].average_orientation_error,
            results[target_type].max_position_error,
            results[target_type].max_orientation_error); // 构造json 以及 sha256
      }
    }
    data_matcher_->clear();
  };
  auto STAGE4Function = [&]() {
    for (auto Errorresult_ : Errorresults) {
      vector<referee_pkg::ComparisonResult> Errorresult = Errorresult_.second;
      std::string target_type = Errorresult_.first;
      if (!Errorresult.empty()) // 理论上不会空 如果正常执行的话  防呆
      {
        RCLCPP_INFO(this->get_logger(), "CulculateScores");
        double total_position, total_orientation;
        int n = Errorresult.size(); // 用于计算后续的平均值
        for (auto i : Errorresult) {
          if (i.found_in_gazebo &&
              results.find(i.target_type) != results.end()) {
            total_position += i.position_error;
            total_orientation += i.orientation_error;
            results[target_type].valid_comparisons++;
          } else {
            continue;
          }
        }
        results[target_type].average_position_error = total_position / n;
        results[target_type].average_orientation_error = total_orientation / n;

        sort(Errorresult.begin(), Errorresult.end(),
             [](referee_pkg::ComparisonResult &a,
                referee_pkg::ComparisonResult &b) {
               return a.position_error > b.position_error;
             }); // 基于位置误差从大到小排列

        results[target_type].max_position_error =
            Errorresult.front().position_error; // 最大值

        sort(Errorresult.begin(), Errorresult.end(),
             [](referee_pkg::ComparisonResult &a,
                referee_pkg::ComparisonResult &b) {
               return a.orientation_error > b.orientation_error;
             }); // 基于位置误差从大到小排列

        results[target_type].max_orientation_error =
            Errorresult.front().orientation_error; // 最大值

        referee_pkg::ArrorPositionError_ =
            results[target_type].average_position_error;
        referee_pkg::ArrorUnitTimeDetectCount_ =
            n / (ContinueTime * StageCount);

        Json.JsonGenerate(
            scores, TEAMNAME, target_type, stage,
            results[target_type].valid_comparisons,
            results[target_type].average_position_error,
            results[target_type].average_orientation_error,
            results[target_type].max_position_error,
            results[target_type].max_orientation_error); // 构造json 以及 sha256

      } else {
        Json.JsonGenerate(
            scores, TEAMNAME, target_type, stage,
            results[target_type].valid_comparisons,
            results[target_type].average_position_error,
            results[target_type].average_orientation_error,
            results[target_type].max_position_error,
            results[target_type].max_orientation_error); // 构造json 以及 sha256
      }
    }
    data_matcher_->clear();
  };
  auto STAGE5Function = [&]() {
    for (auto Errorresult_ : Errorresults) {
      vector<referee_pkg::ComparisonResult> Errorresult = Errorresult_.second;
      std::string target_type = Errorresult_.first;
      if (!Errorresult.empty()) // 理论上不会空 如果正常执行的话  防呆
      {
        RCLCPP_INFO(this->get_logger(), "CulculateScores");
        int n = Errorresult.size(); // 用于计算后续的平均值
        int total_HitAccuracyLevel = 0;
        for (auto i : Errorresult) {
          if (i.found_in_gazebo &&
              results.find(i.target_type) != results.end()) {
            results[target_type].valid_comparisons++;
            total_HitAccuracyLevel += i.HitArrorPrecision;
          } else {
            continue;
          }
        }

        referee_pkg::HitArrorSuccessCount =
            results[target_type].valid_comparisons / n;
        referee_pkg::HitArrorPositionError = 1.0 * total_HitAccuracyLevel / n;

        Json.JsonGenerate(
            scores, TEAMNAME, stage, referee_pkg::HitArrorSuccessCount,
            referee_pkg::HitArrorPositionError); // 构造json 以及 sha256

      } else {
        Json.JsonGenerate(
            scores, TEAMNAME, stage, referee_pkg::HitArrorSuccessCount,
            referee_pkg::HitArrorPositionError); // 构造json 以及 sha256
      }
    }
    data_matcher_->clear();
  };
  switch (stage) {
  case RaceStage::STAGE_1:
    STAGE1Function();
    break;
  case RaceStage::STAGE_2:
    STAGE2Function();
    break;
  case RaceStage::STAGE_3:
    STAGE3Function();
    break;
  case RaceStage::STAGE_4:
    STAGE4Function();
    break;
  case RaceStage::STAGE_5:
    STAGE5Function();
    break;
  }
}

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<Referee>("referee_node");

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}