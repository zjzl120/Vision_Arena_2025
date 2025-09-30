// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from referee_pkg:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__TARGET__STRUCT_H_
#define REFEREE_PKG__MSG__DETAIL__TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Target in the package referee_pkg.
typedef struct referee_pkg__msg__Target
{
  /// 如 "armor_1", "circle_red"
  rosidl_runtime_c__String target_type;
  /// 世界坐标系下的x
  float x;
  /// 世界坐标系下的y
  float y;
  /// 世界坐标系下的z
  float z;
  /// 置信度
  float confidence;
} referee_pkg__msg__Target;

// Struct for a sequence of referee_pkg__msg__Target.
typedef struct referee_pkg__msg__Target__Sequence
{
  referee_pkg__msg__Target * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} referee_pkg__msg__Target__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REFEREE_PKG__MSG__DETAIL__TARGET__STRUCT_H_
