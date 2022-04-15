#include "ros/ros.h"
#include "yh_sum/yh_sum_msg.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_sum_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<yh_sum::yh_sum_msg>("yh_sum_topic", 100);

    ros::Rate loop_rate(5);

    yh_sum::yh_sum_msg msg;

    int cnt = 0;

    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        msg.data = cnt;
        cnt++;
        pub.publish(msg);
        loop_rate.sleep();
    }

    return 0;

}