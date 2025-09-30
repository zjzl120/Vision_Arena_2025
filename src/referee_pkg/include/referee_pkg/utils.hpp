#ifndef __UTILS_HPP__
#define __UTILS_HPP__
#include "gazebo_msgs/msg/model_states.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "rclcpp/rclcpp.hpp"
#include "referee_pkg/msg/multi_object.hpp"
#include "referee_pkg/msg/object.hpp"
#include <builtin_interfaces/msg/time.hpp>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <functional>
#include <geometry_msgs/msg/pose.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/opencv.hpp>
#include <openssl/sha.h>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <tf2/LinearMath/Quaternion.h> // 添加 tf2 四元数支持
using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;
namespace builtin_interfaces {
namespace msg {
/**
 * @brief 用以使得以该类型为键的map能够正常编译
 * @note 裁判系统第五阶段的计算中有使用
 */
inline bool operator<(const Time &lhs, const Time &rhs) {
  if (lhs.sec != rhs.sec) {
    return lhs.sec < rhs.sec;
  }
  return lhs.nanosec < rhs.nanosec;
}

} // namespace msg
} // namespace builtin_interfaces
/**
 * @brief 加密密钥
 * @note 需要与gazebo一致
 */
const unsigned char encryption_key[32] = "Vision-Arena-2025-referee_Code1";
/**
 * @brief IV
 * @note 需要与gazebo一致
 */
const unsigned char encryption_iv[16] = "initial_vector1";
/**
 * @brief 比赛阶段枚举
 */
enum RaceStage {
  STAGE_1 = 1,
  STAGE_2 = 2,
  STAGE_3 = 3,
  STAGE_4 = 4,
  STAGE_5 = 5
};
/**
 * @brief 愚蠢的逻辑
 */
inline std::string operator+(std::string a, RaceStage stage) {
  int b = stage;
  return a + to_string(b);
}
/**
 * @brief 为了方便所以写了前置++重载
 */
inline RaceStage operator++(RaceStage &a) {
  a = RaceStage(int(a) + 1 % 6);
  return a;
}
/**
 * @brief 用于生成json 以及 sha256
 */
class JsonGenerator {
public:
  JsonGenerator() {
    for (const auto &entry : fs::directory_iterator("results/")) {
      if (entry.is_regular_file()) {
        fs::remove(entry.path());
      }
    }
  }
  /**
   * @brief STAGE_2 json 生成
   * @param score 分数 (暂不使用)
   * @param team_name 队伍名称用于生成对应名称的文件
   * @param target_type 识别模型类型
   * @param stage 当前比赛阶段
   * @param targets_found 识别次数
   * @param average_positionerror 平均位置误差
   * @param average_orientationerror 方向 仅在识别类型是箭头时被考虑入分数
   * @param average_ringcenter_error 圆环内外圆圆心误差
   * @param max_positionerror 最大位置误差 提供用以供选手参考
   * @param max_orientationerror 最大方向误差 同上
   */
  void JsonGenerate(double score, string team_name, string target_type,
                    RaceStage stage, int targets_found,
                    double average_positionerror,
                    double average_orientationerror,
                    double average_ringcenter_error, double max_positionerror,
                    double max_orientationerror);
  /**
   * @brief STAGE_1 STAGE_3 STAGE_4 json 生成
   * @param score 分数 (暂不使用)
   * @param team_name 队伍名称用于生成对应名称的文件
   * @param target_type 识别模型类型
   * @param stage 当前比赛阶段
   * @param targets_found 识别次数
   * @param average_positionerror 平均位置误差
   * @param average_orientationerror 方向 仅在识别类型是箭头时被考虑入分数
   * @param max_positionerror 最大位置误差 提供用以供选手参考
   * @param max_orientationerror 最大方向误差 同上
   */
  void JsonGenerate(double score, string team_name, string target_type,
                    RaceStage stage, int targets_found,
                    double average_positionerror,
                    double average_orientationerror, double max_positionerror,
                    double max_orientationerror);
  /**
   * @brief STAGE_5 json 生成
   * @param score 分数 (暂不使用)
   * @param team_name 队伍名称用于生成对应名称的文件
   * @param stage 当前比赛阶段
   * @param hitarror_successcount 平均击打装甲板成功计数
   * @param average_precisonlevel 平均击打精度

   */
  void JsonGenerate(double score, string team_name, RaceStage stage,
                    int hitarror_successcount, double average_precisonlevel);

private:
  /**
   * @brief 用于计算运行id
   */
  std::string generate_run_id();
  /**
   * @brief 保留三位小数 否则 json 倾向于高精度保存
   */
  inline double roundToThreeDecimals(double value) {
    return std::round(value * 1000.0) / 1000.0;
  }
  /**
   * @brief 用于计算对应的时间戳
   */
  std::string generate_timestamp();
  /**
   * @brief 计算并输出 sha256 文件
   * @param filename json路径
   */
  void culculateSHA256(string filename);
  /**
   * @brief json
   */
  json j;
  json j_;
};
/**
 * @brief 用于AddError
 * @param actual 模型位置
 * @param desired 选手端信息计算出的位置
 */
