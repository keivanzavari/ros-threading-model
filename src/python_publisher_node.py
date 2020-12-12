#!/usr/bin/env python3

import threading
import sys

import rospy
from std_msgs.msg import String

global proc_id
proc_id = ""


def publisher():
    msg = String(proc_id)
    r = rospy.Rate(1)
    pub = rospy.Publisher('foo', String, queue_size=1)
    while not rospy.is_shutdown():
        pub.publish(msg)
        r.sleep()


def main():
    global proc_id
    if sys.argv[1]:
        proc_id = sys.argv[1]
    rospy.init_node(f"pub_{proc_id}")
    rospy.logwarn(f"Publisher node {rospy.get_name()} started.")
    thread = threading.Thread(target=publisher)
    thread.start()
    rospy.spin()


if __name__ == '__main__':
    main()
