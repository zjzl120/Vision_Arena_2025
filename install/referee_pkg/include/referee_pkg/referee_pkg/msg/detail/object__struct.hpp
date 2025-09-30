// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from referee_pkg:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__OBJECT__STRUCT_HPP_
#define REFEREE_PKG__MSG__DETAIL__OBJECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'corners'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__referee_pkg__msg__Object __attribute__((deprecated))
#else
# define DEPRECATED__referee_pkg__msg__Object __declspec(deprecated)
#endif

namespace referee_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Object_
{
  using Type = Object_<ContainerAllocator>;

  explicit Object_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_type = "";
    }
  }

  explicit Object_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_type = "";
    }
  }

  // field types and members
  using _target_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_type_type target_type;
  using _corners_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _corners_type corners;

  // setters for named parameter idiom
  Type & set__target_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target_type = _arg;
    return *this;
  }
  Type & set__corners(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->corners = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    referee_pkg::msg::Object_<ContainerAllocator> *;
  using ConstRawPtr =
    const referee_pkg::msg::Object_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<referee_pkg::msg::Object_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<referee_pkg::msg::Object_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      referee_pkg::msg::Object_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::msg::Object_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      referee_pkg::msg::Object_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::msg::Object_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<referee_pkg::msg::Object_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<referee_pkg::msg::Object_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__referee_pkg__msg__Object
    std::shared_ptr<referee_pkg::msg::Object_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__referee_pkg__msg__Object
    std::shared_ptr<referee_pkg::msg::Object_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Object_ & other) const
  {
    if (this->target_type != other.target_type) {
      return false;
    }
    if (this->corners != other.corners) {
      return false;
    }
    return true;
  }
  bool operator!=(const Object_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Object_

// alias to use template instance with default allocator
using Object =
  referee_pkg::msg::Object_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace referee_pkg

#endif  // REFEREE_PKG__MSG__DETAIL__OBJECT__STRUCT_HPP_