double calculatePositionError(const geometry_msgs::msg::Point &actual,
                              const geometry_msgs::msg::Point &desired);
/**
 * @brief 用于AddError
 * @param actual 大圆
 * @param desired 小圆
 */
double calculateRingError(const geometry_msgs::msg::Point &actual,
                          const geometry_msgs::msg::Point &desired);
/**
 * @brief 用于AddError
 * @param actual 模型方向角
 * @param desired 选手端信息计算出的方向角
 *
 */
double calculateOrientationError(const geometry_msgs::msg::Quaternion &actual,
                                 const geometry_msgs::msg::Quaternion &desired);
double calculateOrientationError(const tf2::Quaternion &actual,
                                 const tf2::Quaternion &desired);
namespace referee_pkg {

/// @brief 圆环准确度权重
static const double RINGPOSITIONWEIGHT = 0.03;
/// @brief 圆环中心匹配度权重
static const double RINGCENTERWEIGHT = 0.07;
/// @brief 圆环识别次数权重
static const double RINGUNITTIMEDETECTCOUNTWEIGHT = 0.1;
/// @brief 箭头准确度权重
static const double ARROWPOSITIONWEIGHT = 0.03;
/// @brief 箭头方向权重
static const double ARROWDIRECTWEIGHT = 0.07;
/// @brief 箭头识别次数权重
static const double ARROWUNITTIMEDETECTCOUNTWEIGHT = 0.1;
/// @brief 装甲板数字准确度权重
static const double ARRORPOSITIONWEIGHT = 0.1;
/// @brief 装甲板识别次数权重
static const double ARRORUNITTIMEDETECTCOUNTWEIGHT = 0.05;
/// @brief pnp准确度权重
static const double HITARRORPNPWEIGHT = 0.05;
/// @brief 击打装甲板命中权重
static const double HITARRORSUCCESSWEIGHT = 0.05;
/// @brief 击打装甲板精度权重
static const double HITARRORPOSITIONWEIGHT = 0.05;
/// @brief 圆环准确度误差
static double RingPositionError = 999.0;
/// @brief 圆环中心匹配误差
static double RingCenterError = 999.0;
/// @brief 圆环单位时间识别次数
static int RingUnitTimeDetectCount = 0.0;
/// @brief 箭头准确度误差
static double ArrowPositionRrror = 999.0;
/// @brief 箭头方向误差
static double ArrowDirectRrror = 3.14;
/// @brief 箭头单位时间识别次数
static int ArrowUnitTimeDetectCount = 0.0;
/// @brief 装甲板数字误差
static double ArrorPositionError = 999.0;
/// @brief 装甲板单位时间识别次数
static int ArrorUnitTimeDetectCount = 0.0;
/// @brief 装甲板数字误差带干扰
static double ArrorPositionError_ = 999.0;
/// @brief 装甲板单位时间识别次数带干扰
static int ArrorUnitTimeDetectCount_ = 0.0;
/// @brief 装甲板pnp误差
static double HitArrorPnPError = 999.0;
/// @brief 击打装甲板命中计数
static int HitArrorSuccessCount = 0.0;
/// @brief 命中误差
static double HitArrorPositionError = 999.0;
/// @brief 圆环内外圆比率
static const double RINGRATIO = 1.5625;
/// @brief 每阶段比赛次数
static const int RACECOUNT = 10;
/// @brief 重力加速度
static const double g = 9.80;
/// @brief 弹丸初始速度
static const double v0 = 1.0;
/**
 * @brief 选手端发布的不同模型的 尺寸信息的存储结构体
 * @param width 宽度
 * @param height 高度
 * @note 不必深究参数名称
 */
struct TargetDimensions {
  double width;
  double height;
};

/**
 * @brief 目标类型尺寸映射
 * @note 第一个参数是模型的名字 第二个参数是  这个 @param TargetDimensions
 * 的数据 即尺寸信息
 */
static std::map<std::string, TargetDimensions> TARGET_DIMENSIONS = {
    {"armor_1", {0.1, 0.1}},         // 装甲
    {"circle_red", {0.15, 0.15}},    // 红色圆形
    {"cube", {0.3, 0.3}},            // 立方体
    {"sphere_sin", {1.0, 1.0}},      // 球
    {"armor_red_1", {0.705, 0.520}}, // 待定，粗略计算
    {"armor_red_2", {0.705, 0.520}}, // 待定
    {"armor_red_3", {0.705, 0.520}}, // 待定
    {"armor_red_4", {0.705, 0.520}}, // 待定
    {"armor_red_5", {0.705, 0.520}}, // 待定
    {"rect", {0.5, 0.1}},
    {"rect_move", {0.5, 0.1}},
    {"Ring_red", {0.8, 0.8}},
    {"default", {0.1, 0.1}} // 默认尺寸 必须在最后一个
};
/**
 * @brief 没阶段裁判系统接收的模型名称
 * @note 可添加 直接在接收端过滤
 */
static map<RaceStage, set<std::string>> DetectModel = {
    {RaceStage::STAGE_1, {"Ring_red"}},
    {RaceStage::STAGE_2, {"Arror_red"}},
    {RaceStage::STAGE_3,
     {"armor_red_1", "armor_red_2", "armor_red_3", "armor_red_4"}},
    {RaceStage::STAGE_4,
     {"armor_red_1", "armor_red_2", "armor_red_3", "armor_red_4"}},
    {RaceStage::STAGE_5, {"armor_red_1"}}};
/**
 * @brief 根据目标类型获取3D世界坐标点
 * @param target_type 模型名称
 * @return 返回模型的四个角点 后续用这四个角点去解pnp
 * @note 发布顺序为 以左下为起始的逆时针
 */
static std::vector<cv::Point3f>
get_object_points(const std::string target_type) {
  TargetDimensions dims;

  auto it = TARGET_DIMENSIONS.find(
      target_type); // 从映射中寻找 名称匹配的键 返回的是个指针
  if (it != TARGET_DIMENSIONS.end()) {
    dims = it->second; // 取得 对应的尺寸信息 类型为 TargetDimensions
  }

  std::vector<cv::Point3f> object_points;
  object_points.push_back(
      cv::Point3f(-dims.width / 2, -dims.height / 2, 0)); // 左下
  object_points.push_back(
      cv::Point3f(dims.width / 2, -dims.height / 2, 0)); // 右下
  object_points.push_back(
      cv::Point3f(dims.width / 2, dims.height / 2, 0)); // 右上
  object_points.push_back(
      cv::Point3f(-dims.width / 2, dims.height / 2, 0)); // 左上
  return object_points;
}

/**
 * @brief 相机内参矩阵 可从/camera/camera_info 中获得
 */
const cv::Mat CAMERA_MATRIX = (cv::Mat_<double>(3, 3) << 476.0, 0.0, 400.0, 0.0,
                               476.0, 400.0, 0.0, 0.0, 1.0);

/**
 * @brief 全局畸变系数常量 可从/camera/camera_info 中获得 目前无畸变
 */
const cv::Mat DIST_COEFFS = (cv::Mat_<double>(5, 1) << 0.0, 0.0, 0.0, 0.0, 0.0);

/**
 * @brief 物体位姿信息结构体
 * @param target_type 名称
 * @param rvec 旋转向量
 * @param tvec 平移向量
 * @param pose 从pnp得到的旋转矩阵计算出的位姿
 * @param distance @param tvec 的 norm
 * @param model_name 对应的模型名称(bushi) 实际就是 @param target_type + _model
 * @param position_error 位置误差 在 AddError 后才会有值 暂时无用处
 * @param orientation_error 位置误差 在 AddError 后才会有值 暂时无用处
 *
 */
struct ObjectPoseInfo {
  std::string target_type;
  cv::Mat rvec;
  cv::Mat tvec;
  geometry_msgs::msg::Pose pose;
  double distance;
  std::string model_name;
  double position_error;
  double orientation_error;

