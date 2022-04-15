'''선생님 풀이 '''
#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_divisor.msg import yh_divisor_msg

def msgCallback(msg):    
    n = msg.data   
    """ 정수의 약수를 모두 출력 """
    s = ""

    for i in range(1, n+1):
        if n % i ==0:
            s += str(i)
            s += " "
    print(s)              
    

def listner():
    rospy.init_node("yh_star_sub", anonymous=True)
    rospy.Subscriber("yh_star_topic", yh_divisor_msg, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()