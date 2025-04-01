// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trajectory_logger:srv/SaveTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__STRUCT_HPP_
#define TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__trajectory_logger__srv__SaveTrajectory_Request __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_logger__srv__SaveTrajectory_Request __declspec(deprecated)
#endif

namespace trajectory_logger
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SaveTrajectory_Request_
{
  using Type = SaveTrajectory_Request_<ContainerAllocator>;

  explicit SaveTrajectory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
      this->duration = 0.0;
    }
  }

  explicit SaveTrajectory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : filename(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
      this->duration = 0.0;
    }
  }

  // field types and members
  using _filename_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _filename_type filename;
  using _duration_type =
    double;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__filename(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->filename = _arg;
    return *this;
  }
  Type & set__duration(
    const double & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_logger__srv__SaveTrajectory_Request
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_logger__srv__SaveTrajectory_Request
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SaveTrajectory_Request_ & other) const
  {
    if (this->filename != other.filename) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const SaveTrajectory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SaveTrajectory_Request_

// alias to use template instance with default allocator
using SaveTrajectory_Request =
  trajectory_logger::srv::SaveTrajectory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trajectory_logger


#ifndef _WIN32
# define DEPRECATED__trajectory_logger__srv__SaveTrajectory_Response __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_logger__srv__SaveTrajectory_Response __declspec(deprecated)
#endif

namespace trajectory_logger
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SaveTrajectory_Response_
{
  using Type = SaveTrajectory_Response_<ContainerAllocator>;

  explicit SaveTrajectory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SaveTrajectory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_logger__srv__SaveTrajectory_Response
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_logger__srv__SaveTrajectory_Response
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SaveTrajectory_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SaveTrajectory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SaveTrajectory_Response_

// alias to use template instance with default allocator
using SaveTrajectory_Response =
  trajectory_logger::srv::SaveTrajectory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trajectory_logger

namespace trajectory_logger
{

namespace srv
{

struct SaveTrajectory
{
  using Request = trajectory_logger::srv::SaveTrajectory_Request;
  using Response = trajectory_logger::srv::SaveTrajectory_Response;
};

}  // namespace srv

}  // namespace trajectory_logger

#endif  // TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__STRUCT_HPP_
