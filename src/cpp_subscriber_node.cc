#include <thread>

#include <string>

#include "ros/ros.h"
#include "std_msgs/String.h"

class CustomSubscriber {
 public:
  CustomSubscriber(ros::NodeHandle& nh) { sub = nh.subscribe("/foo", 10, &CustomSubscriber::listen, this); }

  void listen(const std_msgs::String& msg) {
    std::cout << "Msg from " << msg.data << " on thread " << std::this_thread::get_id() << "\n";
  }

 private:
  ros::Subscriber sub;
};

int main(int argc, char** argv) {
  std::string id = "";
  if (argc > 1) {
    id = argv[1];
  }
  ros::init(argc, argv, "sub_" + id);
  auto node_name = ros::this_node::getName();
  ROS_WARN_STREAM("Started node " << node_name);

  ros::NodeHandle nh;
  CustomSubscriber custom_subscriber(nh);

  ros::spin();

  return 0;
}