  ObjectPoseInfo()
      : distance(0.0), position_error(0.0), orientation_error(0.0) {}
};

/**
 * @brief 错误统计结构体
 * @param average_position_error 平均位置误差
 * @param average_orientation_error 平均方向误差
 * @param max_position_error 最大位置误差
 * @param max_orientation_error 最大方向误差
 * @param valid_comparisons 有效比较 的数量
 * @note 在 CulculateScores 中 被放入值 作为最后json构建的参考数据
 */
struct ErrorStatistics {
  double average_position_error;
  double average_orientation_error;
  union {
    double average_ringcenter_error;
    struct {
      double average_hitaccuracy_level;
      double HitPrecison;
    };
  };
  double max_position_error;
  double max_orientation_error;
  int valid_comparisons;
  std::string target_type;

  ErrorStatistics(std::string target_type)
      : average_position_error(999.0), average_orientation_error(3.14),
        max_position_error(999.0), max_orientation_error(3.14),
        valid_comparisons(0), target_type(target_type) {}
  ErrorStatistics()
      : average_position_error(999.0), average_orientation_error(3.14),
        max_position_error(999.0), max_orientation_error(3.14),
        valid_comparisons(0) {}
};

/**
 * @brief 比较结果结构体
 * @param target_type 名称
 * @param model_name 模型名称
 * @param pnp_pose 计算出的pose
 * @param gazebo_pose 真是的pose
 * @param position_error 位置误差 0~
 * @param orientation_error 方向误差 0~pi
 * @param found_in_gazebo 实际全是 1 即 为有效比较才放进来 ,补:
 * 后续作为装甲板是否击中的标志位
 * @note 在AddError 后被添加值 其误差大小与对应的 ObjectPoseInfo 相同
 */
struct ComparisonResult {
  std::string target_type;
  std::string model_name;
  geometry_msgs::msg::Pose pnp_pose;
  geometry_msgs::msg::Pose gazebo_pose;
  double position_error;
  double orientation_error;
  union {
    double RingCirclePositionError;
    int HitArrorPrecision;
  };
  bool found_in_gazebo;

