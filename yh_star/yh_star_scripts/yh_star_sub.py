'''선생님 풀이 2중 for문 사용'''
#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_star.msg import yh_star_msg

def msgCallback(msg):
    n = msg.data
    s = ""

    for i in range(1, n//2+1):
        for j in range(i):
            s += "*"
        s += "\n"    
    for i in range(n//2+1,n+1):
        for j in range(n - i + 1):
            s += "*"
        s += "\n"
    print(s)        
    

def listner():
    rospy.init_node("yh_star_sub", anonymous=True)
    rospy.Subscriber("yh_star_topic", yh_star_msg, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()