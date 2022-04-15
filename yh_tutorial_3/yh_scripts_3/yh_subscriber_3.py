#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy 
from yh_tutorial_3.msg import yh_msg_3

def msgCallback(msg):
    
    rospy.loginfo("%d",msg.stamp.secs) 
    rospy.loginfo("%d",msg.stamp.nsecs) 
    rospy.loginfo("%d",msg.data)


def listener():
    rospy.init_node("yh_subscriber_3",anonymous=True)
    rospy.Subscriber("yh_topic_3",yh_msg_3,msgCallback)

    rospy.spin() 

if __name__=="__main__":
    listener()