// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pose_msg:msg/ModelPoseArray.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__BUILDER_HPP_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pose_msg/msg/detail/model_pose_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pose_msg
{

namespace msg
{

namespace builder
{

class Init_ModelPoseArray_encrypted_data
{
public:
  explicit Init_ModelPoseArray_encrypted_data(::pose_msg::msg::ModelPoseArray & msg)
  : msg_(msg)
  {}
  ::pose_msg::msg::ModelPoseArray encrypted_data(::pose_msg::msg::ModelPoseArray::_encrypted_data_type arg)
  {
    msg_.encrypted_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_msg::msg::ModelPoseArray msg_;
};

class Init_ModelPoseArray_is_encrypted
{
public:
  explicit Init_ModelPoseArray_is_encrypted(::pose_msg::msg::ModelPoseArray & msg)
  : msg_(msg)
  {}
  Init_ModelPoseArray_encrypted_data is_encrypted(::pose_msg::msg::ModelPoseArray::_is_encrypted_type arg)
  {
    msg_.is_encrypted = std::move(arg);
    return Init_ModelPoseArray_encrypted_data(msg_);
  }

private:
  ::pose_msg::msg::ModelPoseArray msg_;
};

class Init_ModelPoseArray_models
{
public:
  explicit Init_ModelPoseArray_models(::pose_msg::msg::ModelPoseArray & msg)
  : msg_(msg)
  {}
  Init_ModelPoseArray_is_encrypted models(::pose_msg::msg::ModelPoseArray::_models_type arg)
  {
    msg_.models = std::move(arg);
    return Init_ModelPoseArray_is_encrypted(msg_);
  }

private:
  ::pose_msg::msg::ModelPoseArray msg_;
};

class Init_ModelPoseArray_header
{
public:
  Init_ModelPoseArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModelPoseArray_models header(::pose_msg::msg::ModelPoseArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ModelPoseArray_models(msg_);
  }

private:
  ::pose_msg::msg::ModelPoseArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_msg::msg::ModelPoseArray>()
{
  return pose_msg::msg::builder::Init_ModelPoseArray_header();
}

}  // namespace pose_msg

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__BUILDER_HPP_
