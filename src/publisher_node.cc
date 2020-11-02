
#include <string>

#include "ros/ros.h"
#include "std_msgs/String.h"

class CustomPublisher {
 public:
  CustomPublisher(const std::string& string_to_publish)
      : custom_str(string_to_publish) {
    ros::NodeHandle nh;
    ros::NodeHandle priv_nh("~");

    // advertise message to set shot
    pub = nh.advertise<sv_msgs::Framing>("/foo", 1, true);
    start();
  }

  void start() {
    std_msgs::String msg;
    msg.data = custom_str;
    while (ros::ok()) {
      pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
    }
  }

 private:
  ros::Publisher pub;
  std::string custom_str;
};

int main(int argc, char** argv) {
  ros::init(argc, argv, "pub_" + argv[1]);
  auto node_name = ros::this_node::get_name();
  ROS_WARN_STREAM("Started node " << node_name);

  CustomPublisher custom_publisher(nh, priv_nh);

  ros::spin();

  return 0;
}
