首先
colcon build --packages-select ros_gazebo_plugin && source install setup.bash
不然后续会报错找不到消息接口

然后
colcon build && source install setup.bash

运行摄像头仿真
ros2 launch camera_sim_pkg camera.launch.py

运行目标仿真
ros2 launch target_model_pkg target_action.launch.py
不加参数就是默认在 5 1 0.5 的位置生成箭头
参数有
model 模型文件
model_name 模型名字（不能生成名字一样的模型）
x
y
z
roll

例如：ros2 launch target_model_pkg target_action.launch.py model:=src/target_model_pkg/urdf/armor/armor_1.sdf model_name:=armor_1

默认是静止，如果运动的话
ros2 topic pub /type std_msgs/msg/Int32 "{data: 1}"

修改模型的位置
ros2 topic pub /pose geometry_msgs/msg/Pose "{position: {x: 1.0, y: 2.0, z: 0.5}}"
