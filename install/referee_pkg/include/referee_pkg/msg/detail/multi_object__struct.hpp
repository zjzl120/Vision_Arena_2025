// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from referee_pkg:msg/MultiObject.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__STRUCT_HPP_
#define REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__STRUCT_HPP_

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
// Member 'objects'
#include "referee_pkg/msg/detail/object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__referee_pkg__msg__MultiObject __attribute__((deprecated))
#else
# define DEPRECATED__referee_pkg__msg__MultiObject __declspec(deprecated)
#endif

namespace referee_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MultiObject_
{
  using Type = MultiObject_<ContainerAllocator>;

  explicit MultiObject_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num_objects = 0ul;
    }
  }

  explicit MultiObject_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num_objects = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _objects_type =
    std::vector<referee_pkg::msg::Object_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<referee_pkg::msg::Object_<ContainerAllocator>>>;
  _objects_type objects;
  using _num_objects_type =
    uint32_t;
  _num_objects_type num_objects;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__objects(
    const std::vector<referee_pkg::msg::Object_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<referee_pkg::msg::Object_<ContainerAllocator>>> & _arg)
  {
    this->objects = _arg;
    return *this;
  }
  Type & set__num_objects(
    const uint32_t & _arg)
  {
    this->num_objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    referee_pkg::msg::MultiObject_<ContainerAllocator> *;
  using ConstRawPtr =
    const referee_pkg::msg::MultiObject_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<referee_pkg::msg::MultiObject_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<referee_pkg::msg::MultiObject_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      referee_pkg::msg::MultiObject_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::msg::MultiObject_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      referee_pkg::msg::MultiObject_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::msg::MultiObject_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<referee_pkg::msg::MultiObject_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<referee_pkg::msg::MultiObject_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__referee_pkg__msg__MultiObject
    std::shared_ptr<referee_pkg::msg::MultiObject_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__referee_pkg__msg__MultiObject
    std::shared_ptr<referee_pkg::msg::MultiObject_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MultiObject_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->objects != other.objects) {
      return false;
    }
    if (this->num_objects != other.num_objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const MultiObject_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MultiObject_

// alias to use template instance with default allocator
using MultiObject =
  referee_pkg::msg::MultiObject_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace referee_pkg

#endif  // REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__STRUCT_HPP_
