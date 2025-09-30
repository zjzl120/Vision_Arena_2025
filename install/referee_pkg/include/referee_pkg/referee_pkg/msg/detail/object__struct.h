// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from referee_pkg:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__OBJECT__STRUCT_H_
#define REFEREE_PKG__MSG__DETAIL__OBJECT__STRUCT_H_

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
// Member 'corners'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Object in the package referee_pkg.
typedef struct referee_pkg__msg__Object
{
  /// 目标类型，如 "armor_1", "circle_red"
  rosidl_runtime_c__String target_type;
  /// 四个角点的像素坐标
  geometry_msgs__msg__Point__Sequence corners;
} referee_pkg__msg__Object;

// Struct for a sequence of referee_pkg__msg__Object.
typedef struct referee_pkg__msg__Object__Sequence
{
  referee_pkg__msg__Object * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} referee_pkg__msg__Object__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REFEREE_PKG__MSG__DETAIL__OBJECT__STRUCT_H_
