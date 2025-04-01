// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trajectory_logger:srv/SaveTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__TRAITS_HPP_
#define TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "trajectory_logger/srv/detail/save_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace trajectory_logger
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveTrajectory_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: filename
  {
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << "\n";
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveTrajectory_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace trajectory_logger

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_logger::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_logger::srv::SaveTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_logger::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_logger::srv::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_logger::srv::SaveTrajectory_Request & msg)
{
  return trajectory_logger::srv::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_logger::srv::SaveTrajectory_Request>()
{
  return "trajectory_logger::srv::SaveTrajectory_Request";
}

template<>
inline const char * name<trajectory_logger::srv::SaveTrajectory_Request>()
{
  return "trajectory_logger/srv/SaveTrajectory_Request";
}

template<>
struct has_fixed_size<trajectory_logger::srv::SaveTrajectory_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trajectory_logger::srv::SaveTrajectory_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trajectory_logger::srv::SaveTrajectory_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace trajectory_logger
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveTrajectory_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveTrajectory_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace trajectory_logger

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_logger::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_logger::srv::SaveTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_logger::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_logger::srv::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_logger::srv::SaveTrajectory_Response & msg)
{
  return trajectory_logger::srv::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_logger::srv::SaveTrajectory_Response>()
{
  return "trajectory_logger::srv::SaveTrajectory_Response";
}

template<>
inline const char * name<trajectory_logger::srv::SaveTrajectory_Response>()
{
  return "trajectory_logger/srv/SaveTrajectory_Response";
}

template<>
struct has_fixed_size<trajectory_logger::srv::SaveTrajectory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trajectory_logger::srv::SaveTrajectory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trajectory_logger::srv::SaveTrajectory_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trajectory_logger::srv::SaveTrajectory>()
{
  return "trajectory_logger::srv::SaveTrajectory";
}

template<>
inline const char * name<trajectory_logger::srv::SaveTrajectory>()
{
  return "trajectory_logger/srv/SaveTrajectory";
}

template<>
struct has_fixed_size<trajectory_logger::srv::SaveTrajectory>
  : std::integral_constant<
    bool,
    has_fixed_size<trajectory_logger::srv::SaveTrajectory_Request>::value &&
    has_fixed_size<trajectory_logger::srv::SaveTrajectory_Response>::value
  >
{
};

template<>
struct has_bounded_size<trajectory_logger::srv::SaveTrajectory>
  : std::integral_constant<
    bool,
    has_bounded_size<trajectory_logger::srv::SaveTrajectory_Request>::value &&
    has_bounded_size<trajectory_logger::srv::SaveTrajectory_Response>::value
  >
{
};

template<>
struct is_service<trajectory_logger::srv::SaveTrajectory>
  : std::true_type
{
};

template<>
struct is_service_request<trajectory_logger::srv::SaveTrajectory_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trajectory_logger::srv::SaveTrajectory_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__TRAITS_HPP_
