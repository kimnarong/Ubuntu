#!/usr/bin/python
# -*- coding : utf8 -*-

import rospy
from yh_tutorial_5.srv import yh_srv_5
import sys

def calculate_client(a,b):
    rospy.wait_for_service("yh_service_5")
    try:
        my_service_client=rospy.ServiceProxy("yh_service_5",yh_srv_5)
        resp=my_service_client(a,b)
        return resp.result
    except rospy.ServiceException as e:
        rospy.logerr("Service call failde: %s",e)

if __name__=="__main__":
    rospy.init_node("my_client")
    if len(sys.argv) !=3:
        rospy.loginfo("usage: rosrun yh_tutorial_5 yh_client_5.py a,b")
        rospy.loginfo("a,b:int64 number")
        sys.exit(1)
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    res = calculate_client(a,b)
    rospy.loginfo("send:a=%d,b=%d",a,b)
    rospy.loginfo("receive:result=%d",res)       
    
