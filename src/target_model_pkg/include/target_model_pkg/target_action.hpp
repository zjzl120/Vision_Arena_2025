#ifndef TARGET_ACTION_HPP
#define TARGET_ACTION_HPP

#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Vector3.hh>
#include <ignition/math/Pose3.hh>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/vector3.hpp>
#include "std_msgs/msg/int32.hpp"
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <thread>
#include <pluginlib/class_list_macros.hpp>
#include "geometry_msgs/msg/pose_array.hpp"
#include "pose_msg/msg/model_pose.hpp"
#include "pose_msg/msg/model_pose_array.hpp"

namespace target_action{

 
class TargetAction : public gazebo::ModelPlugin
{
private:
    gazebo::physics::ModelPtr model ;
    sdf::ElementPtr sdf;
    
    ignition::math::Pose3d initialPose;
    gazebo::event::ConnectionPtr updateConnection; // 用来订阅 Gazebo 的 "WorldUpdateBegin" 事件
    double timeElapsed = 0.0; // 仿真时间
    gazebo::physics::LinkPtr link;
    int type = 0;
    ignition::math::Vector3d linearVel;
    ignition::math::Vector3d angularVel;



    rclcpp::Node::SharedPtr node;
    rclcpp::executors::SingleThreadedExecutor executor_; 
    
    rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr pose_sub;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr type_sub;
    // rclcpp::Publisher<pose_msg::msg::ModelPoseArray>::SharedPtr pose_pub;

public:
   
    TargetAction()=default;
    virtual ~TargetAction()=default; 

    void Load(gazebo::physics::ModelPtr _model,
                              sdf::ElementPtr _sdf) override;


    // void Init() override;
    // void Reset() override;

    void update();

};


}

#endif
