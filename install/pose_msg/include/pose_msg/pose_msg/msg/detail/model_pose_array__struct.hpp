// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pose_msg:msg/ModelPoseArray.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__STRUCT_HPP_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'models'
#include "pose_msg/msg/detail/model_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pose_msg__msg__ModelPoseArray __attribute__((deprecated))
#else
# define DEPRECATED__pose_msg__msg__ModelPoseArray __declspec(deprecated)
#endif

namespace pose_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ModelPoseArray_
{
  using Type = ModelPoseArray_<ContainerAllocator>;

  explicit ModelPoseArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_encrypted = false;
    }
  }

  explicit ModelPoseArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_encrypted = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _models_type =
    std::vector<pose_msg::msg::ModelPose_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pose_msg::msg::ModelPose_<ContainerAllocator>>>;
  _models_type models;
  using _is_encrypted_type =
    bool;
  _is_encrypted_type is_encrypted;
  using _encrypted_data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _encrypted_data_type encrypted_data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__models(
    const std::vector<pose_msg::msg::ModelPose_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pose_msg::msg::ModelPose_<ContainerAllocator>>> & _arg)
  {
    this->models = _arg;
    return *this;
  }
  Type & set__is_encrypted(
    const bool & _arg)
  {
    this->is_encrypted = _arg;
    return *this;
  }
  Type & set__encrypted_data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->encrypted_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_msg::msg::ModelPoseArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_msg::msg::ModelPoseArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_msg::msg::ModelPoseArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_msg::msg::ModelPoseArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_msg::msg::ModelPoseArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_msg::msg::ModelPoseArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_msg::msg::ModelPoseArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_msg::msg::ModelPoseArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_msg::msg::ModelPoseArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_msg::msg::ModelPoseArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_msg__msg__ModelPoseArray
    std::shared_ptr<pose_msg::msg::ModelPoseArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_msg__msg__ModelPoseArray
    std::shared_ptr<pose_msg::msg::ModelPoseArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModelPoseArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->models != other.models) {
      return false;
    }
    if (this->is_encrypted != other.is_encrypted) {
      return false;
    }
    if (this->encrypted_data != other.encrypted_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModelPoseArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModelPoseArray_

// alias to use template instance with default allocator
using ModelPoseArray =
  pose_msg::msg::ModelPoseArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pose_msg

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE_ARRAY__STRUCT_HPP_
