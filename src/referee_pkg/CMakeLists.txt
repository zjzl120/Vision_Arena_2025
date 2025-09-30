cmake_minimum_required(VERSION 3.8...3.10)
project(referee_pkg)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 查找依赖包
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(geometry_msgs REQUIRED) 
find_package(OpenCV REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(pose_msg REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(nlohmann_json REQUIRED CONFIG)
find_package(OpenSSL REQUIRED)
include_directories( 
  include/
  include/referee_pkg/
)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wno-deprecated-declarations)
endif()
# 生成消息接口
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Target.msg"
  "msg/Object.msg"
  "msg/MultiObject.msg"
  "msg/RaceStage.msg"
  "srv/HitArror.srv"
  DEPENDENCIES geometry_msgs std_msgs
)

# 添加可执行文件 - node_01
add_executable(referee src/referee.cpp src/utils.cpp)
ament_target_dependencies(referee
  rclcpp
  std_msgs
  gazebo_msgs
  geometry_msgs
  OpenCV 
  tf2
  tf2_ros
  pose_msg
)

# 链接OpenCV库
target_link_libraries(referee 
  ${OpenCV_LIBS} 
  nlohmann_json::nlohmann_json   
  OpenSSL::SSL
  OpenSSL::Crypto)

# 为node_01添加消息类型支持（新方法）
rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(referee ${typesupport_target})
# 安装node_01
install(TARGETS referee
  DESTINATION lib/${PROJECT_NAME}
)

# 包含OpenCV头文件
include_directories(${OpenCV_INCLUDE_DIRS})

# 安装消息头文件
install(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp/
  DESTINATION include
  PATTERN "*.hpp"
)
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()