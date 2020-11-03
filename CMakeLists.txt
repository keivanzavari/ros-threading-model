cmake_minimum_required(VERSION 2.8.3)
project(threading_model)

add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs)
include_directories(${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(publisher src/publisher_node.cc)
target_link_libraries(publisher ${catkin_LIBRARIES})

add_executable(subscriber src/subscriber_node.cc)
target_link_libraries(subscriber ${catkin_LIBRARIES})
