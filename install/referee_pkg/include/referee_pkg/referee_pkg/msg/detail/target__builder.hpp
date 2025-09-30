// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from referee_pkg:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__TARGET__BUILDER_HPP_
#define REFEREE_PKG__MSG__DETAIL__TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "referee_pkg/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace referee_pkg
{

namespace msg
{

namespace builder
{

class Init_Target_confidence
{
public:
  explicit Init_Target_confidence(::referee_pkg::msg::Target & msg)
  : msg_(msg)
  {}
  ::referee_pkg::msg::Target confidence(::referee_pkg::msg::Target::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::referee_pkg::msg::Target msg_;
};

class Init_Target_z
{
public:
  explicit Init_Target_z(::referee_pkg::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_confidence z(::referee_pkg::msg::Target::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Target_confidence(msg_);
  }

private:
  ::referee_pkg::msg::Target msg_;
};

class Init_Target_y
{
public:
  explicit Init_Target_y(::referee_pkg::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_z y(::referee_pkg::msg::Target::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Target_z(msg_);
  }

private:
  ::referee_pkg::msg::Target msg_;
};

class Init_Target_x
{
public:
  explicit Init_Target_x(::referee_pkg::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_y x(::referee_pkg::msg::Target::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Target_y(msg_);
  }

private:
  ::referee_pkg::msg::Target msg_;
};

class Init_Target_target_type
{
public:
  Init_Target_target_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Target_x target_type(::referee_pkg::msg::Target::_target_type_type arg)
  {
    msg_.target_type = std::move(arg);
    return Init_Target_x(msg_);
  }

private:
  ::referee_pkg::msg::Target msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::referee_pkg::msg::Target>()
{
  return referee_pkg::msg::builder::Init_Target_target_type();
}

}  // namespace referee_pkg

#endif  // REFEREE_PKG__MSG__DETAIL__TARGET__BUILDER_HPP_
