// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pose_msg:msg/ModelPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE__BUILDER_HPP_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pose_msg/msg/detail/model_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pose_msg
{

namespace msg
{

namespace builder
{

class Init_ModelPose_pose
{
public:
  explicit Init_ModelPose_pose(::pose_msg::msg::ModelPose & msg)
  : msg_(msg)
  {}
  ::pose_msg::msg::ModelPose pose(::pose_msg::msg::ModelPose::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_msg::msg::ModelPose msg_;
};

class Init_ModelPose_name
{
public:
  Init_ModelPose_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModelPose_pose name(::pose_msg::msg::ModelPose::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ModelPose_pose(msg_);
  }

private:
  ::pose_msg::msg::ModelPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_msg::msg::ModelPose>()
{
  return pose_msg::msg::builder::Init_ModelPose_name();
}

}  // namespace pose_msg

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE__BUILDER_HPP_
