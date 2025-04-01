#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "trajectory_logger/srv/save_trajectory.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "trajectory_logger/trajectory_publisher_saver.hpp"
#include <fstream>
#include <chrono>
#include <filesystem>

namespace trajectory_logger
{

TrajectoryPublisherSaver::TrajectoryPublisherSaver()
    : Node("trajectory_publisher_saver"), marker_count_(0)
{
    // Declare parameters
    this->declare_parameter("save_directory", "trajectories");
    this->declare_parameter("marker_scale", 0.1);
    this->declare_parameter("publish_rate", 10);
    this->declare_parameter("frame_id", "odom");

    // Get parameters
    save_directory_ = this->get_parameter("save_directory").as_string();
    marker_scale_ = this->get_parameter("marker_scale").as_double();
    publish_rate_ = this->get_parameter("publish_rate").as_int();
    
    // Create publishers
    trajectory_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>(
        "trajectory", 10);

    // Create subscribers
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10,
        std::bind(&TrajectoryPublisherSaver::odom_callback, this, std::placeholders::_1));

    // Create services
    trajectory_service_ = this->create_service<trajectory_logger::srv::SaveTrajectory>(
        "save_trajectory",
        std::bind(&TrajectoryPublisherSaver::save_trajectory_callback, this,
                 std::placeholders::_1, std::placeholders::_2));

    // Ensure save directory exists
    ensure_directory_exists(save_directory_);

    RCLCPP_INFO(this->get_logger(), "Trajectory Publisher Saver initialized");
    RCLCPP_INFO(this->get_logger(), "Save directory: %s", save_directory_.c_str());
}

void TrajectoryPublisherSaver::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    auto marker = create_marker(msg, marker_count_++);
    trajectory_data_.markers.push_back(marker);
    trajectory_pub_->publish(trajectory_data_);
}

void TrajectoryPublisherSaver::save_trajectory_callback(
    const std::shared_ptr<trajectory_logger::srv::SaveTrajectory::Request> request,
    std::shared_ptr<trajectory_logger::srv::SaveTrajectory::Response> response)
{
    std::string filepath = save_directory_ + "/" + request->filename;
    RCLCPP_INFO(this->get_logger(), "Saving trajectory to: %s", filepath.c_str());

    std::ofstream file(filepath);
    if (file.is_open())
    {
        auto now = std::chrono::system_clock::now();
        file << "Trajectory saved at: " << std::chrono::system_clock::to_time_t(now) << std::endl;
        file << "Duration: " << request->duration << " seconds" << std::endl;
        file << "Total points: " << trajectory_data_.markers.size() << std::endl;
        file << "---" << std::endl;

        for (const auto& marker : trajectory_data_.markers)
        {
            file << "Marker: " << marker.id << std::endl;
            file << "Position: (" << marker.pose.position.x << ", "
                 << marker.pose.position.y << ", "
                 << marker.pose.position.z << ")" << std::endl;
        }

        file.close();
        response->success = true;
        response->message = "Successfully saved trajectory to " + filepath;
        RCLCPP_INFO(this->get_logger(), "Successfully saved %zu trajectory points",
                    trajectory_data_.markers.size());
    }
    else
    {
        response->success = false;
        response->message = "Failed to open file: " + filepath;
        RCLCPP_ERROR(this->get_logger(), "Failed to open file: %s", filepath.c_str());
    }
}

visualization_msgs::msg::Marker TrajectoryPublisherSaver::create_marker(
    const nav_msgs::msg::Odometry::SharedPtr msg,
    int id)
{
    visualization_msgs::msg::Marker marker;
    marker.header = msg->header;
    marker.id = id;
    marker.type = visualization_msgs::msg::Marker::SPHERE;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.pose = msg->pose.pose;
    marker.scale.x = marker_scale_;
    marker.scale.y = marker_scale_;
    marker.scale.z = marker_scale_;
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;
    marker.color.a = 1.0;
    marker.lifetime = rclcpp::Duration::from_seconds(0);  // Persistent
    return marker;
}

bool TrajectoryPublisherSaver::ensure_directory_exists(const std::string& directory)
{
    try
    {
        std::filesystem::create_directories(directory);
        return true;
    }
    catch (const std::exception& e)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to create directory: %s", e.what());
        return false;
    }
}

} // namespace trajectory_logger

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<trajectory_logger::TrajectoryPublisherSaver>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
