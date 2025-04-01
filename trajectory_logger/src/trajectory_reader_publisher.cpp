#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <fstream>
#include <sstream>
#include "trajectory_logger/trajectory_reader_publisher.hpp"

namespace trajectory_logger
{

TrajectoryReaderPublisher::TrajectoryReaderPublisher()
    : Node("trajectory_reader_publisher")
{
    // Declare parameters
    this->declare_parameter("trajectory_file", "");
    this->declare_parameter("visualization_rate", 10.0);
    this->declare_parameter("marker_scale", 0.1);
    this->declare_parameter("frame_id", "odom");

    // Get parameters
    trajectory_file_ = this->get_parameter("trajectory_file").as_string();
    visualization_rate_ = this->get_parameter("visualization_rate").as_double();
    marker_scale_ = this->get_parameter("marker_scale").as_double();
    frame_id_ = this->get_parameter("frame_id").as_string();

    // Create publishers
    trajectory_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>(
        "visualized_trajectory", 10);

    // Initialize marker array
    trajectory_data_ = visualization_msgs::msg::MarkerArray();

    // Load trajectory if file is specified
    if (!trajectory_file_.empty())
    {
        load_trajectory();
    }

    // Create timer for visualization
    visualization_timer_ = this->create_wall_timer(
        std::chrono::milliseconds(static_cast<int>(1000.0 / visualization_rate_)),
        std::bind(&TrajectoryReaderPublisher::publish_trajectory, this));

    RCLCPP_INFO(this->get_logger(), "Trajectory Reader Publisher initialized");
    RCLCPP_INFO(this->get_logger(), "Trajectory file: %s", trajectory_file_.c_str());
    RCLCPP_INFO(this->get_logger(), "Visualization rate: %.1f Hz", visualization_rate_);
}

bool TrajectoryReaderPublisher::load_trajectory()
{
    std::ifstream file(trajectory_file_);
    if (!file.is_open())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to open trajectory file: %s", trajectory_file_.c_str());
        return false;
    }

    trajectory_data_.markers.clear();
    std::string line;
    int marker_id = 0;
    double x, y, z;

    // Skip header lines
    for (int i = 0; i < 4; ++i)
    {
        std::getline(file, line);
    }

    while (std::getline(file, line))
    {
        if (line.find("Marker:") != std::string::npos)
        {
            std::getline(file, line);  // Position line
            if (line.find("Position:") != std::string::npos)
            {
                sscanf(line.c_str(), "Position: (%lf, %lf, %lf)", &x, &y, &z);
                auto marker = create_marker(x, y, z, marker_id++);
                trajectory_data_.markers.push_back(marker);
            }
        }
    }

    file.close();
    RCLCPP_INFO(this->get_logger(), "Loaded %zu trajectory points", trajectory_data_.markers.size());
    return true;
}

void TrajectoryReaderPublisher::publish_trajectory()
{
    if (trajectory_data_.markers.empty())
    {
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000, 
            "No trajectory data available to publish");
        return;
    }

    // Update timestamp for all markers
    auto now = this->now();
    for (auto& marker : trajectory_data_.markers)
    {
        marker.header.stamp = now;
    }

    trajectory_pub_->publish(trajectory_data_);
}

visualization_msgs::msg::Marker TrajectoryReaderPublisher::create_marker(
    double x, double y, double z, int id)
{
    visualization_msgs::msg::Marker marker;
    marker.header.frame_id = frame_id_;
    marker.id = id;
    marker.type = visualization_msgs::msg::Marker::SPHERE;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = z;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = marker_scale_;
    marker.scale.y = marker_scale_;
    marker.scale.z = marker_scale_;
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    marker.color.a = 1.0;
    marker.lifetime = rclcpp::Duration::from_seconds(0);  // Persistent
    return marker;
}

} // namespace trajectory_logger

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<trajectory_logger::TrajectoryReaderPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
