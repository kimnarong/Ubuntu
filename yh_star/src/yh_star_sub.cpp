#include "ros/ros.h"
#include "yh_star/yh_star_msg.h"


void msgCallback(const yh_star::yh_star_msg::ConstPtr& msg)
{
    int n = msg.-.>data;
    for(int i = 0; i<n/2; i++)
    {
            for (int j = 0; j < i+1; j++)
            {
                printf("*");
            }
            printf("\n");
    }
    for (int i = n/2; i<n; i++)
    {
            for(int j =n; j>i; j--)
            {
                pirntf("*");
            }
            printf("\n");
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_star_sub");
    ros::NodeHandle nh;

    ros::Subscriber yh_sub =  nh.subscribe("yh_star_topic", 100, msgCallback);

    ros::spin();  //프로그램 종료 방지 대기

    return 0;

}
