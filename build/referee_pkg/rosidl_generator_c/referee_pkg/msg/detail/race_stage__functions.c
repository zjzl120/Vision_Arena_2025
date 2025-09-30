// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from referee_pkg:msg/RaceStage.idl
// generated code does not contain a copyright notice
#include "referee_pkg/msg/detail/race_stage__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
referee_pkg__msg__RaceStage__init(referee_pkg__msg__RaceStage * msg)
{
  if (!msg) {
    return false;
  }
  // stage
  return true;
}

void
referee_pkg__msg__RaceStage__fini(referee_pkg__msg__RaceStage * msg)
{
  if (!msg) {
    return;
  }
  // stage
}

bool
referee_pkg__msg__RaceStage__are_equal(const referee_pkg__msg__RaceStage * lhs, const referee_pkg__msg__RaceStage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stage
  if (lhs->stage != rhs->stage) {
    return false;
  }
  return true;
}

bool
referee_pkg__msg__RaceStage__copy(
  const referee_pkg__msg__RaceStage * input,
  referee_pkg__msg__RaceStage * output)
{
  if (!input || !output) {
    return false;
  }
  // stage
  output->stage = input->stage;
  return true;
}

referee_pkg__msg__RaceStage *
referee_pkg__msg__RaceStage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__RaceStage * msg = (referee_pkg__msg__RaceStage *)allocator.allocate(sizeof(referee_pkg__msg__RaceStage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(referee_pkg__msg__RaceStage));
  bool success = referee_pkg__msg__RaceStage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
referee_pkg__msg__RaceStage__destroy(referee_pkg__msg__RaceStage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    referee_pkg__msg__RaceStage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
referee_pkg__msg__RaceStage__Sequence__init(referee_pkg__msg__RaceStage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__RaceStage * data = NULL;

  if (size) {
    data = (referee_pkg__msg__RaceStage *)allocator.zero_allocate(size, sizeof(referee_pkg__msg__RaceStage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = referee_pkg__msg__RaceStage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        referee_pkg__msg__RaceStage__fini(&data[i - 1]);
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
referee_pkg__msg__RaceStage__Sequence__fini(referee_pkg__msg__RaceStage__Sequence * array)
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
      referee_pkg__msg__RaceStage__fini(&array->data[i]);
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

referee_pkg__msg__RaceStage__Sequence *
referee_pkg__msg__RaceStage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__RaceStage__Sequence * array = (referee_pkg__msg__RaceStage__Sequence *)allocator.allocate(sizeof(referee_pkg__msg__RaceStage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = referee_pkg__msg__RaceStage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
referee_pkg__msg__RaceStage__Sequence__destroy(referee_pkg__msg__RaceStage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    referee_pkg__msg__RaceStage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
referee_pkg__msg__RaceStage__Sequence__are_equal(const referee_pkg__msg__RaceStage__Sequence * lhs, const referee_pkg__msg__RaceStage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!referee_pkg__msg__RaceStage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
referee_pkg__msg__RaceStage__Sequence__copy(
  const referee_pkg__msg__RaceStage__Sequence * input,
  referee_pkg__msg__RaceStage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(referee_pkg__msg__RaceStage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    referee_pkg__msg__RaceStage * data =
      (referee_pkg__msg__RaceStage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!referee_pkg__msg__RaceStage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          referee_pkg__msg__RaceStage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!referee_pkg__msg__RaceStage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
