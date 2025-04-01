from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch.actions import LogInfo
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get the package directory
    pkg_dir = get_package_share_directory('trajectory_logger')
    
    # Ensure trajectories directory exists
    trajectories_dir = os.path.join(pkg_dir, 'trajectories')
    os.makedirs(trajectories_dir, exist_ok=True)
    
    # Load parameters
    params_file = os.path.join(pkg_dir, 'config', 'params.yaml')
    rviz_config_file = os.path.join(pkg_dir, 'config', 'trajectory_logger.rviz')
    
    # Create launch configuration variables
    trajectory_file = LaunchConfiguration('trajectory_file')
    save_directory = LaunchConfiguration('save_directory')
    params_file_arg = DeclareLaunchArgument(
        'params_file',
        default_value=params_file,
        description='Full path to the ROS2 parameters file'
    )
    
    # Declare launch arguments
    declare_trajectory_file_cmd = DeclareLaunchArgument(
        'trajectory_file',
        default_value=os.path.join(trajectories_dir, 'trajectory.txt'),
        description='Path to the trajectory file'
    )
    
    declare_save_directory_cmd = DeclareLaunchArgument(
        'save_directory',
        default_value=trajectories_dir,
        description='Directory to save trajectory files'
    )
    
    # Create the static transform publisher for map->odom
    static_transform_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='static_transform_publisher',
        arguments=['0', '0', '0', '0', '0', '0', 'map', 'odom']
    )
    
    # Create the trajectory publisher/saver node
    publisher_saver_node = Node(
        package='trajectory_logger',
        executable='trajectory_publisher_saver',
        name='trajectory_publisher_saver',
        output='screen',
        parameters=[LaunchConfiguration('params_file')]
    )

    # Create the trajectory reader/publisher node
    reader_publisher_node = Node(
        package='trajectory_logger',
        executable='trajectory_reader_publisher',
        name='trajectory_reader_publisher',
        output='screen',
        parameters=[LaunchConfiguration('params_file')]
    )

    # Create and return launch description
    ld = LaunchDescription()
    
    # Add the commands to the launch description
    ld.add_action(LogInfo(msg=['Trajectories directory: ', trajectories_dir]))
    ld.add_action(declare_save_directory_cmd)
    ld.add_action(declare_trajectory_file_cmd)
    ld.add_action(params_file_arg)
    ld.add_action(LogInfo(msg="Starting Trajectory Logger nodes..."))
    
    # Add the static transform publisher first
    ld.add_action(static_transform_node)
    
    # Add the test odometry publisher
    ld.add_action(Node(
        package='trajectory_logger',
        executable='test_odom_publisher',
        name='test_odom_publisher',
        output='screen'
    ))
    
    # Add the other nodes
    ld.add_action(publisher_saver_node)
    ld.add_action(reader_publisher_node)

    # Launch RViz
    ld.add_action(Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_file],
        output='screen'
    ))

    return ld
