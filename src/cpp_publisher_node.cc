
#include <string>
#include <thread>

#include "ros/ros.h"
#include "std_msgs/String.h"

class CustomPublisher {
 public:
  CustomPublisher(const std::string& string_to_publish) : custom_str(string_to_publish) {
    ros::NodeHandle nh;
    pub = nh.advertise<std_msgs::String>("/foo", 1, true);
    run_thread = std::thread([this] { start(); });
  }

  void start() {
    std_msgs::String msg;
    msg.data = custom_str;
    ros::Rate loop_rate(1);
    while (ros::ok()) {
      pub.publish(msg);
      loop_rate.sleep();
    }
  }

 private:
  ros::Publisher pub;
  std::string custom_str;
  std::thread run_thread;
};

int main(int argc, char** argv) {
  std::string id = "";
  if (argc > 1) {
    id = argv[1];
  }
  ros::init(argc, argv, "pub_" + id);
  auto node_name = ros::this_node::getName();
  ROS_WARN_STREAM("Started node " << node_name);

  CustomPublisher custom_publisher(node_name);

  ros::spin();

  return 0;
}
