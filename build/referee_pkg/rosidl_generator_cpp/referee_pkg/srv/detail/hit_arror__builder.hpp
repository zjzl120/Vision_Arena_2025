// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from referee_pkg:srv/HitArror.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__SRV__DETAIL__HIT_ARROR__BUILDER_HPP_
#define REFEREE_PKG__SRV__DETAIL__HIT_ARROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "referee_pkg/srv/detail/hit_arror__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace referee_pkg
{

namespace srv
{

namespace builder
{

class Init_HitArror_Request_g
{
public:
  explicit Init_HitArror_Request_g(::referee_pkg::srv::HitArror_Request & msg)
  : msg_(msg)
  {}
  ::referee_pkg::srv::HitArror_Request g(::referee_pkg::srv::HitArror_Request::_g_type arg)
  {
    msg_.g = std::move(arg);
    return std::move(msg_);
  }

private:
  ::referee_pkg::srv::HitArror_Request msg_;
};

class Init_HitArror_Request_header
{
public:
  explicit Init_HitArror_Request_header(::referee_pkg::srv::HitArror_Request & msg)
  : msg_(msg)
  {}
  Init_HitArror_Request_g header(::referee_pkg::srv::HitArror_Request::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HitArror_Request_g(msg_);
  }

private:
  ::referee_pkg::srv::HitArror_Request msg_;
};

class Init_HitArror_Request_modelpoint
{
public:
  Init_HitArror_Request_modelpoint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HitArror_Request_header modelpoint(::referee_pkg::srv::HitArror_Request::_modelpoint_type arg)
  {
    msg_.modelpoint = std::move(arg);
    return Init_HitArror_Request_header(msg_);
  }

private:
  ::referee_pkg::srv::HitArror_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::referee_pkg::srv::HitArror_Request>()
{
  return referee_pkg::srv::builder::Init_HitArror_Request_modelpoint();
}

}  // namespace referee_pkg


namespace referee_pkg
{

namespace srv
{

namespace builder
{

class Init_HitArror_Response_roll
{
public:
  explicit Init_HitArror_Response_roll(::referee_pkg::srv::HitArror_Response & msg)
  : msg_(msg)
  {}
  ::referee_pkg::srv::HitArror_Response roll(::referee_pkg::srv::HitArror_Response::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return std::move(msg_);
  }

private:
  ::referee_pkg::srv::HitArror_Response msg_;
};

class Init_HitArror_Response_pitch
{
public:
  explicit Init_HitArror_Response_pitch(::referee_pkg::srv::HitArror_Response & msg)
  : msg_(msg)
  {}
  Init_HitArror_Response_roll pitch(::referee_pkg::srv::HitArror_Response::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_HitArror_Response_roll(msg_);
  }

private:
  ::referee_pkg::srv::HitArror_Response msg_;
};

class Init_HitArror_Response_yaw
{
public:
  Init_HitArror_Response_yaw()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HitArror_Response_pitch yaw(::referee_pkg::srv::HitArror_Response::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_HitArror_Response_pitch(msg_);
  }

private:
  ::referee_pkg::srv::HitArror_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::referee_pkg::srv::HitArror_Response>()
{
  return referee_pkg::srv::builder::Init_HitArror_Response_yaw();
}

}  // namespace referee_pkg

#endif  // REFEREE_PKG__SRV__DETAIL__HIT_ARROR__BUILDER_HPP_
