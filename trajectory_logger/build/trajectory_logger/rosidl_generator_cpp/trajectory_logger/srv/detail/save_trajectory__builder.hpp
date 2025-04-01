// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trajectory_logger:srv/SaveTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__BUILDER_HPP_
#define TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "trajectory_logger/srv/detail/save_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace trajectory_logger
{

namespace srv
{

namespace builder
{

class Init_SaveTrajectory_Request_duration
{
public:
  explicit Init_SaveTrajectory_Request_duration(::trajectory_logger::srv::SaveTrajectory_Request & msg)
  : msg_(msg)
  {}
  ::trajectory_logger::srv::SaveTrajectory_Request duration(::trajectory_logger::srv::SaveTrajectory_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_logger::srv::SaveTrajectory_Request msg_;
};

class Init_SaveTrajectory_Request_filename
{
public:
  Init_SaveTrajectory_Request_filename()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveTrajectory_Request_duration filename(::trajectory_logger::srv::SaveTrajectory_Request::_filename_type arg)
  {
    msg_.filename = std::move(arg);
    return Init_SaveTrajectory_Request_duration(msg_);
  }

private:
  ::trajectory_logger::srv::SaveTrajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_logger::srv::SaveTrajectory_Request>()
{
  return trajectory_logger::srv::builder::Init_SaveTrajectory_Request_filename();
}

}  // namespace trajectory_logger


namespace trajectory_logger
{

namespace srv
{

namespace builder
{

class Init_SaveTrajectory_Response_message
{
public:
  explicit Init_SaveTrajectory_Response_message(::trajectory_logger::srv::SaveTrajectory_Response & msg)
  : msg_(msg)
  {}
  ::trajectory_logger::srv::SaveTrajectory_Response message(::trajectory_logger::srv::SaveTrajectory_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_logger::srv::SaveTrajectory_Response msg_;
};

class Init_SaveTrajectory_Response_success
{
public:
  Init_SaveTrajectory_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveTrajectory_Response_message success(::trajectory_logger::srv::SaveTrajectory_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SaveTrajectory_Response_message(msg_);
  }

private:
  ::trajectory_logger::srv::SaveTrajectory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_logger::srv::SaveTrajectory_Response>()
{
  return trajectory_logger::srv::builder::Init_SaveTrajectory_Response_success();
}

}  // namespace trajectory_logger

#endif  // TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__BUILDER_HPP_
