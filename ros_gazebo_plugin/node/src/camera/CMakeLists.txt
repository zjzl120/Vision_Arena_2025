cmake_minimum_required(VERSION 3.8)
project(camera)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
set(pose_msg_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../msg/install/pose_msg/share/pose_msg/cmake")
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(gazebo REQUIRED)
find_package(pose_msg REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS}
${CMAKE_CURRENT_SOURCE_DIR}/include/camera
)
link_directories(${GAZEBO_LIBRARY_DIRS})
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(${PROJECT_NAME} SHARED
  src/new_camera.cpp 
)
ament_target_dependencies(${PROJECT_NAME}
  "rclcpp"
  "sensor_msgs"
  "gazebo"
  "pose_msg"
)
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
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

ament_package()