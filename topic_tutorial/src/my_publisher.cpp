#include "ros/ros.h" // ROS 헤더파일
#include "topic_tutorial/my_msg.h" //my_msg 메세지 헤더파일 (패키지 않에 헤더파일)
                                   //빌드 후 자동 생성
//메인함수
int main(int argc,char ** argv) 
{
    ros::init(argc,argv,"my_publisher"); //노드 이름 초기화
    ros::NodeHandle nh; //ROS 시스템과 통신을 위한 노드 핸들 선언

    //퍼플리셔 선언
    //패키지( topic_tutorial )의 메세지파일( my_msg )을 이용한
    //퍼블리셔( my_pub )를 작성한다. 토픽은 ( my_topic )이며,
    //퍼플리셔큐(queue) 사이즈를 100개로 설정한다.
    ros::Publisher my_pub = nh.advertise<topic_tutorial::my_msg>("my_topic",100);

    ros::Rate loop_rate(10); //루프 주기를 10Hz로 설정한다. 0.1초

    topic_tutorial::my_msg msg;
    int cnt = 0;

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); //현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt; //cnt의 변수값을 msg의 data에 담는다.
        ROS_INFO("send msg=%d",msg.stamp.sec); //stamp.sec를 표시한다.
        ROS_INFO("send msg=%d",msg.stamp.nsec); //stamp.nsec를 표시한다.
        ROS_INFO("send msg=%d",msg.data); //data를 표시한다.
        cnt++;
        my_pub.publish(msg); //my_pub이 msg 를 퍼플리시한다.
        loop_rate.sleep(); //위에서 정한 주기에 따라 sleep한다.
    }


    return 0;
}                                 