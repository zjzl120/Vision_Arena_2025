// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from referee_pkg:msg/MultiObject.idl
// generated code does not contain a copyright notice
#include "referee_pkg/msg/detail/multi_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `objects`
#include "referee_pkg/msg/detail/object__functions.h"

bool
referee_pkg__msg__MultiObject__init(referee_pkg__msg__MultiObject * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    referee_pkg__msg__MultiObject__fini(msg);
    return false;
  }
  // objects
  if (!referee_pkg__msg__Object__Sequence__init(&msg->objects, 0)) {
    referee_pkg__msg__MultiObject__fini(msg);
    return false;
  }
  // num_objects
  return true;
}

void
referee_pkg__msg__MultiObject__fini(referee_pkg__msg__MultiObject * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // objects
  referee_pkg__msg__Object__Sequence__fini(&msg->objects);
  // num_objects
}

bool
referee_pkg__msg__MultiObject__are_equal(const referee_pkg__msg__MultiObject * lhs, const referee_pkg__msg__MultiObject * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // objects
  if (!referee_pkg__msg__Object__Sequence__are_equal(
      &(lhs->objects), &(rhs->objects)))
  {
    return false;
  }
  // num_objects
  if (lhs->num_objects != rhs->num_objects) {
    return false;
  }
  return true;
}

bool
referee_pkg__msg__MultiObject__copy(
  const referee_pkg__msg__MultiObject * input,
  referee_pkg__msg__MultiObject * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // objects
  if (!referee_pkg__msg__Object__Sequence__copy(
      &(input->objects), &(output->objects)))
  {
    return false;
  }
  // num_objects
  output->num_objects = input->num_objects;
  return true;
}

referee_pkg__msg__MultiObject *
referee_pkg__msg__MultiObject__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__MultiObject * msg = (referee_pkg__msg__MultiObject *)allocator.allocate(sizeof(referee_pkg__msg__MultiObject), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(referee_pkg__msg__MultiObject));
  bool success = referee_pkg__msg__MultiObject__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
referee_pkg__msg__MultiObject__destroy(referee_pkg__msg__MultiObject * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    referee_pkg__msg__MultiObject__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
referee_pkg__msg__MultiObject__Sequence__init(referee_pkg__msg__MultiObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__MultiObject * data = NULL;

  if (size) {
    data = (referee_pkg__msg__MultiObject *)allocator.zero_allocate(size, sizeof(referee_pkg__msg__MultiObject), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = referee_pkg__msg__MultiObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        referee_pkg__msg__MultiObject__fini(&data[i - 1]);
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
referee_pkg__msg__MultiObject__Sequence__fini(referee_pkg__msg__MultiObject__Sequence * array)
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
      referee_pkg__msg__MultiObject__fini(&array->data[i]);
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

referee_pkg__msg__MultiObject__Sequence *
referee_pkg__msg__MultiObject__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__msg__MultiObject__Sequence * array = (referee_pkg__msg__MultiObject__Sequence *)allocator.allocate(sizeof(referee_pkg__msg__MultiObject__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = referee_pkg__msg__MultiObject__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
referee_pkg__msg__MultiObject__Sequence__destroy(referee_pkg__msg__MultiObject__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    referee_pkg__msg__MultiObject__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
referee_pkg__msg__MultiObject__Sequence__are_equal(const referee_pkg__msg__MultiObject__Sequence * lhs, const referee_pkg__msg__MultiObject__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!referee_pkg__msg__MultiObject__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
referee_pkg__msg__MultiObject__Sequence__copy(
  const referee_pkg__msg__MultiObject__Sequence * input,
  referee_pkg__msg__MultiObject__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(referee_pkg__msg__MultiObject);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    referee_pkg__msg__MultiObject * data =
      (referee_pkg__msg__MultiObject *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!referee_pkg__msg__MultiObject__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          referee_pkg__msg__MultiObject__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!referee_pkg__msg__MultiObject__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
