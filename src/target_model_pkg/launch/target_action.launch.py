import launch
import launch_ros
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory, get_package_prefix
from launch.actions import SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    package_path = get_package_share_directory('target_model_pkg')   
    path=os.path.join(package_path,'urdf','arrow/arrow.sdf')         
    action_declare_arg_mode_path = launch.actions.DeclareLaunchArgument(name='model',default_value=str(path),description='加载的模型文件路径')
    declare_modelname = launch.actions.DeclareLaunchArgument('model_name',default_value='arrow')
    declare_x = launch.actions.DeclareLaunchArgument('x', default_value='-1.0')
    declare_y = launch.actions.DeclareLaunchArgument('y', default_value='7.0')
    declare_z = launch.actions.DeclareLaunchArgument('z', default_value='1.0')
    declare_roll = launch.actions.DeclareLaunchArgument('roll', default_value='0.0')
    pkg_prefix = get_package_prefix('target_model_pkg')
    plugin_path = os.path.join(get_package_prefix('target_model_pkg'), 'lib')
    SetEnvironmentVariable(
    name='GAZEBO_PLUGIN_PATH',
    value=plugin_path + ':' + os.environ.get('GAZEBO_PLUGIN_PATH', '')
),

    # paths=[
    #     os.path.join(package_path,'urdf','armor/armor_1.sdf'),
    #     os.path.join(package_path,'urdf','armor/armor_2.sdf'),
    #     os.path.join(package_path,'urdf','armor/armor_3.sdf'),
    #     os.path.join(package_path,'urdf','armor/armor_4.sdf'),
    #     os.path.join(package_path,'urdf','armor/armor_5.sdf')
    # ]
    
    # spawn_nodes = []
    # for i , path_ in enumerate(paths):
    #     spawn_nodes.append(  launch_ros.actions.Node(
    #     package='gazebo_ros',
    #     executable='spawn_entity.py',
    #     arguments=['-file', path_, '-entity', f'model_{i}'],
    #     name=f'spawn_armor_{i}',
    #     output='screen'
    # ))
    
    
    action_launch_robot = launch_ros.actions.Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=[
            '-file', LaunchConfiguration('model'),
            '-entity', LaunchConfiguration('model_name'),
            '-x', LaunchConfiguration('x'),
            '-y', LaunchConfiguration('y'),
            '-z', LaunchConfiguration('z'),
            '-R', LaunchConfiguration('roll')
        ],
        output='screen'
    )
    
    
    return LaunchDescription([
        declare_x,
        declare_y,
        declare_z,
        declare_roll,
        declare_modelname,
        action_declare_arg_mode_path,
        action_launch_robot,
        
        #*spawn_nodes
    ])
