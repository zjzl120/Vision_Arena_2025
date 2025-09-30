// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from referee_pkg:msg/RaceStage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "referee_pkg/msg/detail/race_stage__rosidl_typesupport_introspection_c.h"
#include "referee_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "referee_pkg/msg/detail/race_stage__functions.h"
#include "referee_pkg/msg/detail/race_stage__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  referee_pkg__msg__RaceStage__init(message_memory);
}

void referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_fini_function(void * message_memory)
{
  referee_pkg__msg__RaceStage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_message_member_array[1] = {
  {
    "stage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__msg__RaceStage, stage),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_message_members = {
  "referee_pkg__msg",  // message namespace
  "RaceStage",  // message name
  1,  // number of fields
  sizeof(referee_pkg__msg__RaceStage),
  referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_message_member_array,  // message members
  referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_init_function,  // function to initialize message memory (memory has to be allocated)
  referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_message_type_support_handle = {
  0,
  &referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_referee_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, msg, RaceStage)() {
  if (!referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_message_type_support_handle.typesupport_identifier) {
    referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &referee_pkg__msg__RaceStage__rosidl_typesupport_introspection_c__RaceStage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
