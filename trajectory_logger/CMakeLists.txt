cmake_minimum_required(VERSION 3.8)
project(trajectory_logger)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate the service interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/SaveTrajectory.srv"
  DEPENDENCIES std_msgs
)

# Include directories
include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${nav_msgs_INCLUDE_DIRS}
  ${visualization_msgs_INCLUDE_DIRS}
  ${geometry_msgs_INCLUDE_DIRS}
  ${tf2_INCLUDE_DIRS}
  ${tf2_ros_INCLUDE_DIRS}
)

# Create the executables
add_executable(trajectory_publisher_saver 
  src/trajectory_publisher_saver.cpp)

add_executable(trajectory_reader_publisher 
  src/trajectory_reader_publisher.cpp)

add_executable(test_odom_publisher
  src/test_odom_publisher.cpp)

# Add dependencies for trajectory_publisher_saver
ament_target_dependencies(trajectory_publisher_saver
  rclcpp
  std_msgs
  nav_msgs
  visualization_msgs
  geometry_msgs
  tf2
  tf2_ros
)

# Add dependencies for trajectory_reader_publisher
ament_target_dependencies(trajectory_reader_publisher
  rclcpp
  std_msgs
  nav_msgs
  visualization_msgs
  geometry_msgs
  tf2
  tf2_ros
)

# Add dependencies for test_odom_publisher
ament_target_dependencies(test_odom_publisher
  rclcpp
  nav_msgs
)

# Get the interface targets using the recommended approach
rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Link the interface libraries
target_link_libraries(trajectory_publisher_saver "${cpp_typesupport_target}")
target_link_libraries(trajectory_reader_publisher "${cpp_typesupport_target}")

# Install include directories
install(
  DIRECTORY include/
  DESTINATION include
)

# Install executables
install(TARGETS
  trajectory_publisher_saver
  trajectory_reader_publisher
  test_odom_publisher
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

# Install configuration
install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.yaml" PATTERN "*.rviz"
)

# Install trajectories directory
install(DIRECTORY
  trajectories
  DESTINATION share/${PROJECT_NAME}
)

# Install scripts
install(DIRECTORY
  scripts
  DESTINATION lib/${PROJECT_NAME}
  USE_SOURCE_PERMISSIONS
)

ament_package()
