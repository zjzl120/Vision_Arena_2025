FROM vision-vrena-2025:v0.1.2

COPY ./build /home/va/Vision-Vrena-2025/build
COPY ./install /home/va/Vision-Vrena-2025/install
COPY ./src/target_model_pkg/plugins/lib /home/va/Vision-Vrena-2025/src/target_model_pkg/plugins/lib
COPY ./src/player_pkg /home/va/Vision-Vrena-2025/src/player_pkg 
# 将选手所需程序移入镜像
WORKDIR /home/va/Vision-Vrena-2025
# 设置工作空间
RUN apt-get update && apt-get upgrade -y && mkdir -p src/referee_pkg/results && apt-get install -y ros-humble-xacro ros-humble-gazebo-ros-pkgss
# 下载一些必要的包