  ComparisonResult()
      : position_error(0.0), orientation_error(0.0), found_in_gazebo(false) {}
  ComparisonResult(std::string target_type, std::string model_name,
                   geometry_msgs::msg::Pose pnp_pose,
                   geometry_msgs::msg::Pose gazebo_pose, double position_error,
                   double orientation_error, bool found_in_gazebo)
      : target_type(target_type), model_name(model_name), pnp_pose(pnp_pose),
        gazebo_pose(gazebo_pose), position_error(position_error),
        orientation_error(orientation_error), found_in_gazebo(found_in_gazebo) {
  }
  friend std::ostream &operator<<(std::ostream &out,
                                  ComparisonResult &Errorresults) {
    out << " ErrorResults " << std::endl;
    out << "  stamp : " << Errorresults.generate_timestamp() << std::endl;
    out << "  target_type : " << Errorresults.target_type << std::endl;
    out << "  model_name : " << Errorresults.model_name << std::endl;
    out << "  pnp_pose : " << std::endl;
    out << "       - position : "
        << "[" << Errorresults.pnp_pose.position.x << " , "
        << Errorresults.pnp_pose.position.y << " , "
        << Errorresults.pnp_pose.position.z << "]" << std::endl;
    out << "       - orientation : "
        << "[" << Errorresults.pnp_pose.orientation.w << " , "
        << Errorresults.pnp_pose.orientation.x << " , "
        << Errorresults.pnp_pose.orientation.y << " , "
        << Errorresults.pnp_pose.orientation.z << "]" << std::endl;
    out << "  gazebo_pose : " << std::endl;
    out << "       - position : "
        << "[" << Errorresults.gazebo_pose.position.x << " , "
        << Errorresults.gazebo_pose.position.y << " , "
        << Errorresults.gazebo_pose.position.z << "]" << std::endl;
    out << "       - orientation : "
        << "[" << Errorresults.gazebo_pose.orientation.w << " , "
        << Errorresults.gazebo_pose.orientation.x << " , "
        << Errorresults.gazebo_pose.orientation.y << " , "
        << Errorresults.gazebo_pose.orientation.z << "]" << std::endl;
    out << "  RingCirclePositionError : " << Errorresults.RingCirclePositionError
        << std::endl;
    out << "  position_error : " << Errorresults.position_error << std::endl;
    out << "  orientation_error : " << Errorresults.orientation_error
        << std::endl;
    out << "  found_in_gazebo : " << Errorresults.found_in_gazebo << std::endl;
    out << std::endl;
    return out;
  }
  friend std::ostream &operator<<(std::ostream &out,
                                  ComparisonResult &&Errorresults) {
    out << " ErrorResults " << std::endl;
    out << "  stamp : " << Errorresults.generate_timestamp() << std::endl;
    out << "  target_type : " << Errorresults.target_type << std::endl;
    out << "  model_name : " << Errorresults.model_name << std::endl;
    out << "  pnp_pose : " << std::endl;
    out << "       - position : "
        << "[" << Errorresults.pnp_pose.position.x << " , "
        << Errorresults.pnp_pose.position.y << " , "
        << Errorresults.pnp_pose.position.z << "]" << std::endl;
    out << "       - orientation : "
        << "[" << Errorresults.pnp_pose.orientation.w << " , "
        << Errorresults.pnp_pose.orientation.x << " , "
        << Errorresults.pnp_pose.orientation.y << " , "
        << Errorresults.pnp_pose.orientation.z << "]" << std::endl;
    out << "  gazebo_pose : " << std::endl;
    out << "       - position : "
        << "[" << Errorresults.gazebo_pose.position.x << " , "
        << Errorresults.gazebo_pose.position.y << " , "
        << Errorresults.gazebo_pose.position.z << "]" << std::endl;
    out << "       -orientation : "
        << "[" << Errorresults.gazebo_pose.orientation.w << " , "
        << Errorresults.gazebo_pose.orientation.x << " , "
        << Errorresults.gazebo_pose.orientation.y << " , "
        << Errorresults.gazebo_pose.orientation.z << "]" << std::endl;
    out << "  RingCirclePositionError : " << Errorresults.RingCirclePositionError
        << std::endl;
    out << "  position_error : " << Errorresults.position_error << std::endl;
    out << "  orientation_error : " << Errorresults.orientation_error
        << std::endl;
    out << "  found_in_gazebo : " << Errorresults.found_in_gazebo << std::endl;
    out << std::endl;
    return out;
  }
  std::string generate_timestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%dT%H:%M:%SZ");
    return ss.str();
  }
};

} // namespace referee_pkg
namespace time_stamp {

/**
 * @brief 选手端信息存储
 * @param timestamp 时间戳 用于后续寻找对应模型真值
 * @param object_info 信息存储
 */
struct TimedObjectData {
  builtin_interfaces::msg::Time timestamp;
  referee_pkg::ObjectPoseInfo object_info;

