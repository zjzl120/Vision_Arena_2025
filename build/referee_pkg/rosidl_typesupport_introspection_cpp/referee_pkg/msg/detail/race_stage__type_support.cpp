// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from referee_pkg:msg/RaceStage.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "referee_pkg/msg/detail/race_stage__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace referee_pkg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RaceStage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) referee_pkg::msg::RaceStage(_init);
}

void RaceStage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<referee_pkg::msg::RaceStage *>(message_memory);
  typed_message->~RaceStage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RaceStage_message_member_array[1] = {
  {
    "stage",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg::msg::RaceStage, stage),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RaceStage_message_members = {
  "referee_pkg::msg",  // message namespace
  "RaceStage",  // message name
  1,  // number of fields
  sizeof(referee_pkg::msg::RaceStage),
  RaceStage_message_member_array,  // message members
  RaceStage_init_function,  // function to initialize message memory (memory has to be allocated)
  RaceStage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RaceStage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RaceStage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace referee_pkg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<referee_pkg::msg::RaceStage>()
{
  return &::referee_pkg::msg::rosidl_typesupport_introspection_cpp::RaceStage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, referee_pkg, msg, RaceStage)() {
  return &::referee_pkg::msg::rosidl_typesupport_introspection_cpp::RaceStage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
