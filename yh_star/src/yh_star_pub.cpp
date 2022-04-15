'''손생님풀이'''
#include "ros/ros.h"
#include "yh_star/yh_star_msg.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_star_pub");
    ros::NodeHandle nh;

    ros::Publisher yh_star_pub = nh.advertise<yh_star::yh_star_msg>("yh_star_topic",100);

    ros::Rate loop_rate(2); //0.5초

    yh_star::yh_star_msg msg; //보낼 메세지

    int cnt = 0;

    while(ros::ok())   //오케이 인동안
    {
        msg.stamp = ros::Time::now()
        msg.data = cnt;
        pub.publish(msg)
        cnt++;
        loop_rate.sleep();
    
    }

    return 0;

}