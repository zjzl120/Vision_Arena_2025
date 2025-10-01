// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from referee_pkg:srv/HitArmor.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__SRV__DETAIL__HIT_ARMOR__STRUCT_HPP_
#define REFEREE_PKG__SRV__DETAIL__HIT_ARMOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'modelpoint'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__referee_pkg__srv__HitArmor_Request __attribute__((deprecated))
#else
# define DEPRECATED__referee_pkg__srv__HitArmor_Request __declspec(deprecated)
#endif

namespace referee_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct HitArmor_Request_
{
  using Type = HitArmor_Request_<ContainerAllocator>;

  explicit HitArmor_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->g = 0.0;
    }
  }

  explicit HitArmor_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->g = 0.0;
    }
  }

  // field types and members
  using _modelpoint_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _modelpoint_type modelpoint;
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _g_type =
    double;
  _g_type g;

  // setters for named parameter idiom
  Type & set__modelpoint(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->modelpoint = _arg;
    return *this;
  }
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__g(
    const double & _arg)
  {
    this->g = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    referee_pkg::srv::HitArmor_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const referee_pkg::srv::HitArmor_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<referee_pkg::srv::HitArmor_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<referee_pkg::srv::HitArmor_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      referee_pkg::srv::HitArmor_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::srv::HitArmor_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      referee_pkg::srv::HitArmor_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::srv::HitArmor_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<referee_pkg::srv::HitArmor_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<referee_pkg::srv::HitArmor_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__referee_pkg__srv__HitArmor_Request
    std::shared_ptr<referee_pkg::srv::HitArmor_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__referee_pkg__srv__HitArmor_Request
    std::shared_ptr<referee_pkg::srv::HitArmor_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HitArmor_Request_ & other) const
  {
    if (this->modelpoint != other.modelpoint) {
      return false;
    }
    if (this->header != other.header) {
      return false;
    }
    if (this->g != other.g) {
      return false;
    }
    return true;
  }
  bool operator!=(const HitArmor_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HitArmor_Request_

// alias to use template instance with default allocator
using HitArmor_Request =
  referee_pkg::srv::HitArmor_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace referee_pkg


#ifndef _WIN32
# define DEPRECATED__referee_pkg__srv__HitArmor_Response __attribute__((deprecated))
#else
# define DEPRECATED__referee_pkg__srv__HitArmor_Response __declspec(deprecated)
#endif

namespace referee_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct HitArmor_Response_
{
  using Type = HitArmor_Response_<ContainerAllocator>;

  explicit HitArmor_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw = 0.0;
      this->pitch = 0.0;
      this->roll = 0.0;
    }
  }

  explicit HitArmor_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw = 0.0;
      this->pitch = 0.0;
      this->roll = 0.0;
    }
  }

  // field types and members
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _roll_type =
    double;
  _roll_type roll;

  // setters for named parameter idiom
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    referee_pkg::srv::HitArmor_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const referee_pkg::srv::HitArmor_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<referee_pkg::srv::HitArmor_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<referee_pkg::srv::HitArmor_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      referee_pkg::srv::HitArmor_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::srv::HitArmor_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      referee_pkg::srv::HitArmor_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<referee_pkg::srv::HitArmor_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<referee_pkg::srv::HitArmor_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<referee_pkg::srv::HitArmor_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__referee_pkg__srv__HitArmor_Response
    std::shared_ptr<referee_pkg::srv::HitArmor_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__referee_pkg__srv__HitArmor_Response
    std::shared_ptr<referee_pkg::srv::HitArmor_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HitArmor_Response_ & other) const
  {
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    return true;
  }
  bool operator!=(const HitArmor_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HitArmor_Response_

// alias to use template instance with default allocator
using HitArmor_Response =
  referee_pkg::srv::HitArmor_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace referee_pkg

namespace referee_pkg
{

namespace srv
{

struct HitArmor
{
  using Request = referee_pkg::srv::HitArmor_Request;
  using Response = referee_pkg::srv::HitArmor_Response;
};

}  // namespace srv

}  // namespace referee_pkg

#endif  // REFEREE_PKG__SRV__DETAIL__HIT_ARMOR__STRUCT_HPP_