  TimedObjectData(const builtin_interfaces::msg::Time &stamp,
                  const referee_pkg::ObjectPoseInfo &info)
      : timestamp(stamp), object_info(info) {}
};
/**
 * @brief 模型真值存储
 * @param timestamp 时间戳 用于后续寻找对应选手端
 * @param object_info 信息存储
 */
struct TimedModelData {
  builtin_interfaces::msg::Time timestamp;
  gazebo_msgs::msg::ModelStates model_states;

  TimedModelData(const builtin_interfaces::msg::Time &stamp,
                 const gazebo_msgs::msg::ModelStates &states)
      : timestamp(stamp), model_states(states) {}
};

/**
 * @brief 数据缓存类
 */
class DataMatcher {
public:
  /**
   * @brief 选手端信息存储
   */
  std::map<builtin_interfaces::msg::Time, referee_pkg::ObjectPoseInfo>
      object_data_map_;
  /**
   * @brief 选手端信息存储
   */
  std::map<builtin_interfaces::msg::Time,
           std::vector<referee_pkg::ObjectPoseInfo>>
      object_dataarray_map_;
  /**
   * @brief 模型真值存储
   */
  std::map<builtin_interfaces::msg::Time, gazebo_msgs::msg::ModelStates>
      model_data_map_;

private:
  rclcpp::Logger logger_;

public:
  DataMatcher(rclcpp::Logger logger, double max_time_diff = 0.1)
      : logger_(logger) {}

