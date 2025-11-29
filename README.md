# Vision_Arena_2025

视觉校内赛裁判系统，提供简单例程与仿真环境。
更新：补充并规范摄像头参数显示与使用说明。

<font style="color:#DF2A3F;">注意：正式比赛环境与本地调试环境存在差异。</font>

---

## 一、启动方法

### 0. 编译（使用前）
```bash
source install/local_setup.sh
```

### 1. 裁判系统
示例启动命令（参数可按需修改）：
```bash
ros2 launch referee_pkg referee_pkg_launch.xml TeamName:="TEAM1"
```

### 2. 摄像头仿真（比赛时仅需运行此项）
```bash
ros2 launch camera_sim_pkg camera.launch.py
```
摄像头参数：
- 图像尺寸：width = 1280 像素，height = 1280 像素
- 帧率：fps = 90 Hz
- 水平视场角：hfov = 1.047 rad
- 内参：fx = 1108.0 像素，fy = 1108.383 像素，cx = 640 像素，cy = 640 像素

说明：
- 若需轻量配置，可改为 640×640，并按比例调整 fx/fy/cx/cy。

---

## 二、Docker 使用说明
可以不使用 Docker 直接运行裁判系统与仿真环境。
```bash
# 从 tar 文件导入基础镜像（vision-vrena-2025:v0.1.2）
docker load -i Vision-Vrena-2025.tar

# 构建新镜像，将选手与裁判系统文件打包（vision-vrena-2025:v0.1.3）
docker build -t vision-vrena-2025:v0.1.3 .

# 使用 docker-compose 启动编排（多容器互联）
docker-compose up

# 关闭容器
docker-compose down
```

---

## 三、文件结构
```text
├── README.md                 # 项目说明文档
├── install/                  # 编译安装目录
├── src/                      # 源代码（裁判系统/选手例程/仿真包）
├── results/                  # 得分结果（JSON 与 .sha256）
└── docs/                     # 完整文档
```

---

## 四、文档导航
- [launch 文件使用说明](doc/launchsetting.md) —— 参数说明与用法
- [目标发送要求](doc/objectpublic.md) —— 目标边缘点信息发布规范
- [消息包说明](doc/objectmsg.md) —— 自定义消息包结构与字段
- [话题与服务消息说明](doc/Topic.md) —— 系统交互的话题与服务接口
- [比赛阶段说明](doc/state.md) —— 各比赛阶段任务与评分（Level 1/2/3）

---

## 五、分数统计示例（含 JSON 字段说明）

### STAGE_1（圆环，Level 1）
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

JSON 示例：
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

JSON 字段说明：
1. team_name 队伍名称
2. RaceStage1 表示该键对应 STAGE_1 的阶段结果（展示的 score 即该阶段得分）
3. average_orientationerror 与 log 中 orientation_error 对应（本阶段不计分，仅参考）
4. average_positionerror 与 log 中 position_error 对应（计分）
5. average_ringcentererror 与 log 中 RingCirclePositionError 对应（计分）
6. fps 单位时间内的有效识别次数（计分，单位时间为 1s）
7. run_id 运行标识
8. score 最终得分
9. target_type 目标类型（与模型/任务对应）
10. timestamp 统计时间戳

---

### STAGE_2（箭头，Level 1）
log 示例：
```
ErrorResults 
  stamp : 2025-09-30T11:07:00Z
  target_type : Arrow_red
  model_name : Arrow_red
  pose : 
       - position : [-1.00603 , 7.00915 , 0.95798]
       - orientation : [0.635928 , -0.60991 , 0.322392 , -0.34593]
  RingCirclePositionError : 0
  position_error : 0.0434259
  orientation_error : 2.06512
  found_in_gazebo : 1
```

JSON 示例：
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

JSON 字段说明：
1. team_name 队伍名称
2. RaceStage2 表示该键对应 STAGE_2 的阶段结果
3. average_directerror 箭头方向误差平均值（计分）
4. average_positionerror 位置误差平均值（计分）
5. fps 单位时间内有效识别次数（计分，单位时间为 1s）
6. max_positionerror 位置误差最大值（参考/用于鲁棒性指标）
7. run_id 运行标识
8. score 最终得分
9. target_type 目标类型
10. timestamp 统计时间戳

---

### STAGE_3 / STAGE_4（装甲板/数字，Level 2）
log 示例：
```
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
```

JSON 示例（STAGE_3 节选，4 个目标分别计分）：
```json
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
    }
  ],
  "team_name": "TEAMENAME"
}
```

JSON 字段说明：
1. team_name 队伍名称
2. RaceStage3 为数组，包含多个目标的独立计分结果（通常 4 个目标）
3. average_numdetecterror 数量/类别识别误差（用于装甲板与数字识别的量化指标，计分）
4. average_orientationerror 姿态误差平均值（计分）
5. fps 单位时间内有效识别次数（计分，单位时间为 1s）
6. max_numdetecterror 数量/类别识别误差最大值（参考/鲁棒性指标）
7. max_orientationerror 姿态误差最大值（参考/鲁棒性指标）
8. run_id 运行标识
9. score 该目标的最终得分（各目标分数上限一致）
10. target_type 对应目标类型/模型名
11. timestamp 统计时间戳

---

### STAGE_5（击打装甲，Level 3）
log 示例：
```
ErrorResults 
  stamp : 2025-09-30T11:38:48Z
  GunRotation : [-0.165149 , 0 , -0.241775]
  CameraOrientation : [0.98932 , -0.120182 , -0.00994658 , -0.0818786]
  ArmorPosition : [-1 , 7 , 1]
  AccuraryDistance : 0
  ArmorOrientation : [0.707388 , 0 , 0 , -0.706825]
  HitArmorPrecision : 3
  checkHit : 1
```

JSON 示例：
```json
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
```

JSON 字段说明：
1. team_name 队伍名称
2. RaceStage5 表示该键对应 STAGE_5 的阶段结果
3. average_precisonlevel 平均击打精度等级（计分，注意平均值的除数为“有效击打数”）
4. hitarmor_successcount 有效击打成功次数（计分/统计）
5. run_id 运行标识
6. score 最终得分
7. timestamp 统计时间戳

说明：平均值计算时的除数是客户端发布的有效击打数，而非总请求数。

---

最后更新时间：2025-11-29  
当前版本：v1.0.1