// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from referee_pkg:srv/HitArror.idl
// generated code does not contain a copyright notice
#include "referee_pkg/srv/detail/hit_arror__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `modelpoint`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
referee_pkg__srv__HitArror_Request__init(referee_pkg__srv__HitArror_Request * msg)
{
  if (!msg) {
    return false;
  }
  // modelpoint
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->modelpoint, 0)) {
    referee_pkg__srv__HitArror_Request__fini(msg);
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    referee_pkg__srv__HitArror_Request__fini(msg);
    return false;
  }
  // g
  return true;
}

void
referee_pkg__srv__HitArror_Request__fini(referee_pkg__srv__HitArror_Request * msg)
{
  if (!msg) {
    return;
  }
  // modelpoint
  geometry_msgs__msg__Point__Sequence__fini(&msg->modelpoint);
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // g
}

bool
referee_pkg__srv__HitArror_Request__are_equal(const referee_pkg__srv__HitArror_Request * lhs, const referee_pkg__srv__HitArror_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // modelpoint
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->modelpoint), &(rhs->modelpoint)))
  {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // g
  if (lhs->g != rhs->g) {
    return false;
  }
  return true;
}

bool
referee_pkg__srv__HitArror_Request__copy(
  const referee_pkg__srv__HitArror_Request * input,
  referee_pkg__srv__HitArror_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // modelpoint
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->modelpoint), &(output->modelpoint)))
  {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // g
  output->g = input->g;
  return true;
}

referee_pkg__srv__HitArror_Request *
referee_pkg__srv__HitArror_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__srv__HitArror_Request * msg = (referee_pkg__srv__HitArror_Request *)allocator.allocate(sizeof(referee_pkg__srv__HitArror_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(referee_pkg__srv__HitArror_Request));
  bool success = referee_pkg__srv__HitArror_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
referee_pkg__srv__HitArror_Request__destroy(referee_pkg__srv__HitArror_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    referee_pkg__srv__HitArror_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
referee_pkg__srv__HitArror_Request__Sequence__init(referee_pkg__srv__HitArror_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__srv__HitArror_Request * data = NULL;

  if (size) {
    data = (referee_pkg__srv__HitArror_Request *)allocator.zero_allocate(size, sizeof(referee_pkg__srv__HitArror_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = referee_pkg__srv__HitArror_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        referee_pkg__srv__HitArror_Request__fini(&data[i - 1]);
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
referee_pkg__srv__HitArror_Request__Sequence__fini(referee_pkg__srv__HitArror_Request__Sequence * array)
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
      referee_pkg__srv__HitArror_Request__fini(&array->data[i]);
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

referee_pkg__srv__HitArror_Request__Sequence *
referee_pkg__srv__HitArror_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__srv__HitArror_Request__Sequence * array = (referee_pkg__srv__HitArror_Request__Sequence *)allocator.allocate(sizeof(referee_pkg__srv__HitArror_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = referee_pkg__srv__HitArror_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
referee_pkg__srv__HitArror_Request__Sequence__destroy(referee_pkg__srv__HitArror_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    referee_pkg__srv__HitArror_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
referee_pkg__srv__HitArror_Request__Sequence__are_equal(const referee_pkg__srv__HitArror_Request__Sequence * lhs, const referee_pkg__srv__HitArror_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!referee_pkg__srv__HitArror_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
referee_pkg__srv__HitArror_Request__Sequence__copy(
  const referee_pkg__srv__HitArror_Request__Sequence * input,
  referee_pkg__srv__HitArror_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(referee_pkg__srv__HitArror_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    referee_pkg__srv__HitArror_Request * data =
      (referee_pkg__srv__HitArror_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!referee_pkg__srv__HitArror_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          referee_pkg__srv__HitArror_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!referee_pkg__srv__HitArror_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
referee_pkg__srv__HitArror_Response__init(referee_pkg__srv__HitArror_Response * msg)
{
  if (!msg) {
    return false;
  }
  // yaw
  // pitch
  // roll
  return true;
}

void
referee_pkg__srv__HitArror_Response__fini(referee_pkg__srv__HitArror_Response * msg)
{
  if (!msg) {
    return;
  }
  // yaw
  // pitch
  // roll
}

bool
referee_pkg__srv__HitArror_Response__are_equal(const referee_pkg__srv__HitArror_Response * lhs, const referee_pkg__srv__HitArror_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  return true;
}

bool
referee_pkg__srv__HitArror_Response__copy(
  const referee_pkg__srv__HitArror_Response * input,
  referee_pkg__srv__HitArror_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // yaw
  output->yaw = input->yaw;
  // pitch
  output->pitch = input->pitch;
  // roll
  output->roll = input->roll;
  return true;
}

referee_pkg__srv__HitArror_Response *
referee_pkg__srv__HitArror_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__srv__HitArror_Response * msg = (referee_pkg__srv__HitArror_Response *)allocator.allocate(sizeof(referee_pkg__srv__HitArror_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(referee_pkg__srv__HitArror_Response));
  bool success = referee_pkg__srv__HitArror_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
referee_pkg__srv__HitArror_Response__destroy(referee_pkg__srv__HitArror_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    referee_pkg__srv__HitArror_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
referee_pkg__srv__HitArror_Response__Sequence__init(referee_pkg__srv__HitArror_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__srv__HitArror_Response * data = NULL;

  if (size) {
    data = (referee_pkg__srv__HitArror_Response *)allocator.zero_allocate(size, sizeof(referee_pkg__srv__HitArror_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = referee_pkg__srv__HitArror_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        referee_pkg__srv__HitArror_Response__fini(&data[i - 1]);
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
referee_pkg__srv__HitArror_Response__Sequence__fini(referee_pkg__srv__HitArror_Response__Sequence * array)
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
      referee_pkg__srv__HitArror_Response__fini(&array->data[i]);
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

referee_pkg__srv__HitArror_Response__Sequence *
referee_pkg__srv__HitArror_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  referee_pkg__srv__HitArror_Response__Sequence * array = (referee_pkg__srv__HitArror_Response__Sequence *)allocator.allocate(sizeof(referee_pkg__srv__HitArror_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = referee_pkg__srv__HitArror_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
referee_pkg__srv__HitArror_Response__Sequence__destroy(referee_pkg__srv__HitArror_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    referee_pkg__srv__HitArror_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
referee_pkg__srv__HitArror_Response__Sequence__are_equal(const referee_pkg__srv__HitArror_Response__Sequence * lhs, const referee_pkg__srv__HitArror_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!referee_pkg__srv__HitArror_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
referee_pkg__srv__HitArror_Response__Sequence__copy(
  const referee_pkg__srv__HitArror_Response__Sequence * input,
  referee_pkg__srv__HitArror_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(referee_pkg__srv__HitArror_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    referee_pkg__srv__HitArror_Response * data =
      (referee_pkg__srv__HitArror_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!referee_pkg__srv__HitArror_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          referee_pkg__srv__HitArror_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!referee_pkg__srv__HitArror_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