  /**
   * @brief  添加物体数据到队列
   * @param stamp 时间戳
   * @param info 信息
   */
  void addObjectData(const builtin_interfaces::msg::Time &stamp,
                     const referee_pkg::ObjectPoseInfo &info) {
    object_data_map_[stamp] = info;
  }
  void addObjectData(const builtin_interfaces::msg::Time &stamp,
                     const std::vector<referee_pkg::ObjectPoseInfo> &info) {
    object_dataarray_map_[stamp] = info;
  }
  /**
   * @brief  添加模型数据到队列
   * @param stamp 时间戳
   * @param states 信息
   */
  void addModelData(const builtin_interfaces::msg::Time &stamp,
                    const gazebo_msgs::msg::ModelStates &states) {
    model_data_map_[stamp] = states;
  }
  /**
   * @brief 时间戳匹配函数
   * @param object_info 最后输出的 时间戳匹配的选手端信息
   * @param model_states 最后输出的 时间戳匹配的模型真值
   */
  bool findMatchingData(referee_pkg::ObjectPoseInfo &object_info,
                        gazebo_msgs::msg::ModelStates &model_states);
  bool findMatchingData(std::vector<referee_pkg::ObjectPoseInfo> &object_info,
                        gazebo_msgs::msg::ModelStates &model_states);
  //   bool findMatchingData(referee_pkg::ObjectPoseInfo &object_info,
  //                         gazebo_msgs::msg::ModelStates &model_states) {
  //     if (object_data_map_.empty() || model_data_map_.empty()) {
  //       RCLCPP_INFO(logger_, "No data available");
  //       return false;
  //     }

  //     // 获取最新的物体数据（使用 begin() 获取第一个元素）
  //     auto latest_object = object_data_map_.begin();

  //     // 寻找最接近的时间戳（允许一定误差）
  //     auto closest_model = model_data_map_.end();
  //     double min_time_diff = std::numeric_limits<double>::max();

  //     for (auto it = model_data_map_.begin(); it != model_data_map_.end();
  //     ++it) {
  //       double time_diff =
  //           std::abs((rclcpp::Time(latest_object->first.sec,
  //                                  latest_object->first.nanosec) -
  //                     rclcpp::Time(it->first.sec, it->first.nanosec))
  //                        .seconds());

  //       if (time_diff < min_time_diff && time_diff < 0.01) {
  //         min_time_diff = time_diff;
  //         closest_model = it;
  //       }
  //     }

  //     if (closest_model == model_data_map_.end()) {
  //       RCLCPP_INFO(logger_,
  //                   "No matching model data found for object time: %d.%d",
  //                   latest_object->first.sec, latest_object->first.nanosec);
  //       return false;
  //     }

  //     object_info = latest_object->second;
  //     model_states = closest_model->second;

  //     // 删除已处理的数据（可选）
  //     object_data_map_.erase(latest_object->first);
  //     model_data_map_.erase(closest_model->first);

  //     RCLCPP_INFO(logger_, "Successfully matched data, time diff: %.6f
  //     seconds",
  //                 min_time_diff);
  //     return true;
  //   }

  /**
   * @brief 清空队列
   */
  void clear() {
    object_data_map_.clear();
    model_data_map_.clear();
  }
};

} // namespace time_stamp
#endif
