// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pose_msg:msg/ModelPose.idl
// generated code does not contain a copyright notice
#include "pose_msg/msg/detail/model_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
pose_msg__msg__ModelPose__init(pose_msg__msg__ModelPose * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    pose_msg__msg__ModelPose__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    pose_msg__msg__ModelPose__fini(msg);
    return false;
  }
  return true;
}

void
pose_msg__msg__ModelPose__fini(pose_msg__msg__ModelPose * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
}

bool
pose_msg__msg__ModelPose__are_equal(const pose_msg__msg__ModelPose * lhs, const pose_msg__msg__ModelPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
pose_msg__msg__ModelPose__copy(
  const pose_msg__msg__ModelPose * input,
  pose_msg__msg__ModelPose * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

pose_msg__msg__ModelPose *
pose_msg__msg__ModelPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pose_msg__msg__ModelPose * msg = (pose_msg__msg__ModelPose *)allocator.allocate(sizeof(pose_msg__msg__ModelPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_msg__msg__ModelPose));
  bool success = pose_msg__msg__ModelPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pose_msg__msg__ModelPose__destroy(pose_msg__msg__ModelPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pose_msg__msg__ModelPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pose_msg__msg__ModelPose__Sequence__init(pose_msg__msg__ModelPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pose_msg__msg__ModelPose * data = NULL;

  if (size) {
    data = (pose_msg__msg__ModelPose *)allocator.zero_allocate(size, sizeof(pose_msg__msg__ModelPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_msg__msg__ModelPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_msg__msg__ModelPose__fini(&data[i - 1]);
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
pose_msg__msg__ModelPose__Sequence__fini(pose_msg__msg__ModelPose__Sequence * array)
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
      pose_msg__msg__ModelPose__fini(&array->data[i]);
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

pose_msg__msg__ModelPose__Sequence *
pose_msg__msg__ModelPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pose_msg__msg__ModelPose__Sequence * array = (pose_msg__msg__ModelPose__Sequence *)allocator.allocate(sizeof(pose_msg__msg__ModelPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pose_msg__msg__ModelPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pose_msg__msg__ModelPose__Sequence__destroy(pose_msg__msg__ModelPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pose_msg__msg__ModelPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pose_msg__msg__ModelPose__Sequence__are_equal(const pose_msg__msg__ModelPose__Sequence * lhs, const pose_msg__msg__ModelPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_msg__msg__ModelPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_msg__msg__ModelPose__Sequence__copy(
  const pose_msg__msg__ModelPose__Sequence * input,
  pose_msg__msg__ModelPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_msg__msg__ModelPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pose_msg__msg__ModelPose * data =
      (pose_msg__msg__ModelPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_msg__msg__ModelPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pose_msg__msg__ModelPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_msg__msg__ModelPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
