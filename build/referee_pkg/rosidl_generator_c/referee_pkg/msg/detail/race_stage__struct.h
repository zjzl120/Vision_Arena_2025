// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from referee_pkg:msg/RaceStage.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__RACE_STAGE__STRUCT_H_
#define REFEREE_PKG__MSG__DETAIL__RACE_STAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RaceStage in the package referee_pkg.
typedef struct referee_pkg__msg__RaceStage
{
  int32_t stage;
} referee_pkg__msg__RaceStage;

// Struct for a sequence of referee_pkg__msg__RaceStage.
typedef struct referee_pkg__msg__RaceStage__Sequence
{
  referee_pkg__msg__RaceStage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} referee_pkg__msg__RaceStage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REFEREE_PKG__MSG__DETAIL__RACE_STAGE__STRUCT_H_
