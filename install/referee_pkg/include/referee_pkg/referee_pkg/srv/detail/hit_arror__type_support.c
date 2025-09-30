// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from referee_pkg:srv/HitArror.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "referee_pkg/srv/detail/hit_arror__rosidl_typesupport_introspection_c.h"
#include "referee_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "referee_pkg/srv/detail/hit_arror__functions.h"
#include "referee_pkg/srv/detail/hit_arror__struct.h"


// Include directives for member types
// Member `modelpoint`
#include "geometry_msgs/msg/point.h"
// Member `modelpoint`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  referee_pkg__srv__HitArror_Request__init(message_memory);
}

void referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_fini_function(void * message_memory)
{
  referee_pkg__srv__HitArror_Request__fini(message_memory);
}

size_t referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__size_function__HitArror_Request__modelpoint(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__get_const_function__HitArror_Request__modelpoint(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__get_function__HitArror_Request__modelpoint(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__fetch_function__HitArror_Request__modelpoint(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__get_const_function__HitArror_Request__modelpoint(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__assign_function__HitArror_Request__modelpoint(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__get_function__HitArror_Request__modelpoint(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__resize_function__HitArror_Request__modelpoint(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_member_array[3] = {
  {
    "modelpoint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__srv__HitArror_Request, modelpoint),  // bytes offset in struct
    NULL,  // default value
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__size_function__HitArror_Request__modelpoint,  // size() function pointer
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__get_const_function__HitArror_Request__modelpoint,  // get_const(index) function pointer
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__get_function__HitArror_Request__modelpoint,  // get(index) function pointer
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__fetch_function__HitArror_Request__modelpoint,  // fetch(index, &value) function pointer
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__assign_function__HitArror_Request__modelpoint,  // assign(index, value) function pointer
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__resize_function__HitArror_Request__modelpoint  // resize(index) function pointer
  },
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__srv__HitArror_Request, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "g",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__srv__HitArror_Request, g),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_members = {
  "referee_pkg__srv",  // message namespace
  "HitArror_Request",  // message name
  3,  // number of fields
  sizeof(referee_pkg__srv__HitArror_Request),
  referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_member_array,  // message members
  referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_type_support_handle = {
  0,
  &referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_referee_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror_Request)() {
  referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_type_support_handle.typesupport_identifier) {
    referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &referee_pkg__srv__HitArror_Request__rosidl_typesupport_introspection_c__HitArror_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "referee_pkg/srv/detail/hit_arror__rosidl_typesupport_introspection_c.h"
// already included above
// #include "referee_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "referee_pkg/srv/detail/hit_arror__functions.h"
// already included above
// #include "referee_pkg/srv/detail/hit_arror__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  referee_pkg__srv__HitArror_Response__init(message_memory);
}

void referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_fini_function(void * message_memory)
{
  referee_pkg__srv__HitArror_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_message_member_array[3] = {
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__srv__HitArror_Response, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__srv__HitArror_Response, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(referee_pkg__srv__HitArror_Response, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_message_members = {
  "referee_pkg__srv",  // message namespace
  "HitArror_Response",  // message name
  3,  // number of fields
  sizeof(referee_pkg__srv__HitArror_Response),
  referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_message_member_array,  // message members
  referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_message_type_support_handle = {
  0,
  &referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_referee_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror_Response)() {
  if (!referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_message_type_support_handle.typesupport_identifier) {
    referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &referee_pkg__srv__HitArror_Response__rosidl_typesupport_introspection_c__HitArror_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "referee_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "referee_pkg/srv/detail/hit_arror__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_service_members = {
  "referee_pkg__srv",  // service namespace
  "HitArror",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_Request_message_type_support_handle,
  NULL  // response message
  // referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_Response_message_type_support_handle
};

static rosidl_service_type_support_t referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_service_type_support_handle = {
  0,
  &referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_referee_pkg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror)() {
  if (!referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_service_type_support_handle.typesupport_identifier) {
    referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror_Response)()->data;
  }

  return &referee_pkg__srv__detail__hit_arror__rosidl_typesupport_introspection_c__HitArror_service_type_support_handle;
}
