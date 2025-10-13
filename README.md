# Vision_Arena_2025

视觉校内赛裁判系统，提供简单例程共参考


# 一、启动方法
建议在非比赛阶段不使用docker进行工作
## 裁判系统
如有需要自行更改，下面仅作为示例
```
ros2 launch referee_pkg referee_pkg_launch.xml \
    TeamName:="TEAMENAME" \
    StageSelect:=1 \
    ModeSelect:=0
```
## gazebo

运行摄像头仿真
```
ros2 launch camera_sim_pkg camera.launch.py
```
运行目标仿真
```
ros2 launch target_model_pkg target_action.launch.py
```
不加参数就是默认在 5 1 0.5 的位置生成箭头
参数有
model 模型文件
model_name 模型名字（不能生成名字一样的模型）
x
y
z
roll
例如(装甲板1)：
```
ros2 launch target_model_pkg target_action.launch.py model:=src/target_model_pkg/urdf/armor/armor_1.sdf model_name:=armor_1
```
默认是静止，如果运动的话
```
ros2 topic pub /type std_msgs/msg/Int32 "{data: 1}"
```
修改模型的位置
```
ros2 topic pub /pose geometry_msgs/msg/Pose "{position: {x: 1.0, y: 2.0, z: 0.5}}"
```
## 示例选手端测试程序
```
ros2 run player_pkg TestNode
```
## docker tar 文件使用
```
# 从tar文件中读取镜像 其名成为 vision-vrena-2025:v0.1.2
docker load -i Vision-Vrena-2025.tar

# 运行Dockerfile文件将选手的文件以及裁判系统文件移入以构造一个新的镜像其名称为vision-vrena-2025:v0.1.3
docker build -t vision-vrena-2025:v0.1.3 .

# 运行docker-compose.yml文件以镜像构造三个用dockernetwork链接可互相通信的容器
docker-compose up
```

# 二、 文件结构

```
├── README.md                # 项目说明文档
├── install/                  # 编译安装目录
├── src/                    # 例程源代码
├── results/                  # 得分结果文件
└── docs/                    # 完整文档
```


# 三、文档导航




**最后更新时间**：2025年9月30日  
**当前版本**：v1.0.0


