#include "ros/ros.h"
#include "yh_sum/yh_sum_msg.h"


int old_data = 0;

void msgCallback(const yh_sum::yh_sum_msg::ConstPtr& msg)
{
    printf("%d\n",old_data + msg->data);
    old_data = msg->data;

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_sum_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub =  nh.subscribe("yh_sum_topic", 100, msgCallback);
    ros::spin();  //프로그램 종료 방지 대기

    return 0;

}
