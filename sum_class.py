#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_sum.msg import yh_sum_msg

class MyClass:
    def __int__(self):
        self.sub = rospy.SubscribeListener("yh_sum_topic",yh_sum_msg, self.msgCallback)
        self.old_data = 0
    
    def msgCallback(self,msg):
            
        print(self.old_data + msg.data)
        self.old_data = msg.data
        

def listner():
    rospy.init_node("yh_sum_sub", anonymous=True)
    my_class = MyClass()    
    rospy.spin()

if __name__ == "__main__":
    listner()