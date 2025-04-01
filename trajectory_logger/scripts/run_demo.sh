#!/bin/bash

# Function to check if a command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Check if tmux is installed
if ! command_exists tmux; then
    echo "tmux is not installed. Please install it with:"
    echo "sudo apt-get install tmux"
    exit 1
fi

# Kill any existing tmux session with the same name
tmux kill-session -t trajectory_demo 2>/dev/null

# Source ROS environment
source /opt/ros/humble/setup.bash
source install/setup.bash

# Create a new tmux session
tmux new-session -d -s trajectory_demo

# Rename the first window
tmux rename-window -t trajectory_demo 'Trajectory Demo'

# Split the window into panes
tmux split-window -h -t trajectory_demo
tmux split-window -v -t trajectory_demo:0.1

# In the first pane (left), launch the nodes
tmux send-keys -t trajectory_demo:0.0 'echo "Launching nodes..." && ros2 launch trajectory_logger trajectory_logger_launch.py' Enter

# Wait for nodes to start
sleep 5

# In the second pane (top-right), publish odometry data
tmux send-keys -t trajectory_demo:0.1 'echo "Publishing odometry data..." && ros2 topic pub /odom nav_msgs/msg/Odometry "{header: {frame_id: '\''odom'\''}, pose: {pose: {position: {x: 1.0, y: 2.0, z: 0.0}}}}" -r 1' Enter

# In the third pane (bottom-right), wait and then call the service
tmux send-keys -t trajectory_demo:0.2 'echo "Waiting 5 seconds before saving trajectory..." && sleep 5 && echo "Saving trajectory..." && ros2 service call /save_trajectory trajectory_logger/srv/SaveTrajectory "{filename: '\''demo_trajectory.txt'\'', duration: 5.0}"' Enter

# Select the first pane
tmux select-pane -t trajectory_demo:0.0

# Attach to the tmux session
tmux attach-session -t trajectory_demo