#!/usr/bin/env python3

import threading
import sys

import rospy
from std_msgs.msg import String


def callback(msg):
    print("Msg from %s on thread %s" % (msg.data, threading.current_thread()))


def main():
    suffix = ""
    if sys.argv[1]:
        suffix = sys.argv[1]
    rospy.init_node(f'sub_{suffix}')
    print(f"Subscriber node {rospy.get_name()} started.")
    rospy.Subscriber('foo', String, callback, queue_size=1)
    rospy.spin()


if __name__ == '__main__':
    main()
