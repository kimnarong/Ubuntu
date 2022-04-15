#include "ros/ros.h" // ROS 헤더파일
#include "yh_tutorial_2/yh_msg_2.h" //my_msg 메세지 헤더파일 (패키지 않에 헤더파일)
                                   

int main(int argc,char **argv) 
{
    ros::init(argc,argv,"yh_pub_2"); //노드 이름 초기화
    ros::NodeHandle nh; //ROS 시스템과 통신을 위한 노드 핸들 선언

    //퍼플리셔 선언
    //패키지( topic_tutorial )의 메세지파일( my_msg )을 이용한
    //퍼블리셔( my_pub )를 작성한다. 토픽은 ( my_topic )이며,
    //퍼플리셔큐(queue) 사이즈를 100개로 설정한다.
    

    ros::Rate loop_rate(5); //루프 주기를 10Hz로 설정한다. 0.1초
    int cnt = 0;

    ros::Publisher pub = nh.advertise<yh_tutorial_2::yh_msg_2>("yh_topic_2",100);
    yh_tutorial_2::yh_msg_2 msg;  
    

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); //현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt; //cnt의 변수값을 msg의 data에 담는다.
        pub.publish(msg);
        cnt++;
        loop_rate.sleep();


        
    }

    return 0;
}                                 