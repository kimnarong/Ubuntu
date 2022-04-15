#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_sum.msg import yh_sum_msg

old_data = 0
def msgCallback(msg):
    global old_data
    print(old_data + msg.data)
    old_data = msg.data
    

def listner():
    rospy.init_node("yh_sum_sub", anonymous=True)
    rospy.Subscriber("yh_sum_topic", yh_sum_msg, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()