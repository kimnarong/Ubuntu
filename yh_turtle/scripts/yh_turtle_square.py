#!/usr/bin/python
# -*- coding: utf8 -*- 

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute
from std_srvs.srv import Empty
import math
import sys
from yh_turtle_triangle import TurtleTriangle

class TurtleSquare(TurtleTriangle):
    

    def run(self):
        self.client_teleport(5.54445 - self.length / 2, 5.544445 - self.length/2 ,0)
        self.client_clear()
        
        loop_rate = rospy.Rate(1)
        msg = Twist()


        while self.pub.get_num_connections() < 1:
            continue

        while not rospy.is_shutdown():
            msg.linear.x = self.length
            msg.angular.z = 0
            self.pub.publish(msg)
            loop_rate.sleep()

            msg.linear.x = 0
            msg.angular.z = math.pi / 2
            self.pub.publish(msg)
            loop_rate.sleep()
        
        

if __name__ == "__main__":
    rospy.init_node("yh_turtle_square")
    try:
        length = float(input("변의 길이를 입력해"))  
        #플로트가 아니면 문자열로 인식
        turtle_square = TurtleSquare(length)
        turtle_square.run()
    
    except:
        pass