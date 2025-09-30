// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pose_msg:msg/ModelPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_MSG__MSG__DETAIL__MODEL_POSE__STRUCT_HPP_
#define POSE_MSG__MSG__DETAIL__MODEL_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pose_msg__msg__ModelPose __attribute__((deprecated))
#else
# define DEPRECATED__pose_msg__msg__ModelPose __declspec(deprecated)
#endif

namespace pose_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ModelPose_
{
  using Type = ModelPose_<ContainerAllocator>;

  explicit ModelPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit ModelPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_msg::msg::ModelPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_msg::msg::ModelPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_msg::msg::ModelPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_msg::msg::ModelPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_msg::msg::ModelPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_msg::msg::ModelPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_msg::msg::ModelPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_msg::msg::ModelPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_msg::msg::ModelPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_msg::msg::ModelPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_msg__msg__ModelPose
    std::shared_ptr<pose_msg::msg::ModelPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_msg__msg__ModelPose
    std::shared_ptr<pose_msg::msg::ModelPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModelPose_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModelPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModelPose_

// alias to use template instance with default allocator
using ModelPose =
  pose_msg::msg::ModelPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pose_msg

#endif  // POSE_MSG__MSG__DETAIL__MODEL_POSE__STRUCT_HPP_
