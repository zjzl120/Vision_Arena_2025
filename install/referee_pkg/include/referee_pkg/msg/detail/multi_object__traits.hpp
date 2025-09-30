// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from referee_pkg:msg/MultiObject.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__TRAITS_HPP_
#define REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "referee_pkg/msg/detail/multi_object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'objects'
#include "referee_pkg/msg/detail/object__traits.hpp"

namespace referee_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const MultiObject & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: objects
  {
    if (msg.objects.size() == 0) {
      out << "objects: []";
    } else {
      out << "objects: [";
      size_t pending_items = msg.objects.size();
      for (auto item : msg.objects) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: num_objects
  {
    out << "num_objects: ";
    rosidl_generator_traits::value_to_yaml(msg.num_objects, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MultiObject & msg,
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

  // member: objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.objects.size() == 0) {
      out << "objects: []\n";
    } else {
      out << "objects:\n";
      for (auto item : msg.objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: num_objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_objects: ";
    rosidl_generator_traits::value_to_yaml(msg.num_objects, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MultiObject & msg, bool use_flow_style = false)
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
  const referee_pkg::msg::MultiObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  referee_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use referee_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const referee_pkg::msg::MultiObject & msg)
{
  return referee_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<referee_pkg::msg::MultiObject>()
{
  return "referee_pkg::msg::MultiObject";
}

template<>
inline const char * name<referee_pkg::msg::MultiObject>()
{
  return "referee_pkg/msg/MultiObject";
}

template<>
struct has_fixed_size<referee_pkg::msg::MultiObject>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<referee_pkg::msg::MultiObject>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<referee_pkg::msg::MultiObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__TRAITS_HPP_
