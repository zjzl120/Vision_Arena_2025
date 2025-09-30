#include <gazebo/common/Events.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/World.hh>
#include <rclcpp/rclcpp.hpp>
#include <pose_msg/msg/model_pose.hpp>
#include "pose_msg/msg/model_pose_array.hpp"

namespace gazebo {

class AllModelsPosePublisher : public WorldPlugin {
public:
  AllModelsPosePublisher() : WorldPlugin() {}
  
  virtual void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf) {
    // 存储世界指针
    world_ = _world;
    
      if (!rclcpp::ok())
      rclcpp::init(0, nullptr);
    node = rclcpp::Node::make_shared("task_model");
    executor_.add_node(node);
    // 创建发布者
    publisher_ = node->create_publisher<pose_msg::msg::ModelPoseArray>(
        "/gazebo/model_states", 10);

    
    // 从 SDF 获取参数
    double update_rate = 30.0; // Hz
    if (_sdf->HasElement("updateRate")) {
      update_rate = _sdf->Get<double>("updateRate");
    }
    
    
    
    // 设置更新回调
    update_connection_ = event::Events::ConnectWorldUpdateBegin(
        std::bind(&AllModelsPosePublisher::OnUpdate, this));
    
    // 设置定时器
    update_period_ = 1.0 / update_rate;
    last_update_time_ = world_->SimTime();
    
    RCLCPP_INFO(node->get_logger(), 
               "All models pose publisher loaded");
  }

private:
  void OnUpdate() {
    auto current_time = world_->SimTime();
    if ((current_time - last_update_time_).Double() < update_period_) {
      return;
    }
    
    
    // 创建消息
    auto msg = pose_msg::msg::ModelPoseArray();
     msg.header.stamp.sec = current_time.sec;
        msg.header.stamp.nanosec = current_time.nsec;
    msg.header.frame_id = "world";
    
    // 获取所有模型
    physics::Model_V models = world_->Models();
    
    // 遍历所有模型并获取位姿
    for (auto &model : models) {
      if(model->GetName()=="ground_plane"||model->GetName()=="camera_robot")
        continue;
      pose_msg::msg::ModelPose model_pose;
      
      
      // 获取模型的世界位姿
      ignition::math::Pose3d pose = model->WorldPose();
      model_pose.name = model->GetName();
      // 填充位置
      model_pose.pose.position.x = pose.Pos().X();
      model_pose.pose.position.y = pose.Pos().Y();
      model_pose.pose.position.z = pose.Pos().Z();
      
      // 填充方向
      // model_pose.models.pose.orientation.x = pose.Rot().X();
      // model_pose.models.pose.orientation.y = pose.Rot().Y();
      // model_pose.models.pose.orientation.z = pose.Rot().Z();
      // model_pose.models.pose.orientation.w = pose.Rot().W();
      
      // 添加到消息数组
      msg.models.push_back(model_pose);
    }
    
    // 发布消息
    publisher_->publish(msg);
    last_update_time_ = current_time;
  }

  physics::WorldPtr world_;
  rclcpp::Node::SharedPtr node;
  rclcpp::executors::SingleThreadedExecutor executor_; 
  rclcpp::Publisher<pose_msg::msg::ModelPoseArray>::SharedPtr publisher_;
  event::ConnectionPtr update_connection_;
  common::Time last_update_time_;
  double update_period_;
};

GZ_REGISTER_WORLD_PLUGIN(AllModelsPosePublisher)
}  // namespace gazebo
