// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from referee_pkg:msg/MultiObject.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__STRUCT_H_
#define REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__STRUCT_H_

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
// Member 'objects'
#include "referee_pkg/msg/detail/object__struct.h"

/// Struct defined in msg/MultiObject in the package referee_pkg.
typedef struct referee_pkg__msg__MultiObject
{
  std_msgs__msg__Header header;
  /// 多个物体数组
  referee_pkg__msg__Object__Sequence objects;
  /// 物体数量
  uint32_t num_objects;
} referee_pkg__msg__MultiObject;

// Struct for a sequence of referee_pkg__msg__MultiObject.
typedef struct referee_pkg__msg__MultiObject__Sequence
{
  referee_pkg__msg__MultiObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} referee_pkg__msg__MultiObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__STRUCT_H_
