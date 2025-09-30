#include "target_model_pkg/target_action.hpp"

#include <thread>

namespace target_action {

void TargetAction::Load(gazebo::physics::ModelPtr _model,
                        sdf::ElementPtr _sdf) {
  gzmsg << "TargetAction plugin loaded for model: " << _model->GetName()
        << std::endl;
  
                      

  model = _model;
  sdf = _sdf;
  link = model->GetLinks()[0];

//让插件读取sdf参数
  if (_sdf->HasElement("type")) {
    this->type = _sdf->Get<int>("type");
    gzmsg << "Initial type set from SDF: " << this->type << std::endl;
  } else {
    this->type = 0; // 默认值
  }



  linearVel = ignition::math::Vector3d::Zero;
  angularVel = ignition::math::Vector3d::Zero;

  // 初始化 ROS2 Node
  if (!rclcpp::ok()) rclcpp::init(0, nullptr);
  node = rclcpp::Node::make_shared("task_model");
  executor_.add_node(node);
  
  type_sub = node->create_subscription<std_msgs::msg::Int32>(
      "/type", 10, [this](const std_msgs::msg::Int32::SharedPtr msg) {
         this-> type = msg->data;
        
      });

  pose_sub = node->create_subscription<geometry_msgs::msg::Pose>(
      "/pose", 10, [this](const geometry_msgs::msg::Pose::SharedPtr msg) {
        ignition::math::Pose3d p(
            ignition::math::v6::Vector3d(msg->position.x, msg->position.y,
                                         msg->position.z),
            ignition::math::Quaterniond(
        msg->orientation.w,
        msg->orientation.x,
        msg->orientation.y,
        msg->orientation.z)

        );
        this->link->SetWorldPose(p);
      });

  // 订阅线速度



  updateConnection = gazebo::event::Events::ConnectWorldUpdateBegin(
      std::bind(&TargetAction::update, this));


}

void TargetAction ::update() {
  this->link = model->GetLinks()[0];

  link->SetLinearVel(linearVel);

  if (type == 0) {
            this->linearVel = ignition::math::Vector3d(0, 0, 0);
          } else  if(type == 1) {
            double t = model->GetWorld()->SimTime().Double(); // 仿真秒
            double vx = 2.0 * sin(t * M_PI); // X方向正弦周期运动
            double vy = 2.0 * cos(t * M_PI); // Y方向余弦周期运动
            this->linearVel = ignition::math::Vector3d(vx, vy, 0);
          } else  if (type == 2) {
            this->linearVel = ignition::math::Vector3d(0, 0, 0);
            this->angularVel = ignition::math::Vector3d(0, M_PI/6, 0); 
            link->SetAngularVel(angularVel);
          } 

gzmsg << "AngularVel: " << this->angularVel << std::endl;
  executor_.spin_some();
}

}  // namespace target_action

GZ_REGISTER_MODEL_PLUGIN(target_action::TargetAction)
