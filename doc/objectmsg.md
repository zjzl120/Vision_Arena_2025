## 消息包
### msg
#### Object.msg(选手发布的物体信息基础类型)
```cpp
string target_type           # 目标类型，如 "armor_1", "circle_red"
geometry_msgs/Point[] corners  # 四个角点的像素坐标 （左下起始，逆时针方向）
```

```cpp
#include "referee_pkg/msg/object.hpp"
```

<font style="color:#DF2A3F;">特别提醒:</font> **裁判系统对本消息包**不提供对应的话题接口,但仍需加入头文件以保证用其构造的上级消息包能够正常工作。

#### MultiObject.msg(选手需构造发布的消息类型)
```cpp
std_msgs/Header header		 # 时间戳
Object[] objects             # 多个物体数组
```

```cpp
#include "referee_pkg/msg/multi_object.hpp"
```

<font style="color:#DF2A3F;">特别提醒:</font> **裁判系统对本消息包**不提供对应的话题接口,但仍需加入头文件以保证用其构造的上级消息包能够正常工作。

**<font style="color:#DF2A3F;">特别提醒:</font>**  **消息包内的时间戳请直接沿用其对应图像的时间戳，比赛时若因此导致分数错误概不负责。**

#### RaceStage.msg(裁判系统在比赛阶段切换时发布的消息)
```cpp
int32 stage                   # 比赛阶段 1,2,3,4,5
```

```cpp
#include "referee_pkg/msg/race_stage.hpp"
"/referee/race_stage"
```

**<font style="color:#DF2A3F;">特别提醒:</font>** **该消息仅在阶段切换时进行，请设置订阅者及时接收**

### srv
#### HitArmor.msg(选手须在比赛阶段五构造对应消息的服务器)
```cpp
geometry_msgs/Point[] modelpoint   # 模型的真值点 (左下起始,逆时针方向)
std_msgs/Header header		       # 时间戳
float64 g						   # 重力加速度
---
float64 yaw						   # 欧拉角
float64 pitch
float64 roll
```

```cpp
#include "referee_pkg/srv/hit_armor.hpp"
"/referee/hit_arror"
```

**<font style="color:#DF2A3F;">特别提醒:</font>** **请及时构造对应服务器，弹丸初始速度为1.5m/s,发布的欧拉角为外旋ZYX顺序请多加注意**

****
