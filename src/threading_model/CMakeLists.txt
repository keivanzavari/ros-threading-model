cmake_minimum_required(VERSION 2.8.3)
project(threading_model)

add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS roscpp rospy)

catkin_package()

add_executable(publisher publisher_node.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})

add_executable(subscriber subscriber_node.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})
