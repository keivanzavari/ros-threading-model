cmake_minimum_required(VERSION 2.8.3)
project(threading_model)

add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs)
include_directories(${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(cpp_publisher_node src/cpp_publisher_node.cc)
target_link_libraries(cpp_publisher_node ${catkin_LIBRARIES})

add_executable(cpp_subscriber_node src/cpp_subscriber_node.cc)
target_link_libraries(cpp_subscriber_node ${catkin_LIBRARIES})
