// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pose_msg:msg/ModelPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE__TRAITS_HPP_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pose_msg/msg/detail/model_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace pose_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const ModelPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ModelPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ModelPose & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pose_msg

namespace rosidl_generator_traits
{

[[deprecated("use pose_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pose_msg::msg::ModelPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  pose_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pose_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const pose_msg::msg::ModelPose & msg)
{
  return pose_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pose_msg::msg::ModelPose>()
{
  return "pose_msg::msg::ModelPose";
}

template<>
inline const char * name<pose_msg::msg::ModelPose>()
{
  return "pose_msg/msg/ModelPose";
}

template<>
struct has_fixed_size<pose_msg::msg::ModelPose>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pose_msg::msg::ModelPose>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pose_msg::msg::ModelPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE__TRAITS_HPP_
