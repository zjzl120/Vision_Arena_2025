// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from referee_pkg:srv/HitArror.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__SRV__DETAIL__HIT_ARROR__STRUCT_H_
#define REFEREE_PKG__SRV__DETAIL__HIT_ARROR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'modelpoint'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in srv/HitArror in the package referee_pkg.
typedef struct referee_pkg__srv__HitArror_Request
{
  geometry_msgs__msg__Point__Sequence modelpoint;
  std_msgs__msg__Header header;
  float g;
} referee_pkg__srv__HitArror_Request;

// Struct for a sequence of referee_pkg__srv__HitArror_Request.
typedef struct referee_pkg__srv__HitArror_Request__Sequence
{
  referee_pkg__srv__HitArror_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} referee_pkg__srv__HitArror_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/HitArror in the package referee_pkg.
typedef struct referee_pkg__srv__HitArror_Response
{
  float yaw;
  float pitch;
  float roll;
} referee_pkg__srv__HitArror_Response;

// Struct for a sequence of referee_pkg__srv__HitArror_Response.
typedef struct referee_pkg__srv__HitArror_Response__Sequence
{
  referee_pkg__srv__HitArror_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} referee_pkg__srv__HitArror_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REFEREE_PKG__SRV__DETAIL__HIT_ARROR__STRUCT_H_
