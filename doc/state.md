# 比赛阶段任务说明

文档按等级分级说明：Level 1（STAGE_1/2）、Level 2（STAGE_3/4）、Level 3（STAGE_5）。

统一要求：
- 话题通信（Level 1/2）：/vision/target，消息类型 referee_pkg::msg::MultiObject
- 服务通信（Level 3）：/referee/hit_arror，服务类型 referee_pkg::srv::HitArmor
- 时间戳：header.stamp 必须与相机图像的时间戳一致
- 输出：裁判系统在 results/ 生成阶段 JSON 与 .sha256 校验文件

---

## Level 1（STAGE_1 / STAGE_2）

Level 1 共包含 2 个阶段任务，总分 40 分（各阶段 20 分）。

### 一、评分标准

| 评分维度 | 分值 | 说明                                   |
| :------- | :--- | :------------------------------------- |
| 准确度   | 15分 | 识别结果与真值的误差                   |
| 识别频率 | 5分  | 单位时间内有效识别帧数（基于相机帧率） |

评分区间（两部分加权求和）：
```cpp
// FPS 评分（频率）
const std::array<std::pair<double, double>, 11> REVISED_FPS_SCORES = {{
    {40.0, 10.0},
    {35.0, 9.0},
    {30.0, 8.0},
    {25.0, 7.0},
    {20.0, 6.0},
    {15.0, 5.0},
    {12.0, 4.0},
    {8.0, 3.0},
    {5.0, 2.0},
    {3.0, 1.0},
    {0.0, 0.0}
}};

// 位置误差评分（准确度）
const std::array<std::pair<double, double>, 11> REVISED_POSITION_SCORES = {{
    {0.1, 10.0},
    {0.15, 9.0},
    {0.2, 8.0},
    {0.3, 7.0},
    {0.4, 6.0},
    {0.5, 5.0},
    {0.6, 4.0},
    {0.8, 3.0},
    {1.0, 2.0},
    {1.5, 1.0},
    {2.0, 0.0}
}};
```

### 二、通用接口要求（Level 1）

- 话题名称：`/vision/target`
- 消息类型：`referee_pkg::msg::MultiObject`

字段说明：
| 字段类型          | 字段名        | 要求与说明            |
| :---------------- | :------------ | :-------------------- |
| `std_msgs/Header` | `header`      | 与相机图像时间戳一致  |
| `uint32`          | `num_objects` | 与 `objects` 数量一致 |
| `Object[]`        | `objects`     | 具体物体信息数组      |

### STAGE_1：圆环识别（Ring_red）

- 发布要求：
  - `num_objects` 必须为 2
  - `objects[0]` 外圆，`objects[1]` 内圆
- 关键点（每圆 4 点，逆时针，左点起始）：
  1. 左点（起始）
  2. 下点
  3. 右点
  4. 上点
- 评分要点：
  - 圆心位置差（RingCirclePositionError）计分
  - 位置误差（position_error）计分
  - 姿态误差（orientation_error）不计分
- JSON 示例：
```json
{
  "RaceStage1": {
    "average_orientationerror": 0.0,
    "average_positionerror": 0.043,
    "average_ringcentererror": 0.475,
    "fps": 27,
    "run_id": "xxxx",
    "score": 13.0,
    "target_type": "Ring_red",
    "timestamp": "2025-09-30T10:41:31Z"
  },
  "team_name": "TEAM1"
}
```

### STAGE_2：箭头识别（Arrow_red）

- 发布要求：
  - `objects` 中必须包含类型为 `Arrow_red` 的对象，否则该帧记 0 分
- 关键点（4 点，顺时针，左上角起始）：
  1. 左上角（起始）
  2. 右上角
  3. 右下角
  4. 左下角
- 评分要点：
  - 位置误差（position_error）
  - 方向误差（direct/orientation_error）
- JSON 示例：
```json
{
  "RaceStage2": {
    "average_directerror": 2.567,
    "average_positionerror": 0.876,
    "fps": 48,
    "max_positionerror": 3.064,
    "run_id": "xxxx",
    "score": 9.0,
    "target_type": "Arrow_red",
    "timestamp": "2025-09-30T11:07:29Z"
  },
  "team_name": "TEAM1"
}
```

---

## Level 2（STAGE_3 / STAGE_4）

Level 2 共包含 2 个阶段任务，总分 40 分（各阶段 20 分）。通信方式与 Level 1 相同（话题）。



常用计分字段：
- `average_numdetecterror`、`max_numdetecterror`
- `average_orientationerror`、`max_orientationerror`
- 某些阶段得分可能按组加权或缩放（例如 `score / 4.0`）

