// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from trajectory_logger:srv/SaveTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__FUNCTIONS_H_
#define TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "trajectory_logger/msg/rosidl_generator_c__visibility_control.h"

#include "trajectory_logger/srv/detail/save_trajectory__struct.h"

/// Initialize srv/SaveTrajectory message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trajectory_logger__srv__SaveTrajectory_Request
 * )) before or use
 * trajectory_logger__srv__SaveTrajectory_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Request__init(trajectory_logger__srv__SaveTrajectory_Request * msg);

/// Finalize srv/SaveTrajectory message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
void
trajectory_logger__srv__SaveTrajectory_Request__fini(trajectory_logger__srv__SaveTrajectory_Request * msg);

/// Create srv/SaveTrajectory message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trajectory_logger__srv__SaveTrajectory_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
trajectory_logger__srv__SaveTrajectory_Request *
trajectory_logger__srv__SaveTrajectory_Request__create();

/// Destroy srv/SaveTrajectory message.
/**
 * It calls
 * trajectory_logger__srv__SaveTrajectory_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
void
trajectory_logger__srv__SaveTrajectory_Request__destroy(trajectory_logger__srv__SaveTrajectory_Request * msg);

/// Check for srv/SaveTrajectory message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Request__are_equal(const trajectory_logger__srv__SaveTrajectory_Request * lhs, const trajectory_logger__srv__SaveTrajectory_Request * rhs);

/// Copy a srv/SaveTrajectory message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Request__copy(
  const trajectory_logger__srv__SaveTrajectory_Request * input,
  trajectory_logger__srv__SaveTrajectory_Request * output);

/// Initialize array of srv/SaveTrajectory messages.
/**
 * It allocates the memory for the number of elements and calls
 * trajectory_logger__srv__SaveTrajectory_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Request__Sequence__init(trajectory_logger__srv__SaveTrajectory_Request__Sequence * array, size_t size);

/// Finalize array of srv/SaveTrajectory messages.
/**
 * It calls
 * trajectory_logger__srv__SaveTrajectory_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
void
trajectory_logger__srv__SaveTrajectory_Request__Sequence__fini(trajectory_logger__srv__SaveTrajectory_Request__Sequence * array);

/// Create array of srv/SaveTrajectory messages.
/**
 * It allocates the memory for the array and calls
 * trajectory_logger__srv__SaveTrajectory_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
trajectory_logger__srv__SaveTrajectory_Request__Sequence *
trajectory_logger__srv__SaveTrajectory_Request__Sequence__create(size_t size);

/// Destroy array of srv/SaveTrajectory messages.
/**
 * It calls
 * trajectory_logger__srv__SaveTrajectory_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
void
trajectory_logger__srv__SaveTrajectory_Request__Sequence__destroy(trajectory_logger__srv__SaveTrajectory_Request__Sequence * array);

/// Check for srv/SaveTrajectory message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Request__Sequence__are_equal(const trajectory_logger__srv__SaveTrajectory_Request__Sequence * lhs, const trajectory_logger__srv__SaveTrajectory_Request__Sequence * rhs);

/// Copy an array of srv/SaveTrajectory messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Request__Sequence__copy(
  const trajectory_logger__srv__SaveTrajectory_Request__Sequence * input,
  trajectory_logger__srv__SaveTrajectory_Request__Sequence * output);

/// Initialize srv/SaveTrajectory message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trajectory_logger__srv__SaveTrajectory_Response
 * )) before or use
 * trajectory_logger__srv__SaveTrajectory_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Response__init(trajectory_logger__srv__SaveTrajectory_Response * msg);

/// Finalize srv/SaveTrajectory message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
void
trajectory_logger__srv__SaveTrajectory_Response__fini(trajectory_logger__srv__SaveTrajectory_Response * msg);

/// Create srv/SaveTrajectory message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trajectory_logger__srv__SaveTrajectory_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
trajectory_logger__srv__SaveTrajectory_Response *
trajectory_logger__srv__SaveTrajectory_Response__create();

/// Destroy srv/SaveTrajectory message.
/**
 * It calls
 * trajectory_logger__srv__SaveTrajectory_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
void
trajectory_logger__srv__SaveTrajectory_Response__destroy(trajectory_logger__srv__SaveTrajectory_Response * msg);

/// Check for srv/SaveTrajectory message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Response__are_equal(const trajectory_logger__srv__SaveTrajectory_Response * lhs, const trajectory_logger__srv__SaveTrajectory_Response * rhs);

/// Copy a srv/SaveTrajectory message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Response__copy(
  const trajectory_logger__srv__SaveTrajectory_Response * input,
  trajectory_logger__srv__SaveTrajectory_Response * output);

/// Initialize array of srv/SaveTrajectory messages.
/**
 * It allocates the memory for the number of elements and calls
 * trajectory_logger__srv__SaveTrajectory_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Response__Sequence__init(trajectory_logger__srv__SaveTrajectory_Response__Sequence * array, size_t size);

/// Finalize array of srv/SaveTrajectory messages.
/**
 * It calls
 * trajectory_logger__srv__SaveTrajectory_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
void
trajectory_logger__srv__SaveTrajectory_Response__Sequence__fini(trajectory_logger__srv__SaveTrajectory_Response__Sequence * array);

/// Create array of srv/SaveTrajectory messages.
/**
 * It allocates the memory for the array and calls
 * trajectory_logger__srv__SaveTrajectory_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
trajectory_logger__srv__SaveTrajectory_Response__Sequence *
trajectory_logger__srv__SaveTrajectory_Response__Sequence__create(size_t size);

/// Destroy array of srv/SaveTrajectory messages.
/**
 * It calls
 * trajectory_logger__srv__SaveTrajectory_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
void
trajectory_logger__srv__SaveTrajectory_Response__Sequence__destroy(trajectory_logger__srv__SaveTrajectory_Response__Sequence * array);

/// Check for srv/SaveTrajectory message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Response__Sequence__are_equal(const trajectory_logger__srv__SaveTrajectory_Response__Sequence * lhs, const trajectory_logger__srv__SaveTrajectory_Response__Sequence * rhs);

/// Copy an array of srv/SaveTrajectory messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trajectory_logger
bool
trajectory_logger__srv__SaveTrajectory_Response__Sequence__copy(
  const trajectory_logger__srv__SaveTrajectory_Response__Sequence * input,
  trajectory_logger__srv__SaveTrajectory_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TRAJECTORY_LOGGER__SRV__DETAIL__SAVE_TRAJECTORY__FUNCTIONS_H_
