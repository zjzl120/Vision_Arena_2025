# Vision_Arena_2025

视觉校内赛裁判系统，提供简单例程供参考。
更新：补充并规范了摄像头参数显示与使用说明。

<font style="color:#DF2A3F;">注意：正式比赛环境与本地调试环境存在差异。</font>

---

## 一、启动方法


### 1. 裁判系统
示例启动命令（参数可按需修改）：
```bash
ros2 launch referee_pkg referee_pkg_launch.xml \
  TeamName:="TEAM1" \
```

#### 2 摄像头仿真（比赛时仅需运行此项）
```bash
ros2 launch camera_sim_pkg camera.launch.py
```
摄像头参数：
- 图像尺寸：width = 1280 像素，height = 1280 像素
- 帧率：fps = 90 Hz
- 水平视场角：hfov = 1.047 rad
- 内参：fx = 1108. 像素，fy = 1108.383 像素，cx = 640 像素，cy = 640 像素


---

## 二、Docker 使用说明
可以不使用 Docker 直接运行裁判系统与仿真环境。
```bash
# 从 tar 文件导入基础镜像（vision-vrena-2025:v0.1.2）
docker load -i Vision-Vrena-2025.tar

# 构建新镜像，将选手与裁判系统文件打包（vision-vrena-2025:v0.1.3）
docker build -t vision-vrena-2025:v0.1.3 .

# 使用 docker-compose 启动编排（构造三容器并通过网络互联）
docker-compose up

# 关闭容器
docker-compose down
```

---

## 三、文件结构
```text
├── README.md                 # 项目说明文档
├── install/                  # 编译安装目录
├── src/                      # 例程源代码
├── results/                  # 得分结果文件
└── docs/                     # 完整文档
```

---

## 四、文档导航
- [launch 文件使用说明](doc/launchsetting.md) —— 参数说明与用法
- [目标发送要求](doc/objectpublic.md) —— 目标边缘点信息发布规范
- [消息包说明](doc/objectmsg.md) —— 自定义消息包结构与字段
- [话题与服务消息说明](doc/Topic.md) —— 系统交互的话题与服务接口
- [比赛阶段说明](doc/state.md) —— 各比赛阶段的任务与评分

---

## 五、分数统计示例

### STAGE_1
log 示例：
```
ErrorResults 
  stamp : 2025-09-30T10:41:14Z
  target_type : Ring_red
  model_name : Ring_red
  pose : 
       - position : [-1.00259 , 6.98567 , 0.959323]
       - orientation : [-5.65481e-07 , -7.45499e-07 , -0.707106 , 0.707107]
  RingCirclePositionError : 0.474806
  position_error : 0.043206
  orientation_error : 0
  found_in_gazebo : 1
```
字段说明：
1. stamp：log 输出时间
2. target_type / model_name：模型名称
3. pose-position：根据选手发布的像素坐标计算的位置信息
4. pose-orientation：四元数（未归一化，供参考）
5. RingCirclePositionError：圆环内外圆心位置差值（计分）
6. position_error：识别精度误差（取两圆中较小者，计分）
7. orientation_error：不计分
8. found_in_gazebo：恒为 1

json 示例：
```json
{
  "RaceStage1": {
    "average_orientationerror": 0.0,
    "average_positionerror": 0.043,
    "average_ringcentererror": 0.475,
    "fps": 27,
    "run_id": "458bb861-5716-47cc-bffa-e5adbf082ab8",
    "score": 13.0,
    "target_type": "Ring_red",
    "timestamp": "2025-09-30T10:41:31Z"
  },
  "team_name": "TEAMENAME"
}
```
1. team_name 队伍名称
2. RaceStage1 该键指明其内信息所属阶段（比赛结束后其所展示的分数即为该阶段分数)
3. average_orientationerror 同log
4. average_positionerror 同log,计入分数
5. average_ringcentererror 同log，计入分数
6. fps 选手在单位时间内的识别次数,计入分数(单位时间为 1s)
7. run_id 运行id
8. score 最后得分
9. target_type 同lod
10. timestamp  同lod
### STAGE_2
log 示例：
```
ErrorResults 
  stamp : 2025-09-30T11:07:00Z
  target_type : arrow
  model_name : arrow
  pose : 
       - position : [-1.00603 , 7.00915 , 0.95798]
       - orientation : [0.635928 , -0.60991 , 0.322392 , -0.34593]
  RingCirclePositionError : 0
  position_error : 0.0434259
  orientation_error : 2.06512
  found_in_gazebo : 1
```
字段说明：
1. stamp：log 输出时间
2. target_type / model_name：模型名称
3. pose-position：根据选手发布的像素坐标计算的位置信息
4. pose-orientation：四元数（未归一化）
5. RingCirclePositionError：此阶段无用
6. position_error：识别精度误差（计分）
7. orientation_error：方向误差
8. found_in_gazebo：恒为 1

