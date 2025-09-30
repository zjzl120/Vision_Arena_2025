// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from referee_pkg:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__OBJECT__TRAITS_HPP_
#define REFEREE_PKG__MSG__DETAIL__OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "referee_pkg/msg/detail/object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'corners'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace referee_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Object & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_type
  {
    out << "target_type: ";
    rosidl_generator_traits::value_to_yaml(msg.target_type, out);
    out << ", ";
  }

  // member: corners
  {
    if (msg.corners.size() == 0) {
      out << "corners: []";
    } else {
      out << "corners: [";
      size_t pending_items = msg.corners.size();
      for (auto item : msg.corners) {
        to_flow_style_yaml(item, out);
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
  const Object & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_type: ";
    rosidl_generator_traits::value_to_yaml(msg.target_type, out);
    out << "\n";
  }

  // member: corners
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.corners.size() == 0) {
      out << "corners: []\n";
    } else {
      out << "corners:\n";
      for (auto item : msg.corners) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Object & msg, bool use_flow_style = false)
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

}  // namespace referee_pkg

namespace rosidl_generator_traits
{

[[deprecated("use referee_pkg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const referee_pkg::msg::Object & msg,
  std::ostream & out, size_t indentation = 0)
{
  referee_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use referee_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const referee_pkg::msg::Object & msg)
{
  return referee_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<referee_pkg::msg::Object>()
{
  return "referee_pkg::msg::Object";
}

template<>
inline const char * name<referee_pkg::msg::Object>()
{
  return "referee_pkg/msg/Object";
}

template<>
struct has_fixed_size<referee_pkg::msg::Object>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<referee_pkg::msg::Object>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<referee_pkg::msg::Object>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // REFEREE_PKG__MSG__DETAIL__OBJECT__TRAITS_HPP_
