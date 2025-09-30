// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pose_msg:msg/ModelPoseArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pose_msg/msg/detail/model_pose_array__rosidl_typesupport_introspection_c.h"
#include "pose_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pose_msg/msg/detail/model_pose_array__functions.h"
#include "pose_msg/msg/detail/model_pose_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `models`
#include "pose_msg/msg/model_pose.h"
// Member `models`
#include "pose_msg/msg/detail/model_pose__rosidl_typesupport_introspection_c.h"
// Member `encrypted_data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_msg__msg__ModelPoseArray__init(message_memory);
}

void pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_fini_function(void * message_memory)
{
  pose_msg__msg__ModelPoseArray__fini(message_memory);
}

size_t pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__size_function__ModelPoseArray__models(
  const void * untyped_member)
{
  const pose_msg__msg__ModelPose__Sequence * member =
    (const pose_msg__msg__ModelPose__Sequence *)(untyped_member);
  return member->size;
}

const void * pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_const_function__ModelPoseArray__models(
  const void * untyped_member, size_t index)
{
  const pose_msg__msg__ModelPose__Sequence * member =
    (const pose_msg__msg__ModelPose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_function__ModelPoseArray__models(
  void * untyped_member, size_t index)
{
  pose_msg__msg__ModelPose__Sequence * member =
    (pose_msg__msg__ModelPose__Sequence *)(untyped_member);
  return &member->data[index];
}

void pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__fetch_function__ModelPoseArray__models(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const pose_msg__msg__ModelPose * item =
    ((const pose_msg__msg__ModelPose *)
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_const_function__ModelPoseArray__models(untyped_member, index));
  pose_msg__msg__ModelPose * value =
    (pose_msg__msg__ModelPose *)(untyped_value);
  *value = *item;
}

void pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__assign_function__ModelPoseArray__models(
  void * untyped_member, size_t index, const void * untyped_value)
{
  pose_msg__msg__ModelPose * item =
    ((pose_msg__msg__ModelPose *)
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_function__ModelPoseArray__models(untyped_member, index));
  const pose_msg__msg__ModelPose * value =
    (const pose_msg__msg__ModelPose *)(untyped_value);
  *item = *value;
}

bool pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__resize_function__ModelPoseArray__models(
  void * untyped_member, size_t size)
{
  pose_msg__msg__ModelPose__Sequence * member =
    (pose_msg__msg__ModelPose__Sequence *)(untyped_member);
  pose_msg__msg__ModelPose__Sequence__fini(member);
  return pose_msg__msg__ModelPose__Sequence__init(member, size);
}

size_t pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__size_function__ModelPoseArray__encrypted_data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_const_function__ModelPoseArray__encrypted_data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_function__ModelPoseArray__encrypted_data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__fetch_function__ModelPoseArray__encrypted_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_const_function__ModelPoseArray__encrypted_data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__assign_function__ModelPoseArray__encrypted_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_function__ModelPoseArray__encrypted_data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__resize_function__ModelPoseArray__encrypted_data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg__msg__ModelPoseArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "models",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg__msg__ModelPoseArray, models),  // bytes offset in struct
    NULL,  // default value
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__size_function__ModelPoseArray__models,  // size() function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_const_function__ModelPoseArray__models,  // get_const(index) function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_function__ModelPoseArray__models,  // get(index) function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__fetch_function__ModelPoseArray__models,  // fetch(index, &value) function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__assign_function__ModelPoseArray__models,  // assign(index, value) function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__resize_function__ModelPoseArray__models  // resize(index) function pointer
  },
  {
    "is_encrypted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg__msg__ModelPoseArray, is_encrypted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "encrypted_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg__msg__ModelPoseArray, encrypted_data),  // bytes offset in struct
    NULL,  // default value
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__size_function__ModelPoseArray__encrypted_data,  // size() function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_const_function__ModelPoseArray__encrypted_data,  // get_const(index) function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__get_function__ModelPoseArray__encrypted_data,  // get(index) function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__fetch_function__ModelPoseArray__encrypted_data,  // fetch(index, &value) function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__assign_function__ModelPoseArray__encrypted_data,  // assign(index, value) function pointer
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__resize_function__ModelPoseArray__encrypted_data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_members = {
  "pose_msg__msg",  // message namespace
  "ModelPoseArray",  // message name
  4,  // number of fields
  sizeof(pose_msg__msg__ModelPoseArray),
  pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_member_array,  // message members
  pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_init_function,  // function to initialize message memory (memory has to be allocated)
  pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_type_support_handle = {
  0,
  &pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_msg, msg, ModelPoseArray)() {
  pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_msg, msg, ModelPose)();
  if (!pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_type_support_handle.typesupport_identifier) {
    pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pose_msg__msg__ModelPoseArray__rosidl_typesupport_introspection_c__ModelPoseArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
