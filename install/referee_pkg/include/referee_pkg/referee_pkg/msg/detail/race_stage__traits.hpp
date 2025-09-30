// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from referee_pkg:msg/RaceStage.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__RACE_STAGE__TRAITS_HPP_
#define REFEREE_PKG__MSG__DETAIL__RACE_STAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "referee_pkg/msg/detail/race_stage__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace referee_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const RaceStage & msg,
  std::ostream & out)
{
  out << "{";
  // member: stage
  {
    out << "stage: ";
    rosidl_generator_traits::value_to_yaml(msg.stage, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RaceStage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stage: ";
    rosidl_generator_traits::value_to_yaml(msg.stage, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RaceStage & msg, bool use_flow_style = false)
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
  const referee_pkg::msg::RaceStage & msg,
  std::ostream & out, size_t indentation = 0)
{
  referee_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use referee_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const referee_pkg::msg::RaceStage & msg)
{
  return referee_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<referee_pkg::msg::RaceStage>()
{
  return "referee_pkg::msg::RaceStage";
}

template<>
inline const char * name<referee_pkg::msg::RaceStage>()
{
  return "referee_pkg/msg/RaceStage";
}

template<>
struct has_fixed_size<referee_pkg::msg::RaceStage>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<referee_pkg::msg::RaceStage>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<referee_pkg::msg::RaceStage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // REFEREE_PKG__MSG__DETAIL__RACE_STAGE__TRAITS_HPP_
