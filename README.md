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
# 四、比赛阶段
### STAGE_1
**本阶段进行圆环的识别**,为防止选手将圆环视作圆进行处理，本阶段裁判系统<font style="color:#DF2A3F;">要求选手端发布圆环的外圆内圆信息</font>。

本阶段选手发布者发布的

**话题名称应为** <font style="background-color:#DF2A3F;">/vision/target</font>

**话题消息类型应为 ** <font style="background-color:#DF2A3F;">referee_pkg::msg::MultiObject </font>

**其中消息中的**

**Object[] objects 应以外圆 内圆 的顺序放入 ， 其内的四个点 应为圆上的 以左点为起始逆时针方向的四个点**

**std_msgs/Header header 应为对应图像消息中的时间戳**

**uint32 num_objects   要求为2**

### STAGE_2
本阶段选手发布者发布的

**话题名称应为** <font style="background-color:#DF2A3F;">/vision/target</font>

**话题消息类型应为**<font style="background-color:#DF2A3F;">referee_pkg::msg::MultiObject </font>

**其中消息中的 **

**Object[] objects  应至少涵盖要求发布的Arrow_red类型，否则分数为0 ，四个角点的顺序为左下起始逆时针方向**

**std_msgs/Header header 应为对应图像消息中的时间戳**

**uint32 num_objects   对应objects**

### STAGE_3/STAGE_4
本阶段选手发布者发布的

**话题名称应为**<font style="background-color:#DF2A3F;">/vision/target</font>

**话题消息类型应为**<font style="background-color:#DF2A3F;">referee_pkg::msg::MultiObject </font>

**其中消息中的**

**Object[] objects  应至少涵盖要求发布的四个装甲板类型，否则分数为0 ，四个角点的顺序为左下起始逆时针方向**

**std_msgs/Header header 应为对应图像消息中的时间戳**

**uint32 num_objects   对应objects**

### STAGE_5
出于全面考察ROS2、裁判系统实际书写以及选手的学习内容的考虑，本阶段ROS通信要求为 **<font style="color:#DF2A3F;">服务</font>**,**选手需要构造服务端**来接收**裁判系统客户端**的请求;此外裁判系统辖定了弹丸的击打速度 <font style="color:#DF2A3F;">1.5m/s</font>

本阶段选手服务的

服务名称应为 **<font style="background-color:#FBDE28;">/referee/hit_arror</font>** 

服务消息类型应为 **<font style="background-color:#FBDE28;">referee_pkg::srv::HitArmor</font>** 

需要注意的是返回的 Response 中的 欧拉角应为<font style="color:#DF2A3F;"> 外旋ZYX </font>顺序 ，当然你要真的想弄复杂些弄 内旋ZYX 我也没意见 ，跟我提就好（根据反馈人数决定要不要更改）


# 五、比赛得分

<details class="lake-collapse"><summary id="ud7ac7697"><span class="ne-text" style="font-size: 16px">比赛阶段及对应分数</span></summary><h5 id="lN8Kk"><span class="ne-text">基础任务（40分）分两个任务，各二十分</span></h5><ol class="ne-ol"><li id="ue46aa76e" data-lake-index-type="0"><span class="ne-text" style="font-size: 16px">识别物体：圆环（内外八个点），箭头（按顺序发送点）</span></li></ol><p id="u47b05239" class="ne-p"><span class="ne-text" style="font-size: 16px">分值设置：</span></p><ol class="ne-ol"><li id="ub78d1d02" data-lake-index-type="0"><span class="ne-text" style="font-size: 16px">准确度（10分）【待测试】：</span></li><li id="uf7472692" data-lake-index-type="0"><span class="ne-text" style="font-size: 16px">单位时间内识别次数：根据选手端发来图像时发过几帧相机图像（10分）【待测试分档】：</span></li></ol><h5 id="jgGg1"><span class="ne-text">进阶任务（30分）</span></h5><ol class="ne-ol"><li id="u60b3ff42" data-lake-index-type="0"><span class="ne-text" style="font-size: 16px">动态识别：同时出现不同数字编号的四个装甲板，按照数字及对应装甲板位置存入自定义消息</span></li></ol><p id="uf1e5399c" class="ne-p"><span class="ne-text" style="font-size: 16px">采分：数字识别准确度（10分）：</span></p><p id="u5cff3389" class="ne-p" style="margin-left: 2em"><span class="ne-text" style="font-size: 16px">   识别次数（5分）</span></p><ol start="2" class="ne-ol"><li id="ufd7f787b" data-lake-index-type="0"><span class="ne-text" style="font-size: 16px">干扰项区分：在动态的多个尺寸比例下的正方体长方体干扰中识别动态装甲板位置</span></li></ol><p id="u31c5042f" class="ne-p"><span class="ne-text" style="font-size: 16px">采分：位置识别准确度（10分）</span></p><p id="u7eab0fc1" class="ne-p" style="text-indent: 2em"><span class="ne-text" style="font-size: 16px">   识别次数（5分）</span></p><h5 id="qfQJV"><span class="ne-text">装甲板击打（20分）</span></h5><p id="uadd2c688" class="ne-p"><span class="ne-text" style="font-size: 16px">选手端自行进行pnp解算，输出旋转角</span></p><p id="u1690bdfd" class="ne-p"><span class="ne-text" style="font-size: 16px">采分：</span></p><p id="u5ec062c0" class="ne-p"><span class="ne-text" style="font-size: 16px">         pnp准确度（0分）： (暂时废弃)</span></p><ol class="ne-ol"><li id="ua45b1443" data-lake-index-type="0"><span class="ne-text" style="font-size: 16px">弹道解算（20分）：是否命中（8分），命中精度（12分）：</span></li></ol><h5 id="XF14Q"><span class="ne-text">代码规范（10分）</span></h5><p id="u1abeb300" class="ne-p"><span class="ne-text" style="font-size: 16px">语雀技术文档，注释清晰</span></p><p id="u1e9c6dcd" class="ne-p"><span class="ne-text" style="font-size: 16px"></span></p></details>




**最后更新时间**：2025年9月30日  
**当前版本**：v1.0.0


