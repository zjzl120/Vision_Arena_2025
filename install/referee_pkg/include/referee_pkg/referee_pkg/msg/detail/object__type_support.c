// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from referee_pkg:msg/Object.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "referee_pkg/msg/detail/object__rosidl_typesupport_introspection_c.h"
#include "referee_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "referee_pkg/msg/detail/object__functions.h"
#include "referee_pkg/msg/detail/object__struct.h"


// Include directives for member types
// Member `target_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `corners`
#include "geometry_msgs/msg/point.h"
// Member `corners`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  referee_pkg__msg__Object__init(message_memory);
}

void referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_fini_function(void * message_memory)
{
  referee_pkg__msg__Object__fini(message_memory);
}

size_t referee_pkg__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__corners(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * referee_pkg__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__corners(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * referee_pkg__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__corners(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void referee_pkg__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__corners(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__corners(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void referee_pkg__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__corners(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__corners(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool referee_pkg__msg__Object__rosidl_typesupport_introspection_c__resize_function__Object__corners(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[2] = {
  {
    "target_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__msg__Object, target_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "corners",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__msg__Object, corners),  // bytes offset in struct
    NULL,  // default value
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__corners,  // size() function pointer
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__corners,  // get_const(index) function pointer
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__corners,  // get(index) function pointer
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__corners,  // fetch(index, &value) function pointer
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__corners,  // assign(index, value) function pointer
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__resize_function__Object__corners  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_members = {
  "referee_pkg__msg",  // message namespace
  "Object",  // message name
  2,  // number of fields
  sizeof(referee_pkg__msg__Object),
  referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array,  // message members
  referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_init_function,  // function to initialize message memory (memory has to be allocated)
  referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_type_support_handle = {
  0,
  &referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_referee_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, msg, Object)() {
  referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_type_support_handle.typesupport_identifier) {
    referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &referee_pkg__msg__Object__rosidl_typesupport_introspection_c__Object_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
