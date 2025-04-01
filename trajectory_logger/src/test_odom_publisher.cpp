#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <cmath>

class TestOdomPublisher : public rclcpp::Node
{
public:
    TestOdomPublisher() : Node("test_odom_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("/odom", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),  // 10Hz
            std::bind(&TestOdomPublisher::timer_callback, this));
        
        RCLCPP_INFO(this->get_logger(), "Test Odometry Publisher started");
    }

private:
    void timer_callback()
    {
        auto odom = nav_msgs::msg::Odometry();
        odom.header.stamp = this->now();
        odom.header.frame_id = "map";
        odom.child_frame_id = "base_link";

        // Create a circular pattern
        double radius = 2.0;  // 2 meter radius
        double angular_velocity = 0.5;  // rad/s
        double time = count_ * 0.1;  // 100ms per step
        
        odom.pose.pose.position.x = radius * cos(angular_velocity * time);
        odom.pose.pose.position.y = radius * sin(angular_velocity * time);
        odom.pose.pose.position.z = 0.0;
        
        // Simple orientation (always facing the direction of motion)
        odom.pose.pose.orientation.w = cos(angular_velocity * time / 2);
        odom.pose.pose.orientation.z = sin(angular_velocity * time / 2);
        
        publisher_->publish(odom);
        count_++;
    }

    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TestOdomPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
} 