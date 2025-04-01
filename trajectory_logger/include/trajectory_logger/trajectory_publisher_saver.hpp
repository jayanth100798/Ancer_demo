#ifndef TRAJECTORY_PUBLISHER_SAVER_HPP_
#define TRAJECTORY_PUBLISHER_SAVER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <trajectory_logger/srv/save_trajectory.hpp>
#include <filesystem>
#include <fstream>

namespace trajectory_logger
{

/**
 * @brief Class for collecting and saving robot trajectories
 * 
 * This class subscribes to odometry data, visualizes the trajectory,
 * and provides a service to save the collected trajectory to a file.
 */
class TrajectoryPublisherSaver : public rclcpp::Node
{
public:
    /**
     * @brief Constructor
     * Initializes the node, publishers, subscribers, and service
     */
    TrajectoryPublisherSaver();

private:
    // ROS2 Publishers, Subscribers, and Services
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr trajectory_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Service<trajectory_logger::srv::SaveTrajectory>::SharedPtr trajectory_service_;

    // Data storage
    visualization_msgs::msg::MarkerArray trajectory_data_;
    int marker_count_;

    // Configuration
    std::string save_directory_;
    double marker_scale_;
    int publish_rate_;

    /**
     * @brief Callback for odometry messages
     * @param msg The received odometry message
     */
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);

    /**
     * @brief Service callback for saving trajectories
     * @param request The service request containing filename and duration
     * @param response The service response indicating success/failure
     */
    void save_trajectory_callback(
        const std::shared_ptr<trajectory_logger::srv::SaveTrajectory::Request> request,
        std::shared_ptr<trajectory_logger::srv::SaveTrajectory::Response> response);

    /**
     * @brief Creates a visualization marker from odometry data
     * @param msg The odometry message
     * @param id The marker ID
     * @return The created visualization marker
     */
    visualization_msgs::msg::Marker create_marker(
        const nav_msgs::msg::Odometry::SharedPtr msg,
        int id);

    /**
     * @brief Ensures the save directory exists
     * @param directory The directory path to check/create
     * @return true if directory exists or was created, false otherwise
     */
    bool ensure_directory_exists(const std::string& directory);
};

} // namespace trajectory_logger

#endif // TRAJECTORY_PUBLISHER_SAVER_HPP_ 