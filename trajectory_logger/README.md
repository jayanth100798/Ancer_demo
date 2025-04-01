# Trajectory Logger

A ROS2 package for collecting, storing, and visualizing robot trajectories. This package provides a modular solution for recording robot movements and replaying them for analysis or visualization.

## Architecture

The package consists of two main nodes:
1. `trajectory_publisher_saver`: Collects and saves trajectory data
2. `trajectory_reader_publisher`: Reads and visualizes saved trajectories

### Algorithms

#### Trajectory Collection and Storage
```pseudocode
Algorithm: TrajectoryCollection
Input: Odometry messages from robot
Output: Stored trajectory file

1. Initialize trajectory storage container
2. For each incoming odometry message:
   2.1. Extract pose information
   2.2. Create visualization marker
   2.3. Add to trajectory container
   2.4. Publish current trajectory visualization

3. When save service is called:
   3.1. Open specified file
   3.2. Write metadata (timestamp, duration)
   3.3. For each point in trajectory:
      3.3.1. Write position data
   3.4. Close file
   3.5. Return success status
```

#### Trajectory Visualization
```pseudocode
Algorithm: TrajectoryVisualization
Input: Trajectory file
Output: Visualization markers

1. Initialize visualization publisher
2. Monitor trajectory file:
   2.1. Read trajectory data
   2.2. Parse position information
   2.3. Create visualization markers
   2.4. Publish markers for RViz visualization
```

## Class Structure

### TrajectoryPublisherSaver
```cpp
class TrajectoryPublisherSaver {
private:
    // ROS2 components
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr trajectory_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Service<trajectory_logger::srv::SaveTrajectory>::SharedPtr trajectory_service_;
    
    // Data storage
    visualization_msgs::msg::MarkerArray trajectory_data_;
    
    // Configuration
    std::string save_directory_;
    
public:
    // Constructor and core functions
    TrajectoryPublisherSaver();
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void save_trajectory_callback(const std::shared_ptr<SaveTrajectory::Request> request,
                                std::shared_ptr<SaveTrajectory::Response> response);
};
```

### TrajectoryReaderPublisher
```cpp
class TrajectoryReaderPublisher {
private:
    // ROS2 components
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr trajectory_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    // Configuration
    std::string trajectory_file_;
    
public:
    // Constructor and core functions
    TrajectoryReaderPublisher();
    void publish_trajectory();
};
```

## Configuration

All configurable parameters can be set through ROS2 parameters or launch file arguments:

```yaml
trajectory_publisher_saver:
  ros__parameters:
    save_directory: "trajectories"
    marker_scale: 0.1
    publish_rate: 10

trajectory_reader_publisher:
  ros__parameters:
    trajectory_file: "trajectory.txt"
    visualization_rate: 1.0
```

## Dependencies

- ROS2 Humble
- Navigation Messages
- Visualization Messages
- TF2

## Building

```bash
# Create a workspace
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src

# Clone the repository
git clone <repository_url> trajectory_logger

# Build
cd ..
colcon build --symlink-install
```

## Usage

1. Launch the nodes:
```bash
ros2 launch trajectory_logger trajectory_logger_launch.py
```

2. Save a trajectory:
```bash
ros2 service call /save_trajectory trajectory_logger/srv/SaveTrajectory "{filename: 'my_trajectory.txt', duration: 5.0}"
```

3. Run the demo:
```bash
./scripts/run_demo.sh
```

## Code Organization

```
trajectory_logger/
├── include/
│   └── trajectory_logger/
│       ├── trajectory_publisher_saver.hpp
│       └── trajectory_reader_publisher.hpp
├── src/
│   ├── trajectory_publisher_saver.cpp
│   └── trajectory_reader_publisher.cpp
├── launch/
│   └── trajectory_logger_launch.py
├── scripts/
│   └── run_demo.sh
├── srv/
│   └── SaveTrajectory.srv
└── config/
    └── params.yaml
```

## Future Enhancements

1. Support for different file formats (JSON, YAML, binary)
2. Trajectory interpolation and smoothing
3. Time-based playback of trajectories
4. Integration with navigation stack
5. Support for multiple coordinate frames

## Contributing

Please follow these guidelines when contributing:
1. Use descriptive variable and function names
2. Add comments for complex logic
3. Follow C++ style guidelines
4. Write unit tests for new features
5. Update documentation

## License

This project is licensed under the MIT License - see the LICENSE file for details. 