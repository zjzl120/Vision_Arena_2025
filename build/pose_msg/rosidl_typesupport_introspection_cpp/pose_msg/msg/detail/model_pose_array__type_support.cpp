// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from pose_msg:msg/ModelPoseArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "pose_msg/msg/detail/model_pose_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace pose_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ModelPoseArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) pose_msg::msg::ModelPoseArray(_init);
}

void ModelPoseArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<pose_msg::msg::ModelPoseArray *>(message_memory);
  typed_message->~ModelPoseArray();
}

size_t size_function__ModelPoseArray__models(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<pose_msg::msg::ModelPose> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ModelPoseArray__models(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<pose_msg::msg::ModelPose> *>(untyped_member);
  return &member[index];
}

void * get_function__ModelPoseArray__models(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<pose_msg::msg::ModelPose> *>(untyped_member);
  return &member[index];
}

void fetch_function__ModelPoseArray__models(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const pose_msg::msg::ModelPose *>(
    get_const_function__ModelPoseArray__models(untyped_member, index));
  auto & value = *reinterpret_cast<pose_msg::msg::ModelPose *>(untyped_value);
  value = item;
}

void assign_function__ModelPoseArray__models(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<pose_msg::msg::ModelPose *>(
    get_function__ModelPoseArray__models(untyped_member, index));
  const auto & value = *reinterpret_cast<const pose_msg::msg::ModelPose *>(untyped_value);
  item = value;
}

void resize_function__ModelPoseArray__models(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<pose_msg::msg::ModelPose> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ModelPoseArray__encrypted_data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ModelPoseArray__encrypted_data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__ModelPoseArray__encrypted_data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__ModelPoseArray__encrypted_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__ModelPoseArray__encrypted_data(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__ModelPoseArray__encrypted_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__ModelPoseArray__encrypted_data(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__ModelPoseArray__encrypted_data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ModelPoseArray_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg::msg::ModelPoseArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "models",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<pose_msg::msg::ModelPose>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg::msg::ModelPoseArray, models),  // bytes offset in struct
    nullptr,  // default value
    size_function__ModelPoseArray__models,  // size() function pointer
    get_const_function__ModelPoseArray__models,  // get_const(index) function pointer
    get_function__ModelPoseArray__models,  // get(index) function pointer
    fetch_function__ModelPoseArray__models,  // fetch(index, &value) function pointer
    assign_function__ModelPoseArray__models,  // assign(index, value) function pointer
    resize_function__ModelPoseArray__models  // resize(index) function pointer
  },
  {
    "is_encrypted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg::msg::ModelPoseArray, is_encrypted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "encrypted_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_msg::msg::ModelPoseArray, encrypted_data),  // bytes offset in struct
    nullptr,  // default value
    size_function__ModelPoseArray__encrypted_data,  // size() function pointer
    get_const_function__ModelPoseArray__encrypted_data,  // get_const(index) function pointer
    get_function__ModelPoseArray__encrypted_data,  // get(index) function pointer
    fetch_function__ModelPoseArray__encrypted_data,  // fetch(index, &value) function pointer
    assign_function__ModelPoseArray__encrypted_data,  // assign(index, value) function pointer
    resize_function__ModelPoseArray__encrypted_data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ModelPoseArray_message_members = {
  "pose_msg::msg",  // message namespace
  "ModelPoseArray",  // message name
  4,  // number of fields
  sizeof(pose_msg::msg::ModelPoseArray),
  ModelPoseArray_message_member_array,  // message members
  ModelPoseArray_init_function,  // function to initialize message memory (memory has to be allocated)
  ModelPoseArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ModelPoseArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ModelPoseArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace pose_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<pose_msg::msg::ModelPoseArray>()
{
  return &::pose_msg::msg::rosidl_typesupport_introspection_cpp::ModelPoseArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pose_msg, msg, ModelPoseArray)() {
  return &::pose_msg::msg::rosidl_typesupport_introspection_cpp::ModelPoseArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
