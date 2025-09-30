// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from referee_pkg:msg/RaceStage.idl
// generated code does not contain a copyright notice

#ifndef REFEREE_PKG__MSG__DETAIL__RACE_STAGE__BUILDER_HPP_
#define REFEREE_PKG__MSG__DETAIL__RACE_STAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "referee_pkg/msg/detail/race_stage__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace referee_pkg
{

namespace msg
{

namespace builder
{

class Init_RaceStage_stage
{
public:
  Init_RaceStage_stage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::referee_pkg::msg::RaceStage stage(::referee_pkg::msg::RaceStage::_stage_type arg)
  {
    msg_.stage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::referee_pkg::msg::RaceStage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::referee_pkg::msg::RaceStage>()
{
  return referee_pkg::msg::builder::Init_RaceStage_stage();
}

}  // namespace referee_pkg

#endif  // REFEREE_PKG__MSG__DETAIL__RACE_STAGE__BUILDER_HPP_
