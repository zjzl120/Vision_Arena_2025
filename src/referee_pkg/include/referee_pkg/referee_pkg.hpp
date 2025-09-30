#ifndef REFEREE_HPP_
#define REFEREE_HPP_
#include "gazebo_msgs/msg/model_states.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "pose_msg/msg/model_pose.hpp"
#include "pose_msg/msg/model_pose_array.hpp"
#include "referee_pkg/msg/detail/race_stage__struct.hpp"
#include "referee_pkg/msg/multi_object.hpp"
#include "referee_pkg/msg/object.hpp"
#include "referee_pkg/msg/race_stage.hpp"
#include "referee_pkg/srv/detail/hit_arror__struct.hpp"
#include "referee_pkg/srv/hit_arror.hpp"
#include "referee_pkg/utils.hpp"
#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <fstream>
#include <functional>
#include <memory>
#include <mutex>
#include <nlohmann/json.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/opencv.hpp>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>
#include <std_msgs/msg/detail/header__struct.hpp>
#include <string>
#include <tf2/LinearMath/Matrix3x3.h>  // 添加 tf2 矩阵支持
#include <tf2/LinearMath/Quaternion.h> // 添加 tf2 四元数支持
#include <thread>

using namespace std;
/**
 * @brief 裁判系统主类 万化归一
 */
class Referee : public rclcpp::Node {
public:
  /**
   * @brief 构造函数
   * @note 用于 发布者 订阅者 的定义；其中定义的 定时器用于限定
   * 最终结果输出的时间 即 比赛时间
   */
  Referee(string name) : Node(name) {
    multi_object_sub_ =
        this->create_subscription<referee_pkg::msg::MultiObject>(
            "/vision/target", 10,
            std::bind(&Referee::callback_Object, this,
                      std::placeholders::_1)); // 选手端消息订阅

    Status_sub = this->create_subscription<pose_msg::msg::ModelPoseArray>(
        "/gazebo/model_states", 10,
        bind(&Referee::callback_Status, this,
             std::placeholders::_1)); // 模型真值消息订阅
    Stage_pub = this->create_publisher<referee_pkg::msg::RaceStage>(
        "/referee/race_stage", 10); // 发布比赛阶段

    HitArror_clt = this->create_client<referee_pkg::srv::HitArror>(
        "/referee/hit_arror"); // 击打装甲板客户端

    data_matcher_ = std::make_unique<time_stamp::DataMatcher>(
        this->get_logger()); // 选手发布数据 与 真值数据 储存

    // launch 参数接收
    this->declare_parameter<string>("TeamName", "TeamA");
    this->get_parameter<string>("TeamName", TEAMNAME);
    this->declare_parameter<int>("ContinueTime", 100);
    this->get_parameter<int>("ContinueTime", ContinueTime);
    // 用于存储日志
    log_ = ofstream("results/" + TEAMNAME + "_results.log");
    if (!log_) {
      cout << "log build error" << endl;
      return;
    }
    // 裁判系统运行开始 发布当前所处比赛阶段
    stage_msg.stage = int(stage);
    Stage_pub->publish(stage_msg);
    RCLCPP_WARN(this->get_logger(),"%s", (string("当前比赛阶段 : STAGE_") + stage).c_str());
    
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000 * ContinueTime), [this]() {
          ++StageCount;
          this->CulculateScores(Errorresults, results, score);
          if (StageCount == referee_pkg::RACECOUNT) {
            ++stage;
            Errorresults.clear();
            data_matcher_->clear();
            results.clear();
            StageCount = 0;
            stage_msg.stage = int(stage);
            Stage_pub->publish(stage_msg);
            RCLCPP_WARN(this->get_logger(),"%s", (string("当前比赛阶段 : STAGE_") + stage).c_str());
          }
        }); // 比赛定时器
        
    // 初始化map
    for (auto i : referee_pkg::TARGET_DIMENSIONS) {
      referee_pkg::ErrorStatistics result(i.first);
      results.emplace(i.first, result);
      vector<referee_pkg::ComparisonResult> ErrorResult;
      Errorresults.emplace(i.first, ErrorResult);
    }
  }
  /**
   * @brief 析构函数 暂时只关闭 日志文件
   */
  ~Referee() { log_.close(); }

