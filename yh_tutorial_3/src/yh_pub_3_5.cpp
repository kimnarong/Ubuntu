#include "ros/ros.h" // ROS 헤더파일
#include "yh_tutorial_3/yh_msg_3.h" //my_msg 메세지 헤더파일 (패키지 않에 헤더파일)
                                   
//★3_2 랑 똑같이 쓸때 바꿔야하는 부분

int main(int argc,char **argv) 
{
    ros::init(argc,argv,"yh_pub_3_5"); //노드 이름 초기화     ★ 3_2노드이름
    ros::NodeHandle nh; //ROS 시스템과 통신을 위한 노드 핸들 선언

    //퍼플리셔 선언
    //패키지( topic_tutorial )의 메세지파일( my_msg )을 이용한
    //퍼블리셔( my_pub )를 작성한다. 토픽은 ( my_topic )이며,
    //퍼플리셔큐(queue) 사이즈를 100개로 설정한다.
    

    ros::Rate loop_rate(2); //루프 주기를 2Hz로 설정한다. 0.5초    ★주기
    int cnt = 0;

    ros::Publisher pub = nh.advertise<yh_tutorial_3::yh_msg_3>("yh_topic_3",100);
    yh_tutorial_3::yh_msg_3 msg;  
    

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); //현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt; //cnt의 변수값을 msg의 data에 담는다.
        pub.publish(msg);
        cnt += 5;   //★ 카운트 숫자
        loop_rate.sleep();


        
    }

    return 0;
}                                 