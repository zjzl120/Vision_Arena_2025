// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pose_msg:msg/ModelPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pose_msg/msg/detail/model_pose__rosidl_typesupport_introspection_c.h"
#include "pose_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pose_msg/msg/detail/model_pose__functions.h"
#include "pose_msg/msg/detail/model_pose__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_msg__msg__ModelPose__init(message_memory);
}

void pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_fini_function(void * message_memory)
{
  pose_msg__msg__ModelPose__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_member_array[2] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg__msg__ModelPose, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg__msg__ModelPose, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_members = {
  "pose_msg__msg",  // message namespace
  "ModelPose",  // message name
  2,  // number of fields
  sizeof(pose_msg__msg__ModelPose),
  pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_member_array,  // message members
  pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_init_function,  // function to initialize message memory (memory has to be allocated)
  pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_type_support_handle = {
  0,
  &pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_msg, msg, ModelPose)() {
  pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_type_support_handle.typesupport_identifier) {
    pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pose_msg__msg__ModelPose__rosidl_typesupport_introspection_c__ModelPose_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
