// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from trajectory_logger:srv/SaveTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "trajectory_logger/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "trajectory_logger/srv/detail/save_trajectory__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace trajectory_logger
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
cdr_serialize(
  const trajectory_logger::srv::SaveTrajectory_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  trajectory_logger::srv::SaveTrajectory_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
get_serialized_size(
  const trajectory_logger::srv::SaveTrajectory_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
max_serialized_size_SaveTrajectory_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace trajectory_logger

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trajectory_logger, srv, SaveTrajectory_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trajectory_logger/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "trajectory_logger/srv/detail/save_trajectory__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace trajectory_logger
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
cdr_serialize(
  const trajectory_logger::srv::SaveTrajectory_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  trajectory_logger::srv::SaveTrajectory_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
get_serialized_size(
  const trajectory_logger::srv::SaveTrajectory_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
max_serialized_size_SaveTrajectory_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace trajectory_logger

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trajectory_logger, srv, SaveTrajectory_Response)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trajectory_logger/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trajectory_logger
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trajectory_logger, srv, SaveTrajectory)();

#ifdef __cplusplus
}
#endif

#endif  // TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
