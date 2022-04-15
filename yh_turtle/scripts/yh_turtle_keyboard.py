#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist

 
'''본인이 알아볼 수 있게 메세지 이름 직관적으로 짓기'''


pub = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=1)
def keyboardCallback(msg):
    pub.publish(msg)

def listener():
    rospy.init_node("yh_turtle_keyboard")
    sub = rospy.Subscriber("/cmd_vel",Twist,keyboardCallback)
    rospy.spin()

if __name__=="__main__":
    listener()