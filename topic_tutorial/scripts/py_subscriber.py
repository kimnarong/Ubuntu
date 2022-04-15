#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy 
from topic_tutorial.msg import my_msg

def msgCallback(msg):
    rospy.loginfo("receive message: %d",msg.stamp.secs)
    rospy.loginfo("receive message: %d",msg.stamp.nsecs)
    rospy.loginfo("receive message: %d",msg.data)

def listener():
    rospy.init_node("py_subscriber",anonymous=True)
    rospy.Subscriber("my_topic",my_msg,msgCallback)

    rospy.spin() 
if __name__=="__main__":
    listener()