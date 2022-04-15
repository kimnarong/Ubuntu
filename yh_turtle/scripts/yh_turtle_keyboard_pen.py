#!/usr/bin/python
# -*- coding: utf8 -*-

from sys import setdlopenflags
import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import SetPen, SetPenRequest

class MyTurtle:
    def __init__(self):
        self.sub = rospy.Subscriber("cmd_vel",Twist,self.msgCallback)
        self.pub = rospy.Publisher("turtle1/cmd_vel",Twist,queue_size=1)
        # service name  = turtle1/set_pen
        # service type = turtlesim/SetPen
        self.client_pen = rospy.ServiceProxy("turtle1/set_pen",SetPen)
        self.pen = SetPenRequest()
        self.pen = widith = 3 #초기값 3
   #메세지가 들어왔을 때 실행 할 메세지 콜백 함수 만들어 주기
    def msgCallback(self,msg): 

        if msg.linear.z > 0:
           
           # self.pub.publish(msg)
           self.pen.r = int(input("r:  "))
           self.pen.g = int(input("g:  "))
           self.pen.b = int(input("b:  "))
           self.client_pen(self.pen)
            
        elif msg.linear.z < 0:
          
            self.pen.width = int(input("width:  "))
            self.client_pen(self.pen)

        else:
            self.pub.publish(msg)

            
if __name__=="__main__":
    rospy.init_node("yh_turtle_keyboard_pen")
    my_turtle = MyTurtle()
    rospy.spin()
