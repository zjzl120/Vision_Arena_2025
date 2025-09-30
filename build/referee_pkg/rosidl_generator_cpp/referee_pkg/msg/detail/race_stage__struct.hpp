// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from referee_pkg:msg/RaceStage.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__RACE_STAGE__STRUCT_HPP_
#define REFEREE_PKG__MSG__DETAIL__RACE_STAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__referee_pkg__msg__RaceStage __attribute__((deprecated))
#else
# define DEPRECATED__referee_pkg__msg__RaceStage __declspec(deprecated)
#endif

namespace referee_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RaceStage_
{
  using Type = RaceStage_<ContainerAllocator>;

  explicit RaceStage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stage = 0l;
    }
  }

  explicit RaceStage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stage = 0l;
    }
  }

  // field types and members
  using _stage_type =
    int32_t;
  _stage_type stage;

  // setters for named parameter idiom
  Type & set__stage(
    const int32_t & _arg)
  {
    this->stage = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    referee_pkg::msg::RaceStage_<ContainerAllocator> *;
  using ConstRawPtr =
    const referee_pkg::msg::RaceStage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<referee_pkg::msg::RaceStage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<referee_pkg::msg::RaceStage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      referee_pkg::msg::RaceStage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::msg::RaceStage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      referee_pkg::msg::RaceStage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::msg::RaceStage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<referee_pkg::msg::RaceStage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<referee_pkg::msg::RaceStage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__referee_pkg__msg__RaceStage
    std::shared_ptr<referee_pkg::msg::RaceStage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__referee_pkg__msg__RaceStage
    std::shared_ptr<referee_pkg::msg::RaceStage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RaceStage_ & other) const
  {
    if (this->stage != other.stage) {
      return false;
    }
    return true;
  }
  bool operator!=(const RaceStage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RaceStage_

// alias to use template instance with default allocator
using RaceStage =
  referee_pkg::msg::RaceStage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace referee_pkg

#endif  // REFEREE_PKG__MSG__DETAIL__RACE_STAGE__STRUCT_HPP_
