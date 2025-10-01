// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from referee_pkg:srv/HitArmor.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__SRV__DETAIL__HIT_ARMOR__TRAITS_HPP_
#define REFEREE_PKG__SRV__DETAIL__HIT_ARMOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "referee_pkg/srv/detail/hit_armor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'modelpoint'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace referee_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const HitArmor_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: modelpoint
  {
    if (msg.modelpoint.size() == 0) {
      out << "modelpoint: []";
    } else {
      out << "modelpoint: [";
      size_t pending_items = msg.modelpoint.size();
      for (auto item : msg.modelpoint) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: g
  {
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HitArmor_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: modelpoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.modelpoint.size() == 0) {
      out << "modelpoint: []\n";
    } else {
      out << "modelpoint:\n";
      for (auto item : msg.modelpoint) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HitArmor_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace referee_pkg

namespace rosidl_generator_traits
{

[[deprecated("use referee_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const referee_pkg::srv::HitArmor_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  referee_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use referee_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const referee_pkg::srv::HitArmor_Request & msg)
{
  return referee_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<referee_pkg::srv::HitArmor_Request>()
{
  return "referee_pkg::srv::HitArmor_Request";
}

template<>
inline const char * name<referee_pkg::srv::HitArmor_Request>()
{
  return "referee_pkg/srv/HitArmor_Request";
}

template<>
struct has_fixed_size<referee_pkg::srv::HitArmor_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<referee_pkg::srv::HitArmor_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<referee_pkg::srv::HitArmor_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace referee_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const HitArmor_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HitArmor_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HitArmor_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace referee_pkg

namespace rosidl_generator_traits
{

[[deprecated("use referee_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const referee_pkg::srv::HitArmor_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  referee_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use referee_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const referee_pkg::srv::HitArmor_Response & msg)
{
  return referee_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<referee_pkg::srv::HitArmor_Response>()
{
  return "referee_pkg::srv::HitArmor_Response";
}

template<>
inline const char * name<referee_pkg::srv::HitArmor_Response>()
{
  return "referee_pkg/srv/HitArmor_Response";
}

template<>
struct has_fixed_size<referee_pkg::srv::HitArmor_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<referee_pkg::srv::HitArmor_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<referee_pkg::srv::HitArmor_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<referee_pkg::srv::HitArmor>()
{
  return "referee_pkg::srv::HitArmor";
}

template<>
inline const char * name<referee_pkg::srv::HitArmor>()
{
  return "referee_pkg/srv/HitArmor";
}

template<>
struct has_fixed_size<referee_pkg::srv::HitArmor>
  : std::integral_constant<
    bool,
    has_fixed_size<referee_pkg::srv::HitArmor_Request>::value &&
    has_fixed_size<referee_pkg::srv::HitArmor_Response>::value
  >
{
};

template<>
struct has_bounded_size<referee_pkg::srv::HitArmor>
  : std::integral_constant<
    bool,
    has_bounded_size<referee_pkg::srv::HitArmor_Request>::value &&
    has_bounded_size<referee_pkg::srv::HitArmor_Response>::value
  >
{
};

template<>
struct is_service<referee_pkg::srv::HitArmor>
  : std::true_type
{
};

template<>
struct is_service_request<referee_pkg::srv::HitArmor_Request>
  : std::true_type
{
};

template<>
struct is_service_response<referee_pkg::srv::HitArmor_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // REFEREE_PKG__SRV__DETAIL__HIT_ARMOR__TRAITS_HPP_
