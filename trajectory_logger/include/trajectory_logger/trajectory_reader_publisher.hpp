#ifndef TRAJECTORY_READER_PUBLISHER_HPP_
#define TRAJECTORY_READER_PUBLISHER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <fstream>
#include <string>
#include <vector>

namespace trajectory_logger
{

/**
 * @brief Class for reading and visualizing saved trajectories
 * 
 * This class reads trajectory data from files and publishes
 * visualization markers for display in RViz.
 */
class TrajectoryReaderPublisher : public rclcpp::Node
{
public:
    /**
     * @brief Constructor
     * Initializes the node, publishers, and timer
     */
    TrajectoryReaderPublisher();

private:
    // ROS2 Components
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr trajectory_pub_;
    rclcpp::TimerBase::SharedPtr visualization_timer_;

    // Configuration
    std::string trajectory_file_;
    double visualization_rate_;
    double marker_scale_;
    std::string frame_id_;

    // Cached trajectory data
    visualization_msgs::msg::MarkerArray trajectory_data_;

    /**
     * @brief Timer callback to publish trajectory
     */
    void publish_trajectory();

    /**
     * @brief Loads trajectory data from file
     * @return true if loading was successful, false otherwise
     */
    bool load_trajectory();

    /**
     * @brief Creates a visualization marker from position data
     * @param x X coordinate
     * @param y Y coordinate
     * @param z Z coordinate
     * @param id Marker ID
     * @return The created visualization marker
     */
    visualization_msgs::msg::Marker create_marker(
        double x, double y, double z, int id);

    /**
     * @brief Parses a position line from the trajectory file
     * @param line The line to parse
     * @param x Output X coordinate
     * @param y Output Y coordinate
     * @param z Output Z coordinate
     * @return true if parsing was successful, false otherwise
     */
    bool parse_position(const std::string& line, 
                       double& x, double& y, double& z);
};

} // namespace trajectory_logger

#endif // TRAJECTORY_READER_PUBLISHER_HPP_ 