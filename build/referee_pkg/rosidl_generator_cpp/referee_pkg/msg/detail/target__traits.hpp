// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from referee_pkg:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__TARGET__TRAITS_HPP_
#define REFEREE_PKG__MSG__DETAIL__TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "referee_pkg/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace referee_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Target & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_type
  {
    out << "target_type: ";
    rosidl_generator_traits::value_to_yaml(msg.target_type, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Target & msg,
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

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Target & msg, bool use_flow_style = false)
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
  const referee_pkg::msg::Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  referee_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use referee_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const referee_pkg::msg::Target & msg)
{
  return referee_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<referee_pkg::msg::Target>()
{
  return "referee_pkg::msg::Target";
}

template<>
inline const char * name<referee_pkg::msg::Target>()
{
  return "referee_pkg/msg/Target";
}

template<>
struct has_fixed_size<referee_pkg::msg::Target>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<referee_pkg::msg::Target>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<referee_pkg::msg::Target>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // REFEREE_PKG__MSG__DETAIL__TARGET__TRAITS_HPP_
