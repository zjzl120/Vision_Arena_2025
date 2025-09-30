// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from referee_pkg:srv/HitArror.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "referee_pkg/srv/detail/hit_arror__struct.h"
#include "referee_pkg/srv/detail/hit_arror__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace referee_pkg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _HitArror_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _HitArror_Request_type_support_ids_t;

static const _HitArror_Request_type_support_ids_t _HitArror_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _HitArror_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _HitArror_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _HitArror_Request_type_support_symbol_names_t _HitArror_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, referee_pkg, srv, HitArror_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror_Request)),
  }
};

typedef struct _HitArror_Request_type_support_data_t
{
  void * data[2];
} _HitArror_Request_type_support_data_t;

static _HitArror_Request_type_support_data_t _HitArror_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _HitArror_Request_message_typesupport_map = {
  2,
  "referee_pkg",
  &_HitArror_Request_message_typesupport_ids.typesupport_identifier[0],
  &_HitArror_Request_message_typesupport_symbol_names.symbol_name[0],
  &_HitArror_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t HitArror_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_HitArror_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace referee_pkg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, referee_pkg, srv, HitArror_Request)() {
  return &::referee_pkg::srv::rosidl_typesupport_c::HitArror_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "referee_pkg/srv/detail/hit_arror__struct.h"
// already included above
// #include "referee_pkg/srv/detail/hit_arror__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace referee_pkg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _HitArror_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _HitArror_Response_type_support_ids_t;

static const _HitArror_Response_type_support_ids_t _HitArror_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _HitArror_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _HitArror_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _HitArror_Response_type_support_symbol_names_t _HitArror_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, referee_pkg, srv, HitArror_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror_Response)),
  }
};

typedef struct _HitArror_Response_type_support_data_t
{
  void * data[2];
} _HitArror_Response_type_support_data_t;

static _HitArror_Response_type_support_data_t _HitArror_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _HitArror_Response_message_typesupport_map = {
  2,
  "referee_pkg",
  &_HitArror_Response_message_typesupport_ids.typesupport_identifier[0],
  &_HitArror_Response_message_typesupport_symbol_names.symbol_name[0],
  &_HitArror_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t HitArror_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_HitArror_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace referee_pkg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, referee_pkg, srv, HitArror_Response)() {
  return &::referee_pkg::srv::rosidl_typesupport_c::HitArror_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "referee_pkg/srv/detail/hit_arror__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace referee_pkg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _HitArror_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _HitArror_type_support_ids_t;

static const _HitArror_type_support_ids_t _HitArror_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _HitArror_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _HitArror_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _HitArror_type_support_symbol_names_t _HitArror_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, referee_pkg, srv, HitArror)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, referee_pkg, srv, HitArror)),
  }
};

typedef struct _HitArror_type_support_data_t
{
  void * data[2];
} _HitArror_type_support_data_t;

static _HitArror_type_support_data_t _HitArror_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _HitArror_service_typesupport_map = {
  2,
  "referee_pkg",
  &_HitArror_service_typesupport_ids.typesupport_identifier[0],
  &_HitArror_service_typesupport_symbol_names.symbol_name[0],
  &_HitArror_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t HitArror_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_HitArror_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace referee_pkg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, referee_pkg, srv, HitArror)() {
  return &::referee_pkg::srv::rosidl_typesupport_c::HitArror_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
