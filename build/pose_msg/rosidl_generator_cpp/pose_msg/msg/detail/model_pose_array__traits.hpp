// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pose_msg:msg/ModelPoseArray.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__TRAITS_HPP_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pose_msg/msg/detail/model_pose_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'models'
#include "pose_msg/msg/detail/model_pose__traits.hpp"

namespace pose_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const ModelPoseArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: models
  {
    if (msg.models.size() == 0) {
      out << "models: []";
    } else {
      out << "models: [";
      size_t pending_items = msg.models.size();
      for (auto item : msg.models) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: is_encrypted
  {
    out << "is_encrypted: ";
    rosidl_generator_traits::value_to_yaml(msg.is_encrypted, out);
    out << ", ";
  }

  // member: encrypted_data
  {
    if (msg.encrypted_data.size() == 0) {
      out << "encrypted_data: []";
    } else {
      out << "encrypted_data: [";
      size_t pending_items = msg.encrypted_data.size();
      for (auto item : msg.encrypted_data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ModelPoseArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: models
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.models.size() == 0) {
      out << "models: []\n";
    } else {
      out << "models:\n";
      for (auto item : msg.models) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: is_encrypted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_encrypted: ";
    rosidl_generator_traits::value_to_yaml(msg.is_encrypted, out);
    out << "\n";
  }

  // member: encrypted_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.encrypted_data.size() == 0) {
      out << "encrypted_data: []\n";
    } else {
      out << "encrypted_data:\n";
      for (auto item : msg.encrypted_data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ModelPoseArray & msg, bool use_flow_style = false)
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
  const pose_msg::msg::ModelPoseArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  pose_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pose_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const pose_msg::msg::ModelPoseArray & msg)
{
  return pose_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pose_msg::msg::ModelPoseArray>()
{
  return "pose_msg::msg::ModelPoseArray";
}

template<>
inline const char * name<pose_msg::msg::ModelPoseArray>()
{
  return "pose_msg/msg/ModelPoseArray";
}

template<>
struct has_fixed_size<pose_msg::msg::ModelPoseArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pose_msg::msg::ModelPoseArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pose_msg::msg::ModelPoseArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__TRAITS_HPP_
