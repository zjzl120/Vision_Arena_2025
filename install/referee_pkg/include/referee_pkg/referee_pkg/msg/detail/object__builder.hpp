// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from referee_pkg:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__OBJECT__BUILDER_HPP_
#define REFEREE_PKG__MSG__DETAIL__OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "referee_pkg/msg/detail/object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace referee_pkg
{

namespace msg
{

namespace builder
{

class Init_Object_corners
{
public:
  explicit Init_Object_corners(::referee_pkg::msg::Object & msg)
  : msg_(msg)
  {}
  ::referee_pkg::msg::Object corners(::referee_pkg::msg::Object::_corners_type arg)
  {
    msg_.corners = std::move(arg);
    return std::move(msg_);
  }

private:
  ::referee_pkg::msg::Object msg_;
};

class Init_Object_target_type
{
public:
  Init_Object_target_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Object_corners target_type(::referee_pkg::msg::Object::_target_type_type arg)
  {
    msg_.target_type = std::move(arg);
    return Init_Object_corners(msg_);
  }

private:
  ::referee_pkg::msg::Object msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::referee_pkg::msg::Object>()
{
  return referee_pkg::msg::builder::Init_Object_target_type();
}

}  // namespace referee_pkg

#endif  // REFEREE_PKG__MSG__DETAIL__OBJECT__BUILDER_HPP_
