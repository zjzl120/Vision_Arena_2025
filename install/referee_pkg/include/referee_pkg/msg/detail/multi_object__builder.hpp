// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from referee_pkg:msg/MultiObject.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__BUILDER_HPP_
#define REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "referee_pkg/msg/detail/multi_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace referee_pkg
{

namespace msg
{

namespace builder
{

class Init_MultiObject_num_objects
{
public:
  explicit Init_MultiObject_num_objects(::referee_pkg::msg::MultiObject & msg)
  : msg_(msg)
  {}
  ::referee_pkg::msg::MultiObject num_objects(::referee_pkg::msg::MultiObject::_num_objects_type arg)
  {
    msg_.num_objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::referee_pkg::msg::MultiObject msg_;
};

class Init_MultiObject_objects
{
public:
  explicit Init_MultiObject_objects(::referee_pkg::msg::MultiObject & msg)
  : msg_(msg)
  {}
  Init_MultiObject_num_objects objects(::referee_pkg::msg::MultiObject::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return Init_MultiObject_num_objects(msg_);
  }

private:
  ::referee_pkg::msg::MultiObject msg_;
};

class Init_MultiObject_header
{
public:
  Init_MultiObject_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiObject_objects header(::referee_pkg::msg::MultiObject::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MultiObject_objects(msg_);
  }

private:
  ::referee_pkg::msg::MultiObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::referee_pkg::msg::MultiObject>()
{
  return referee_pkg::msg::builder::Init_MultiObject_header();
}

}  // namespace referee_pkg

#endif  // REFEREE_PKG__MSG__DETAIL__MULTI_OBJECT__BUILDER_HPP_
