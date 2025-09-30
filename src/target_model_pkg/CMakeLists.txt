cmake_minimum_required(VERSION 3.8)
project(target_model_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(pluginlib REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(pose_msg REQUIRED)
# 找 Gazebo
find_package(gazebo REQUIRED)
find_package(ignition-math6 REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
include_directories(
  include
  ${GAZEBO_INCLUDE_DIRS}
  ${IGNITION-MATH6_INCLUDE_DIRS}
)


# 定义库名称
set(library_name ${PROJECT_NAME}_lib)
# 创建共享库
add_library(${library_name} SHARED src/target_action.cpp)
# 指定库的依赖关系
ament_target_dependencies(${library_name}   rclcpp
  pluginlib
  std_msgs
  geometry_msgs
  pose_msg

)

target_link_libraries(${library_name}
  ${GAZEBO_LIBRARIES}           # Gazebo 核心库
  ${IGNITION-MATH6_LIBRARIES}   # Ignition Math
)

target_include_directories(${library_name} PUBLIC include)
# 安装库文件到指定目录
install(TARGETS ${library_name}
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib
)

# 安装头文件到指定目录
install(DIRECTORY include/
 DESTINATION include/)
install(DIRECTORY launch urdf  
  DESTINATION share/${PROJECT_NAME}
)



ament_package()
