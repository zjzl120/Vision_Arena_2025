## launch文件参数说明及使用方法
### referee_pkg_launch.xml
```cpp
<arg name="TeamName" default="TeamA" description = "队伍名称"/>
<arg name="StageSelect" default="5" description = "起始阶段选择 : 1,2,3,4,5"/>
<arg name="ModeSelect" default="0" description = "模式选择 {0: 恒定模式 , 1 : 顺序模式}"/>
```

<font style="color:#DF2A3F;">特别注意: </font>恒定模式为裁判系统永远执行初始阶段的处理,顺序模式为顺序进行,若为<font style="color:#DF2A3F;">顺序模式</font>每个阶段裁判系统都会<font style="color:#DF2A3F;">重复执行十次</font>，<font style="color:#DF2A3F;">每次持续时间10s</font>,最后成绩取10次处理后的最终成绩

```cpp
ros2 launch referee_pkg referee_pkg_launch.xml \
    TeamName:="TEAMENAME" \
    StageSelect:=0 \
    ModeSelect:=1
```
### target_launch.xml
```cpp
<arg name="model" default="$(find target_model_pkg)/urdf/sphere/sphere.sdf" description = "模型路径"/>
<arg name="model_name" default="Ring_red" description = "模型名称"/>
<arg name="x" default="3.0" description = "x坐标"/>
<arg name="y" default="8.0" description = "y坐标"/>
<arg name="z" default="2.0" description = "z坐标"/>
```

```cpp
# 同时修改所有参数
ros2 launch target_model_pkg your_launch_file.py \
    model:=src/target_model_pkg/urdf/sphere/sphere.sdf\
    model_name:=Ring_red \
    x:=3.0 \
    y:=8.0 \
    z:=2.0 \
    roll:=0.78
```

