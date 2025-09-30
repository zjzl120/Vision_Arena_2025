// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from referee_pkg:msg/Object.idl
// generated code does not contain a copyright notice
#include "referee_pkg/msg/detail/object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `corners`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
referee_pkg__msg__Object__init(referee_pkg__msg__Object * msg)
{
  if (!msg) {
    return false;
  }
  // target_type
  if (!rosidl_runtime_c__String__init(&msg->target_type)) {
    referee_pkg__msg__Object__fini(msg);
    return false;
  }
  // corners
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->corners, 0)) {
    referee_pkg__msg__Object__fini(msg);
    return false;
  }
  return true;
}

void
referee_pkg__msg__Object__fini(referee_pkg__msg__Object * msg)
{
  if (!msg) {
    return;
  }
  // target_type
  rosidl_runtime_c__String__fini(&msg->target_type);
  // corners
  geometry_msgs__msg__Point__Sequence__fini(&msg->corners);
}

bool
referee_pkg__msg__Object__are_equal(const referee_pkg__msg__Object * lhs, const referee_pkg__msg__Object * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target_type), &(rhs->target_type)))
  {
    return false;
  }
  // corners
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->corners), &(rhs->corners)))
  {
    return false;
  }
  return true;
}

bool
referee_pkg__msg__Object__copy(
  const referee_pkg__msg__Object * input,
  referee_pkg__msg__Object * output)
{
  if (!input || !output) {
    return false;
  }
  // target_type
  if (!rosidl_runtime_c__String__copy(
      &(input->target_type), &(output->target_type)))
  {
    return false;
  }
  // corners
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->corners), &(output->corners)))
  {
    return false;
  }
  return true;
}

referee_pkg__msg__Object *
referee_pkg__msg__Object__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__Object * msg = (referee_pkg__msg__Object *)allocator.allocate(sizeof(referee_pkg__msg__Object), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(referee_pkg__msg__Object));
  bool success = referee_pkg__msg__Object__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
referee_pkg__msg__Object__destroy(referee_pkg__msg__Object * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    referee_pkg__msg__Object__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
referee_pkg__msg__Object__Sequence__init(referee_pkg__msg__Object__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__Object * data = NULL;

  if (size) {
    data = (referee_pkg__msg__Object *)allocator.zero_allocate(size, sizeof(referee_pkg__msg__Object), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = referee_pkg__msg__Object__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        referee_pkg__msg__Object__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
referee_pkg__msg__Object__Sequence__fini(referee_pkg__msg__Object__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      referee_pkg__msg__Object__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

referee_pkg__msg__Object__Sequence *
referee_pkg__msg__Object__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__Object__Sequence * array = (referee_pkg__msg__Object__Sequence *)allocator.allocate(sizeof(referee_pkg__msg__Object__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = referee_pkg__msg__Object__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
referee_pkg__msg__Object__Sequence__destroy(referee_pkg__msg__Object__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    referee_pkg__msg__Object__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
referee_pkg__msg__Object__Sequence__are_equal(const referee_pkg__msg__Object__Sequence * lhs, const referee_pkg__msg__Object__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!referee_pkg__msg__Object__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
referee_pkg__msg__Object__Sequence__copy(
  const referee_pkg__msg__Object__Sequence * input,
  referee_pkg__msg__Object__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(referee_pkg__msg__Object);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    referee_pkg__msg__Object * data =
      (referee_pkg__msg__Object *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!referee_pkg__msg__Object__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          referee_pkg__msg__Object__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!referee_pkg__msg__Object__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
