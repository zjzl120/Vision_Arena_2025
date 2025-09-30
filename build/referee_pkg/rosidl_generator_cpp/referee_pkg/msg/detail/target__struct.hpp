// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from referee_pkg:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__TARGET__STRUCT_HPP_
#define REFEREE_PKG__MSG__DETAIL__TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__referee_pkg__msg__Target __attribute__((deprecated))
#else
# define DEPRECATED__referee_pkg__msg__Target __declspec(deprecated)
#endif

namespace referee_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Target_
{
  using Type = Target_<ContainerAllocator>;

  explicit Target_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_type = "";
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->confidence = 0.0f;
    }
  }

  explicit Target_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_type = "";
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->confidence = 0.0f;
    }
  }

  // field types and members
  using _target_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_type_type target_type;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _confidence_type =
    float;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__target_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target_type = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    referee_pkg::msg::Target_<ContainerAllocator> *;
  using ConstRawPtr =
    const referee_pkg::msg::Target_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<referee_pkg::msg::Target_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<referee_pkg::msg::Target_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      referee_pkg::msg::Target_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::msg::Target_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      referee_pkg::msg::Target_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::msg::Target_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<referee_pkg::msg::Target_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<referee_pkg::msg::Target_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__referee_pkg__msg__Target
    std::shared_ptr<referee_pkg::msg::Target_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__referee_pkg__msg__Target
    std::shared_ptr<referee_pkg::msg::Target_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Target_ & other) const
  {
    if (this->target_type != other.target_type) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const Target_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Target_

// alias to use template instance with default allocator
using Target =
  referee_pkg::msg::Target_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace referee_pkg

#endif  // REFEREE_PKG__MSG__DETAIL__TARGET__STRUCT_HPP_
