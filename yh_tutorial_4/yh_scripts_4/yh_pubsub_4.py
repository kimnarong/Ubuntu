#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_tutorial_4.msg import yh_msg_4

pub = rospy.Publisher("raspberry",yh_msg_4,queue_size=100)

def msgCallback(msg):
    if msg.data % 5==0:
        pub.publish(msg)


def listener():
    rospy.init_node("yh_pubsub_4",anonymous=True)
    rospy.Subscriber("yh_topic_4",yh_msg_4,msgCallback)
    rospy.spin() 


        
if __name__=="__main__":
    listener()
