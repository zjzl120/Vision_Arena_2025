// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from pose_msg:msg/ModelPoseArray.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pose_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "pose_msg/msg/detail/model_pose_array__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace pose_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pose_msg
cdr_serialize(
  const pose_msg::msg::ModelPoseArray & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pose_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pose_msg::msg::ModelPoseArray & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pose_msg
get_serialized_size(
  const pose_msg::msg::ModelPoseArray & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pose_msg
max_serialized_size_ModelPoseArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pose_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pose_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pose_msg, msg, ModelPoseArray)();

#ifdef __cplusplus
}
#endif

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
