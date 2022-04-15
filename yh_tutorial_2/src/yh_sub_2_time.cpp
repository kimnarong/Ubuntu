#include "ros/ros.h" // ROS 헤더 파일
#include "yh_tutorial_2/yh_msg_2.h" //my_msg 파일 헤더
                                   //빌드 후 자동 생성
//메세지 콜백함수, 서브스크라이버가 메세지를 수신했을 때 동작하는 함수이다.
//입력메세지로는 패키지 이름( topic_tutorial )의 메세지 이름( my_msg )을 받도록 되어있다.                                   

//서브스크라이버 노들이므로 콜백함수 선언
void msgCallback(const yh_tutorial_2::yh_msg_2::ConstPtr& msg) 
{
    // 조건 없이 시간 정보만 출력
    ROS_INFO("%d",msg->stamp.sec);
    ROS_INFO("%d",msg->stamp.nsec);
      
}

//메인 함수
int main(int argc, char **argv)
{
    ros::init(argc,argv,"yh_sub_2_time"); //노드 이름 초기화
    ros::NodeHandle nh; //Ros 시스템과 통신을 위한 노드 핸들 선언
    ros :: Subscriber sub=  nh.subscribe("yh_topic_2",100,msgCallback);

    
    ros::spin();  //스핀이 없으면 바로 종료됨

    return 0;
}
