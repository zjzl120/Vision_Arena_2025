// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pose_msg:msg/ModelPoseArray.idl
// generated code does not contain a copyright notice
#include "pose_msg/msg/detail/model_pose_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `models`
#include "pose_msg/msg/detail/model_pose__functions.h"
// Member `encrypted_data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
pose_msg__msg__ModelPoseArray__init(pose_msg__msg__ModelPoseArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pose_msg__msg__ModelPoseArray__fini(msg);
    return false;
  }
  // models
  if (!pose_msg__msg__ModelPose__Sequence__init(&msg->models, 0)) {
    pose_msg__msg__ModelPoseArray__fini(msg);
    return false;
  }
  // is_encrypted
  // encrypted_data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->encrypted_data, 0)) {
    pose_msg__msg__ModelPoseArray__fini(msg);
    return false;
  }
  return true;
}

void
pose_msg__msg__ModelPoseArray__fini(pose_msg__msg__ModelPoseArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // models
  pose_msg__msg__ModelPose__Sequence__fini(&msg->models);
  // is_encrypted
  // encrypted_data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->encrypted_data);
}

bool
pose_msg__msg__ModelPoseArray__are_equal(const pose_msg__msg__ModelPoseArray * lhs, const pose_msg__msg__ModelPoseArray * rhs)
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
  // models
  if (!pose_msg__msg__ModelPose__Sequence__are_equal(
      &(lhs->models), &(rhs->models)))
  {
    return false;
  }
  // is_encrypted
  if (lhs->is_encrypted != rhs->is_encrypted) {
    return false;
  }
  // encrypted_data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->encrypted_data), &(rhs->encrypted_data)))
  {
    return false;
  }
  return true;
}

bool
pose_msg__msg__ModelPoseArray__copy(
  const pose_msg__msg__ModelPoseArray * input,
  pose_msg__msg__ModelPoseArray * output)
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
  // models
  if (!pose_msg__msg__ModelPose__Sequence__copy(
      &(input->models), &(output->models)))
  {
    return false;
  }
  // is_encrypted
  output->is_encrypted = input->is_encrypted;
  // encrypted_data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->encrypted_data), &(output->encrypted_data)))
  {
    return false;
  }
  return true;
}

pose_msg__msg__ModelPoseArray *
pose_msg__msg__ModelPoseArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pose_msg__msg__ModelPoseArray * msg = (pose_msg__msg__ModelPoseArray *)allocator.allocate(sizeof(pose_msg__msg__ModelPoseArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_msg__msg__ModelPoseArray));
  bool success = pose_msg__msg__ModelPoseArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pose_msg__msg__ModelPoseArray__destroy(pose_msg__msg__ModelPoseArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pose_msg__msg__ModelPoseArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pose_msg__msg__ModelPoseArray__Sequence__init(pose_msg__msg__ModelPoseArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pose_msg__msg__ModelPoseArray * data = NULL;

  if (size) {
    data = (pose_msg__msg__ModelPoseArray *)allocator.zero_allocate(size, sizeof(pose_msg__msg__ModelPoseArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_msg__msg__ModelPoseArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_msg__msg__ModelPoseArray__fini(&data[i - 1]);
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
pose_msg__msg__ModelPoseArray__Sequence__fini(pose_msg__msg__ModelPoseArray__Sequence * array)
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
      pose_msg__msg__ModelPoseArray__fini(&array->data[i]);
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

pose_msg__msg__ModelPoseArray__Sequence *
pose_msg__msg__ModelPoseArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pose_msg__msg__ModelPoseArray__Sequence * array = (pose_msg__msg__ModelPoseArray__Sequence *)allocator.allocate(sizeof(pose_msg__msg__ModelPoseArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pose_msg__msg__ModelPoseArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pose_msg__msg__ModelPoseArray__Sequence__destroy(pose_msg__msg__ModelPoseArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pose_msg__msg__ModelPoseArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pose_msg__msg__ModelPoseArray__Sequence__are_equal(const pose_msg__msg__ModelPoseArray__Sequence * lhs, const pose_msg__msg__ModelPoseArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_msg__msg__ModelPoseArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_msg__msg__ModelPoseArray__Sequence__copy(
  const pose_msg__msg__ModelPoseArray__Sequence * input,
  pose_msg__msg__ModelPoseArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_msg__msg__ModelPoseArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pose_msg__msg__ModelPoseArray * data =
      (pose_msg__msg__ModelPoseArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_msg__msg__ModelPoseArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pose_msg__msg__ModelPoseArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_msg__msg__ModelPoseArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
