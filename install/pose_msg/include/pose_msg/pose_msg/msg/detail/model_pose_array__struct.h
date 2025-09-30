// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pose_msg:msg/ModelPoseArray.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__STRUCT_H_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'models'
#include "pose_msg/msg/detail/model_pose__struct.h"
// Member 'encrypted_data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ModelPoseArray in the package pose_msg.
typedef struct pose_msg__msg__ModelPoseArray
{
  std_msgs__msg__Header header;
  pose_msg__msg__ModelPose__Sequence models;
  /// 添加加密相关字段
  bool is_encrypted;
  rosidl_runtime_c__uint8__Sequence encrypted_data;
} pose_msg__msg__ModelPoseArray;

// Struct for a sequence of pose_msg__msg__ModelPoseArray.
typedef struct pose_msg__msg__ModelPoseArray__Sequence
{
  pose_msg__msg__ModelPoseArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_msg__msg__ModelPoseArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__STRUCT_H_
