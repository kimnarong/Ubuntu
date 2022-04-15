#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
#standard msg package/msg folder, Twist
from geometry_msgs.msg import Twist
#to use pi
import math
#to get radius in main
import sys
#teleport turtlesim
from turtlesim.srv import TeleportAbsolute
#clear pen (looked up info)
from std_srvs.srv import Empty



class TurtleCircle():
    def __init__(self, radius):
        # make a publisher
        self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)
        #make turtle spawn
        self.client_teleport = rospy.ServiceProxy("/turtle1/teleport_absolute", TeleportAbsolute)

        #to earse pen
        self.client_clear = rospy.ServiceProxy("/clear", Empty)

        # receive radius when object is created
        self.radius = radius
    
    def run(self):
        msg = Twist()
        #teleport from center spawn to top
        self.client_teleport(5.544445, 5.544445 + self.radius, 0)
        self.client_clear()
        # if radius is r, in order to draw a circle:
        # -msg.linear.x = circumference per sec = 2 pi r / s
        # -msg.angular.x = 2 pi / s
        # -so the ratio is r vs 1 to dra a circle
        msg.linear.x = self.radius + 1
        # + is counterclockwise, - is clockwise
        msg.angular.z = -1.0

        loop_rate = rospy.Rate(1)
        while not rospy.is_shutdown():
            self.pub.publish(msg)
            loop_rate.sleep()


if __name__ == "__main__":

    rospy.init_node("yh_turtle_circle")
    # to get radius
    radius = float(sys.argv[1])
    turtle_circle = TurtleCircle(radius)
    turtle_circle.run()