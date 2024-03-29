#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_tutorial_3.msg import yh_msg_3

def talker():
   
    pub = rospy.Publisher("yh_topic_3",yh_msg_3,queue_size=100)
    rospy.init_node("yh_publisher_3_2",anonymous=True)
    loop_rate = rospy.Rate(5) 
    cnt = 0
    msg = yh_msg_3()


    while not rospy.is_shutdown():
        msg.stamp = rospy.Time.now()
        msg.data = cnt 
        pub.publish(msg)
        cnt += 2
        loop_rate.sleep() 
        
if __name__=="__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        pass





