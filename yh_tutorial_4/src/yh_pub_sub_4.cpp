#include "ros/ros.h" // ROS 헤더파일   
#include "yh_tutorial_4/yh_msg_4.h" //my_msg 메세지 헤더파일 (패키지 않에 헤더파일)
                                 

ros::Publisher pub;  //전역변수로 선언해주기!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg) //메세지 받기(거의 고정 상태)
{
    if (msg->data %5==0)
    {
        pub.publish(msg);
    }

}
int main(int argc,char **argv) 
{
    ros::init(argc,argv,"yh_pub_sub_4"); //노드 이름 초기화
    ros::NodeHandle nh; //ROS 시스템과 통신을 위한 노드 핸들 선언

    pub=nh.advertise<yh_tutorial_4::yh_msg_4>("raspberry_pie",100); 
    ros::Subscriber sub = nh.subscribe("yh_topic_4",100,msgCallback); 

    ros::spin(); 
    
    return 0;
}                                 