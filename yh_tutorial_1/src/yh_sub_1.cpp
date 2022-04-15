#include "ros/ros.h" // ROS 헤더 파일
#include "yh_tutorial_1/yh_msg_1.h" //my_msg 파일 헤더
                                   //빌드 후 자동 생성
//메세지 콜백함수, 서브스크라이버가 메세지를 수신했을 때 동작하는 함수이다.
//입력메세지로는 패키지 이름( topic_tutorial )의 메세지 이름( my_msg )을 받도록 되어있다.                                   



void msgCallback(const yh_tutorial_1::yh_msg_1::ConstPtr& msg) 
{

    // class Bclass{
    // int c =10;
    // }
    // Bclass b;
    // Bclass *a=&b;
    // print("%d",*a->c);
    // *a.c ==a->c
    // *포인터의 개념

                             //*msg.stamp.sec
    ROS_INFO("receive msg=%d",msg->stamp.sec); //stamp.sec를 표시한다.
    ROS_INFO("receive msg=%d",msg->stamp.nsec); //stamp.nsec를 표시한다.
    ROS_INFO("receive msg=%d",msg->data); //data를 표시한다.
}

//메인 함수
int main(int argc, char **argv)
{
    ros::init(argc,argv,"yh_sub_1"); //노드 이름 초기화
    ros::NodeHandle nh; //Ros 시스템과 통신을 위한 노드 핸들 선언

    //서브스크라이버 선언
    //패키지 ( topic_tutorial )의 메세지 ( my_msg )을 이용한 서브스크라이버 ( my_sub )를 작성한다.
    //토픽명은 ( my_topic )이며, 서브스크라이버큐(quequ) 사이즈를 100으로 설정한다.
    //콜백함수는 (msgCallback)이다.
    ros :: Subscriber yh_sub=  nh.subscribe("yh_topic_1",100,msgCallback);

    //콜백 함수 호출을 위한 함수, 메시지가 수신되기를 대기
    //수신되었을 경우 콜백 함수를 호출한다.
    ros::spin();  //스핀이 없으면 바로 종료됨

    return 0;
}