json 示例：
```json
{
  "RaceStage2": {
    "average_directerror": 2.567,
    "average_positionerror": 0.876,
    "fps": 48,
    "max_positionerror": 3.064,
    "run_id": "d976942f-0ffa-441f-8451-912be3defa77",
    "score": 9.0,
    "target_type": "Arrow_red",
    "timestamp": "2025-09-30T11:07:29Z"
  },
  "team_name": "TEAMENAME"
}
```
1. team_name 队伍名称
2. RaceStage2 该键指明其内信息所属阶段（比赛结束后其所展示的分数即为该阶段分数)
3. average_orientationerror 同log
4. average_positionerror 同log,计入分数
5. fps 选手在单位时间内的识别次数,计入分数(单位时间为 1s)
6. run_id 运行id
7. score 最后得分
8. target_type 同lod
9. timestamp  同lod
---

STAGE_3/STAGE_4
log
 ErrorResults 
  stamp : 2025-09-30T11:15:49Z
  target_type : armor_red_1
  model_name : armor_red_1
  pose : 
       - position : [-1.02111 , 7.05548 , 1.23076]
       - orientation : [0.80399 , 0.592801 , -0.0418458 , 0.0208693]
  RingCirclePositionError : 0
  position_error : 0.238272
  orientation_error : 1.96731
  found_in_gazebo : 1
1. stamp 对应该条log输出的时间
2. target_type 模型名称
3. model_name 同上
4. pose-position 裁判系统基于选手发布的像素坐标系点计算出的位置信息
5. pose-orientation 四元数(未归一化),此处信息无用，但考虑到选手需求，故给出
6. RingCirclePositionError 此阶段无用
7. position_error 选手的识别精度量化误差，计入分数
8. orientation_error 四元数，计入分数
9. found_in_gazebo 恒定为 1
json
{
  "RaceStage3": [
    {
      "average_numdetecterror": 0.238,
      "average_orientationerror": 3.14,
      "fps": 44,
      "max_numdetecterror": 999.0,
      "max_orientationerror": 3.14,
      "run_id": "e75c2975-6e88-4f25-a685-7f724fc3d049",
      "score": 0.0,
      "target_type": "armor_red_2",
      "timestamp": "2025-09-30T11:21:13Z"
    },
    {
      "average_numdetecterror": 0.238,
      "average_orientationerror": 1.967,
      "fps": 46,
      "max_numdetecterror": 0.238,
      "max_orientationerror": 1.967,
      "run_id": "b03c72da-42a1-4623-bf21-b5d157f5990e",
      "score": 2.0,
      "target_type": "armor_red_1",
      "timestamp": "2025-09-30T11:21:13Z"
    },
    {
      "average_numdetecterror": 0.238,
      "average_orientationerror": 3.14,
      "fps": 46,
      "max_numdetecterror": 999.0,
      "max_orientationerror": 3.14,
      "run_id": "d7140c53-b776-4cc0-9a7b-7a61cb129125",
      "score": 0.0,
      "target_type": "armor_red_3",
      "timestamp": "2025-09-30T11:21:13Z"
    },
    {
      "average_numdetecterror": 0.238,
      "average_orientationerror": 3.14,
      "fps": 46,
      "max_numdetecterror": 999.0,
      "max_orientationerror": 3.14,
      "run_id": "7e8e6d77-93da-4764-891c-33d763316235",
      "score": 0.0,
      "target_type": "armor_red_4",
      "timestamp": "2025-09-30T11:21:13Z"
    }
  ],
  "team_name": "TEAMENAME"
}
json中会有4个模型的数据，每个模型单独算分，最高分数一致
1. team_name 队伍名称
2. RaceStage3 该键指明其内信息所属阶段（比赛结束后其所展示的分数即为该阶段分数)
3. average_numdetecterror 裁判系统用此值量化选手的装甲板识别以及装甲板数字识别,计入分数
4. average_positionerror 同log
5. fps 选手在单位时间内的识别次数,计入分数(单位时间为 1s)
6. run_id 运行id
7. score 最后得分
8. target_type 同lod
9. timestamp  同lod
STAGE_5
og
 ErrorResults 
  stamp : 2025-09-30T11:38:48Z
  GunRotation : [-0.165149 , 0 , -0.241775]
  CameraOrientation : [0.98932 , -0.120182 , -0.00994658 , -0.0818786]
  ArmorPosition : [-1 , 7 , 1]
  AccuraryDistance : 0
  ArmorOrientation [0.707388 , 0 , 0 , -0.706825]
  HitArmorPrecision : 3
  checkHit : 1
1. stamp 对应该条log输出的时间
2. GunRotation 客户端接收到的云台旋转
3.  CameraOrientation  云台应当进行的旋转
4. ArmorPosition  基于调试考虑gazebo中模型的真实位置
5. AccuraryDistance 误差值
6. ArmorOrientation 装甲板的姿态
7. HitArmorPrecision 击打准确度，计入分数
8. checkHit 是否击打成功，计入分数
json
{
  "RaceStage5": {
    "average_precisonlevel": 0.254,
    "hitarmor_successcount": 0,
    "run_id": "26bcd75f-3d48-40ee-95fa-bd179c14a728",
    "score": 0.0,
    "timestamp": "2025-09-30T11:38:55Z"
  },
  "team_name": "TEAMENAME"
}
基本同上，所以不多加解释
需要特别注意的是: 平均值计算时的除数是客户端发布的有效击打数，而非总请求数

最后更新时间：2025-11-20  
当前版本：v1.0.1