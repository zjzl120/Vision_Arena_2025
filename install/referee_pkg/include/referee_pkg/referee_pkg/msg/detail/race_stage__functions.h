// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from referee_pkg:msg/RaceStage.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__RACE_STAGE__FUNCTIONS_H_
#define REFEREE_PKG__MSG__DETAIL__RACE_STAGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "referee_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "referee_pkg/msg/detail/race_stage__struct.h"

/// Initialize msg/RaceStage message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * referee_pkg__msg__RaceStage
 * )) before or use
 * referee_pkg__msg__RaceStage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
bool
referee_pkg__msg__RaceStage__init(referee_pkg__msg__RaceStage * msg);

/// Finalize msg/RaceStage message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
void
referee_pkg__msg__RaceStage__fini(referee_pkg__msg__RaceStage * msg);

/// Create msg/RaceStage message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * referee_pkg__msg__RaceStage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
referee_pkg__msg__RaceStage *
referee_pkg__msg__RaceStage__create();

/// Destroy msg/RaceStage message.
/**
 * It calls
 * referee_pkg__msg__RaceStage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
void
referee_pkg__msg__RaceStage__destroy(referee_pkg__msg__RaceStage * msg);

/// Check for msg/RaceStage message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
bool
referee_pkg__msg__RaceStage__are_equal(const referee_pkg__msg__RaceStage * lhs, const referee_pkg__msg__RaceStage * rhs);

/// Copy a msg/RaceStage message.
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
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
bool
referee_pkg__msg__RaceStage__copy(
  const referee_pkg__msg__RaceStage * input,
  referee_pkg__msg__RaceStage * output);

/// Initialize array of msg/RaceStage messages.
/**
 * It allocates the memory for the number of elements and calls
 * referee_pkg__msg__RaceStage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
bool
referee_pkg__msg__RaceStage__Sequence__init(referee_pkg__msg__RaceStage__Sequence * array, size_t size);

/// Finalize array of msg/RaceStage messages.
/**
 * It calls
 * referee_pkg__msg__RaceStage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
void
referee_pkg__msg__RaceStage__Sequence__fini(referee_pkg__msg__RaceStage__Sequence * array);

/// Create array of msg/RaceStage messages.
/**
 * It allocates the memory for the array and calls
 * referee_pkg__msg__RaceStage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
referee_pkg__msg__RaceStage__Sequence *
referee_pkg__msg__RaceStage__Sequence__create(size_t size);

/// Destroy array of msg/RaceStage messages.
/**
 * It calls
 * referee_pkg__msg__RaceStage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
void
referee_pkg__msg__RaceStage__Sequence__destroy(referee_pkg__msg__RaceStage__Sequence * array);

/// Check for msg/RaceStage message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
bool
referee_pkg__msg__RaceStage__Sequence__are_equal(const referee_pkg__msg__RaceStage__Sequence * lhs, const referee_pkg__msg__RaceStage__Sequence * rhs);

/// Copy an array of msg/RaceStage messages.
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
ROSIDL_GENERATOR_C_PUBLIC_referee_pkg
bool
referee_pkg__msg__RaceStage__Sequence__copy(
  const referee_pkg__msg__RaceStage__Sequence * input,
  referee_pkg__msg__RaceStage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // REFEREE_PKG__MSG__DETAIL__RACE_STAGE__FUNCTIONS_H_
