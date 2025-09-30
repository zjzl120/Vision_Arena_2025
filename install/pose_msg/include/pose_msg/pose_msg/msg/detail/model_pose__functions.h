// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pose_msg:msg/ModelPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE__FUNCTIONS_H_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pose_msg/msg/rosidl_generator_c__visibility_control.h"

#include "pose_msg/msg/detail/model_pose__struct.h"

/// Initialize msg/ModelPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_msg__msg__ModelPose
 * )) before or use
 * pose_msg__msg__ModelPose__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
bool
pose_msg__msg__ModelPose__init(pose_msg__msg__ModelPose * msg);

/// Finalize msg/ModelPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
void
pose_msg__msg__ModelPose__fini(pose_msg__msg__ModelPose * msg);

/// Create msg/ModelPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_msg__msg__ModelPose__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
pose_msg__msg__ModelPose *
pose_msg__msg__ModelPose__create();

/// Destroy msg/ModelPose message.
/**
 * It calls
 * pose_msg__msg__ModelPose__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
void
pose_msg__msg__ModelPose__destroy(pose_msg__msg__ModelPose * msg);

/// Check for msg/ModelPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
bool
pose_msg__msg__ModelPose__are_equal(const pose_msg__msg__ModelPose * lhs, const pose_msg__msg__ModelPose * rhs);

/// Copy a msg/ModelPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
bool
pose_msg__msg__ModelPose__copy(
  const pose_msg__msg__ModelPose * input,
  pose_msg__msg__ModelPose * output);

/// Initialize array of msg/ModelPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_msg__msg__ModelPose__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
bool
pose_msg__msg__ModelPose__Sequence__init(pose_msg__msg__ModelPose__Sequence * array, size_t size);

/// Finalize array of msg/ModelPose messages.
/**
 * It calls
 * pose_msg__msg__ModelPose__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
void
pose_msg__msg__ModelPose__Sequence__fini(pose_msg__msg__ModelPose__Sequence * array);

/// Create array of msg/ModelPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_msg__msg__ModelPose__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
pose_msg__msg__ModelPose__Sequence *
pose_msg__msg__ModelPose__Sequence__create(size_t size);

/// Destroy array of msg/ModelPose messages.
/**
 * It calls
 * pose_msg__msg__ModelPose__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
void
pose_msg__msg__ModelPose__Sequence__destroy(pose_msg__msg__ModelPose__Sequence * array);

/// Check for msg/ModelPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
bool
pose_msg__msg__ModelPose__Sequence__are_equal(const pose_msg__msg__ModelPose__Sequence * lhs, const pose_msg__msg__ModelPose__Sequence * rhs);

/// Copy an array of msg/ModelPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_msg
bool
pose_msg__msg__ModelPose__Sequence__copy(
  const pose_msg__msg__ModelPose__Sequence * input,
  pose_msg__msg__ModelPose__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE__FUNCTIONS_H_
