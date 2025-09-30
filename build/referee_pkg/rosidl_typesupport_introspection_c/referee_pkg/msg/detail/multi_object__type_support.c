// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from referee_pkg:msg/MultiObject.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "referee_pkg/msg/detail/multi_object__rosidl_typesupport_introspection_c.h"
#include "referee_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "referee_pkg/msg/detail/multi_object__functions.h"
#include "referee_pkg/msg/detail/multi_object__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `objects`
#include "referee_pkg/msg/object.h"
// Member `objects`
#include "referee_pkg/msg/detail/object__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  referee_pkg__msg__MultiObject__init(message_memory);
}

void referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_fini_function(void * message_memory)
{
  referee_pkg__msg__MultiObject__fini(message_memory);
}

size_t referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__size_function__MultiObject__objects(
  const void * untyped_member)
{
  const referee_pkg__msg__Object__Sequence * member =
    (const referee_pkg__msg__Object__Sequence *)(untyped_member);
  return member->size;
}

const void * referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__get_const_function__MultiObject__objects(
  const void * untyped_member, size_t index)
{
  const referee_pkg__msg__Object__Sequence * member =
    (const referee_pkg__msg__Object__Sequence *)(untyped_member);
  return &member->data[index];
}

void * referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__get_function__MultiObject__objects(
  void * untyped_member, size_t index)
{
  referee_pkg__msg__Object__Sequence * member =
    (referee_pkg__msg__Object__Sequence *)(untyped_member);
  return &member->data[index];
}

void referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__fetch_function__MultiObject__objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const referee_pkg__msg__Object * item =
    ((const referee_pkg__msg__Object *)
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__get_const_function__MultiObject__objects(untyped_member, index));
  referee_pkg__msg__Object * value =
    (referee_pkg__msg__Object *)(untyped_value);
  *value = *item;
}

void referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__assign_function__MultiObject__objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  referee_pkg__msg__Object * item =
    ((referee_pkg__msg__Object *)
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__get_function__MultiObject__objects(untyped_member, index));
  const referee_pkg__msg__Object * value =
    (const referee_pkg__msg__Object *)(untyped_value);
  *item = *value;
}

bool referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__resize_function__MultiObject__objects(
  void * untyped_member, size_t size)
{
  referee_pkg__msg__Object__Sequence * member =
    (referee_pkg__msg__Object__Sequence *)(untyped_member);
  referee_pkg__msg__Object__Sequence__fini(member);
  return referee_pkg__msg__Object__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__msg__MultiObject, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__msg__MultiObject, objects),  // bytes offset in struct
    NULL,  // default value
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__size_function__MultiObject__objects,  // size() function pointer
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__get_const_function__MultiObject__objects,  // get_const(index) function pointer
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__get_function__MultiObject__objects,  // get(index) function pointer
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__fetch_function__MultiObject__objects,  // fetch(index, &value) function pointer
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__assign_function__MultiObject__objects,  // assign(index, value) function pointer
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__resize_function__MultiObject__objects  // resize(index) function pointer
  },
  {
    "num_objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__msg__MultiObject, num_objects),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_members = {
  "referee_pkg__msg",  // message namespace
  "MultiObject",  // message name
  3,  // number of fields
  sizeof(referee_pkg__msg__MultiObject),
  referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_member_array,  // message members
  referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_init_function,  // function to initialize message memory (memory has to be allocated)
  referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_type_support_handle = {
  0,
  &referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_referee_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, msg, MultiObject)() {
  referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, msg, Object)();
  if (!referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_type_support_handle.typesupport_identifier) {
    referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &referee_pkg__msg__MultiObject__rosidl_typesupport_introspection_c__MultiObject_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