### 二、通用接口要求（Level 2）

- 话题名称：`/vision/target`
- 消息类型：`referee_pkg::msg::MultiObject`
- 要求：
  - `objects` 至少涵盖要求发布的四个装甲板类型，否则该阶段记 0 分
  - 角点顺序：左下角起始，逆时针方向
  - `header.stamp` 对齐相机时间戳
  - `num_objects` 与 `objects` 数量一致

### STAGE_3：装甲板识别（Armor_xxx）

### 一、评分标准（示例字段）

| 评分维度 | 分值 | 说明                        |
| :------- | :--- | :-------------------------- |
| 检测准确 | 10分 | 数字/装甲板角点与真值的偏差 |
| 识别频率 | 5分  | 单位时间内有效识别帧数      |

- 目标：识别赛场指定的装甲板目标集（如 armor_red_1/2/3/4 等）
- 评分要点：
  - 数量检测误差（numdetecterror）
  - 姿态误差（orientationerror）
  - 频率（fps）
- JSON 示例（单目标）：
```json
{
  "RaceStage3": {
    "average_numdetecterror": 0.238,
    "average_orientationerror": 1.967,
    "fps": 46,
    "max_numdetecterror": 0.238,
    "max_orientationerror": 1.967,
    "run_id": "xxxx",
    "score": 2.0,
    "target_type": "armor_red_1",
    "timestamp": "2025-09-30T11:21:13Z"
  },
  "team_name": "TEAM1"
}
```

### STAGE_4：数字识别（Digit/Number_xxx）
| 评分维度 | 分值 | 说明                        |
| :------- | :--- | :-------------------------- |
| 检测准确 | 15分 | 数字/装甲板角点与真值的偏差 |
| 识别频率 | 5分  | 单位时间内有效识别帧数      |

- 目标：识别场景中的数字/编号目标集
- 评分要点与 STAGE_3 一致（字段名相同），可能采用组内加权或缩放
- JSON 示例（多目标列表）：
```json
{
  "RaceStage4": [
    {
      "average_numdetecterror": 0.12,
      "average_orientationerror": 1.31,
      "fps": 44,
      "max_numdetecterror": 0.42,
      "max_orientationerror": 2.02,
      "run_id": "xxxx",
      "score": 1.5,
      "target_type": "number_2",
      "timestamp": "2025-09-30T11:25:13Z"
    },
    {
      "average_numdetecterror": 0.09,
      "average_orientationerror": 0.98,
      "fps": 47,
      "max_numdetecterror": 0.21,
      "max_orientationerror": 1.45,
      "run_id": "xxxx",
      "score": 2.0,
      "target_type": "number_5",
      "timestamp": "2025-09-30T11:25:13Z"
    }
  ],
  "team_name": "TEAM1"
}
```

---

## Level 3（STAGE_5）

Level 3 为服务通信与击打评测阶段，总分 20 分。

### 一、评分标准（示例字段）

| 评分维度      | 分值   | 说明                            |
| :------------ | :----- | :------------------------------ |
| 命中精度      | 12.5分 | 命中精度等级（precision level） |
| 成功次数/响应 | 12.5分 | 有效击打成功次数与服务响应能力  |

常用计分字段：
- `hitarmor_successcount`、`average_precisonlevel`、`score`

### 二、接口要求（Level 3，服务通信）

- 服务名称：`/referee/hit_arror`
- 服务类型：`referee_pkg::srv::HitArmor`
- 要求：
  - 选手实现服务端，接收裁判系统客户端请求
  - 裁判系统设定弹丸击打速度为 1.5 m/s
  - Response 欧拉角采用外旋 ZYX 顺序（如需改为内旋 ZYX，可赛前统一调整）
  - 严格处理 request/response 的时间戳与坐标系约定

### STAGE_5：击打装甲

- 目标：在裁判系统的请求下，返回击打姿态与结果，并完成命中评估
- JSON 示例：
```json
{
  "RaceStage5": {
    "average_precisonlevel": 0.254,
    "hitarmor_successcount": 0,
    "run_id": "xxxx",
    "score": 0.0,
    "timestamp": "2025-09-30T11:38:55Z"
  },
  "team_name": "TEAM1"
}
```

---

## 实现与调试建议（通用）

- 时间戳对齐：`header.stamp` 与相机图像消息严格一致，否则会出现数据无法匹配或计分异常。
- 关键点顺序：各阶段点序要求严格，错误顺序会显著影响误差与得分。
- 文件输出：results/ 下按阶段生成 JSON 和 `.sha256` 校验文件。

最后更新时间：2025-11-29  
当前版本：v1.0.1