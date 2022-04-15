#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy 
from yh_tutorial_4.msg import yh_msg_4

def msgCallback(msg):
    
    rospy.loginfo("%d",msg.stamp.secs) 
    rospy.loginfo("%d",msg.stamp.nsecs) 
    rospy.loginfo("%d",msg.data)


def listener():
    rospy.init_node("yh_subscriber_4",anonymous=True)
    rospy.Subscriber("raspberry_pie",yh_msg_4,msgCallback)

    rospy.spin() 

if __name__=="__main__":
    listener()