private:
  /// @brief 不做解释
  rclcpp::Subscription<referee_pkg::msg::MultiObject>::SharedPtr
      multi_object_sub_;
  /// @brief 不做解释
  rclcpp::Subscription<pose_msg::msg::ModelPoseArray>::SharedPtr Status_sub;
  /// @brief 不做解释
  rclcpp::Publisher<referee_pkg::msg::RaceStage>::SharedPtr Stage_pub;
  /// @brief 不做解释
  rclcpp::Client<referee_pkg::srv::HitArror>::SharedPtr HitArror_clt;
  /// @brief 不做解释
  std::unique_ptr<time_stamp::DataMatcher> data_matcher_;
  /**
   * @brief 用以发布比赛阶段信息
   */
  referee_pkg::msg::RaceStage stage_msg;
  /**
   * @brief 用于缓存每一次的选手端接受.回调结束即被清除
   */
  std::vector<referee_pkg::ObjectPoseInfo> object_pose_infos;
  /**
   * @brief 比赛定时器
   */
  rclcpp::TimerBase::SharedPtr timer_;
  /// @brief 比较结果存储数组 在比赛结束前都不被清理
  unordered_map<std::string, vector<referee_pkg::ComparisonResult>>
      Errorresults;
  /// @brief 最终结果存储
  unordered_map<std::string, referee_pkg::ErrorStatistics> results;
  /// @brief 用于生成json 及对应哈希的类
  JsonGenerator Json;
  /// @brief 互斥量 因为AddError 使用了多线程
  mutex AddError_mutex;
  /// @brief 条件变量
  condition_variable AddError_cv;
  /// @brief 分数
  double score;
  /// @brief 队伍名称
  string TEAMNAME;
  /// @brief 比赛持续时间
  int ContinueTime;
  /// @brief 每阶段循环次数
  int StageCount = 0;
  /// @brief 比赛阶段枚举
  enum RaceStage stage = RaceStage::STAGE_1;
  /// @brief 日志
  ofstream log_;
  /**
   * @brief 接收选手端信息 并对其进行处理
   * @param data_matcher_ 最终结果存储在其中的 object_data_map 中
   */
  void callback_Object(const referee_pkg::msg::MultiObject::SharedPtr msg);
  /**
   * @brief 接收真值 并对其进行处理
   * @param data_matcher_  最终结果存储在的 model_data_map 中
   */
  void callback_Status(const pose_msg::msg::ModelPoseArray::SharedPtr msg);
  /**
   * @brief 计算误差
   * @param Errorresults 结果保存
   */
  void
  addError(unordered_map<std::string, vector<referee_pkg::ComparisonResult>>
               &Errorresults);
  /**
   * @brief 进行最终的计算分数 并输出 json 
   * @param results 结果储存 但不使用
   */
  void CulculateScores(
      unordered_map<std::string, vector<referee_pkg::ComparisonResult>>
          &Errorresults,
      unordered_map<std::string, referee_pkg::ErrorStatistics> &results,
      double scores);
  /**
   * @brief 向选手端发送请求
   * @param modelpoints 模型上的四个点与之前相似
   * @param header 当前时间戳
   * @param g 重力加速度
   * @note
   * 需要多加注意的是该函数没有等待服务端上线的逻辑，但没有服务端没有上线的这一段时间中也被计入比赛时间
   */
  void HitArrorSendRequest(vector<geometry_msgs::msg::Point> modelpoints,
                           std_msgs::msg::Header header, double g) {
    if (HitArror_clt->service_is_ready()) {
      auto request = std::make_shared<referee_pkg::srv::HitArror_Request>();
      request->g = g;
      request->header = header;
      request->modelpoint = modelpoints;
      RCLCPP_WARN(this->get_logger(),"发布击打装甲板信息 : g : %lf" , g);
      HitArror_clt->async_send_request(
          request,
          bind(&Referee::HitArrorReponse_Callback, this, placeholders::_1));
    }
  }
  /**
   * @brief 用于接收选手端返回的三轴旋转
   * @param result_future 用于接受返回信息
   * @note 需要注意的是此函数高度集成将所有被调用函数均化作 lambda表达式
   */
  void HitArrorReponse_Callback(
      rclcpp::Client<referee_pkg::srv::HitArror>::SharedFuture result_future);
  /**
   * @brief 解密函数用于解密gazebo发送过来的加密真值
   * @param ciphertext 经加密后的模型信息
   * @return 返回解密后的串
   */
  std::vector<unsigned char>
  decryptData(const std::vector<unsigned char> &ciphertext);
  /**
   * @brief 将解密后的串构造成 ModelPoseArray
   * @param 经 decryptData 函数解密后的串
   * @return 返回正常的未被加密能直接使用的模型信息
   */
  pose_msg::msg::ModelPoseArray
  deserializeModelStates(const std::vector<unsigned char> &data);
  /**
   * @brief 处理模型信息
   * @param msg deserializeModelStates 返回的模型信息
   */
  void processModelStates(const pose_msg::msg::ModelPoseArray &msg);
};

#endif // REFEREE_HPP_