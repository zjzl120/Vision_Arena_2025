cmake_minimum_required(VERSION 3.8...3.10)
project(player_pkg)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 查找依赖包
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(geometry_msgs REQUIRED) 
find_package(OpenCV REQUIRED)
find_package(pose_msg REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(referee_pkg REQUIRED)
find_package(sensor_msgs REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wno-deprecated-declarations)
endif()

add_executable(TestNode src/test.cpp)
ament_target_dependencies(TestNode
  rclcpp
  std_msgs
  OpenCV 
  geometry_msgs
  cv_bridge
  pose_msg
  referee_pkg
)
# 链接OpenCV库
target_link_libraries(TestNode ${OpenCV_LIBS})

# 为Vision_test添加消息类型支持（新方法）
target_link_libraries(TestNode ${typesupport_target})

# 安装Vision_test
install(TARGETS TestNode
  DESTINATION lib/${PROJECT_NAME}
)

# 包含OpenCV头文件
include_directories(${OpenCV_INCLUDE_DIRS})


ament_package()
