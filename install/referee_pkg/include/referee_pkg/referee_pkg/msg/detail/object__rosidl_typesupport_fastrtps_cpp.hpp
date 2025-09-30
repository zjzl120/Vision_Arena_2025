// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from referee_pkg:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define REFEREE_PKG__MSG__DETAIL__OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "referee_pkg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "referee_pkg/msg/detail/object__struct.hpp"

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

namespace referee_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_referee_pkg
cdr_serialize(
  const referee_pkg::msg::Object & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_referee_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  referee_pkg::msg::Object & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_referee_pkg
get_serialized_size(
  const referee_pkg::msg::Object & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_referee_pkg
max_serialized_size_Object(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace referee_pkg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_referee_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, referee_pkg, msg, Object)();

#ifdef __cplusplus
}
#endif

#endif  // REFEREE_PKG__MSG__DETAIL__OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
