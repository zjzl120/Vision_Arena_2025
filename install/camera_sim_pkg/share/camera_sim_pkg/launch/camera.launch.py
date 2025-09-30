import launch
import launch_ros
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.parameter_descriptions import ParameterValue
from launch.launch_description_sources import PythonLaunchDescriptionSource
def generate_launch_description():
        urdf_package_path=get_package_share_directory('camera_sim_pkg')
        world_package_path=get_package_share_directory('target_model_pkg')
        urdf_xacro_path=os.path.join(urdf_package_path,'urdf','camera_robot.urdf.xacro')
        gazebo_word_path=os.path.join(world_package_path,'worlds','arena_with_targets.world')
        action_args=launch.actions.DeclareLaunchArgument(
                name='model',default_value=str(urdf_xacro_path),description="模型路径"
        )
    #相机参数
        action_args_width=launch.actions.DeclareLaunchArgument(
                name='width',default_value='640',description="相机分辨率宽"
        )
        action_args_height=launch.actions.DeclareLaunchArgument(
                name='height',default_value='480',description="相机分辨率高"
        )
        action_args_fps=launch.actions.DeclareLaunchArgument(
                name='fps',default_value='90',description="相机帧率"
        )
        
        comment_result =launch.substitutions.Command(['xacro ',
            launch.substitutions.LaunchConfiguration('model'),
            ' width:=',launch.substitutions.LaunchConfiguration('width'),
            ' height:=',launch.substitutions.LaunchConfiguration('height'),
            ' fps:=',launch.substitutions.LaunchConfiguration('fps')])
        value= ParameterValue(comment_result,value_type=str)
        action_robot_status_publisher=launch_ros.actions.Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                parameters=[{'robot_description':value}],
                output="log"
        )
        action_launch_gazebo =launch.actions.IncludeLaunchDescription(
               PythonLaunchDescriptionSource ([get_package_share_directory('gazebo_ros'),'/launch','/gazebo.launch.py']),
                launch_arguments=[('world',gazebo_word_path),('verbose','true')]
        )
       
        action_robot_gazebo_publisher=launch_ros.actions.Node(
                package="gazebo_ros",
                executable="spawn_entity.py",
                arguments=['-topic','/robot_description','-entity','camera_robot'],
                output="log"
        )
        return launch.LaunchDescription([
        
       action_args,
       action_args_width,
        action_args_height,
        action_args_fps,
      action_launch_gazebo,
       action_robot_status_publisher,
       action_robot_gazebo_publisher
]    )
