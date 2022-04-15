#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from turtlesim.srv import SetPen

class TurtlePen:
    def __init__(self):
        self.client_pen = rospy.ServiceProxy("turtle1/set_pen",SetPen)
        
    def run(self):
        
        r = int(input("r값: "))
        g = int(input("g값: "))
        b = int(input("b값: "))
        width = int(input("width값: "))
        off = int(input("off값: "))
        self.client_pen(r,g,b,width,off)
if __name__ == "__main__":
    rospy.init_node("yh_turtle_pen")
    turtle_pen = TurtlePen()
    while not rospy.is_shutdown(): #계속 값을 받을 수 있게 설정
        turtle_pen.run()
