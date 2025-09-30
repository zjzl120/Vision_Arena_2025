// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pose_msg:msg/ModelPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE__STRUCT_H_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/ModelPose in the package pose_msg.
typedef struct pose_msg__msg__ModelPose
{
  rosidl_runtime_c__String name;
  geometry_msgs__msg__Pose pose;
} pose_msg__msg__ModelPose;

// Struct for a sequence of pose_msg__msg__ModelPose.
typedef struct pose_msg__msg__ModelPose__Sequence
{
  pose_msg__msg__ModelPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_msg__msg__ModelPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE__STRUCT_H_
