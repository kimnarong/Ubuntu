#include "ros/ros.h" // ROS 헤더 파일
#include "yh_tutorial_4/yh_msg_4.h" //my_msg 파일 헤더
                                   //빌드 후 자동 생성
//메세지 콜백함수, 서브스크라이버가 메세지를 수신했을 때 동작하는 함수이다.
//입력메세지로는 패키지 이름( topic_tutorial )의 메세지 이름( my_msg )을 받도록 되어있다.                                   

//서브스크라이버 노들이므로 콜백함수 선언
void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg) //메세지 받기(거의 고정 상태)
{
    // 메세지를 받아서 로스인포로 메세지 안의 시간 정보와 숫자 정보 출력하기
    ROS_INFO("time1 = %d",msg->stamp.sec);    //시간
    ROS_INFO("time2 = %d",msg->stamp.nsec);   //시간
    ROS_INFO("nember = %d",msg->data);        //숫자
      
}

//메인 함수
int main(int argc, char **argv)
{
    ros::init(argc,argv,"yh_sub_4"); //노드 이름 초기화
    ros::NodeHandle nh; //Ros 시스템과 통신을 위한 노드 핸들 선언
    ros :: Subscriber sub=  nh.subscribe("raspberry_pie",100,msgCallback);
                                          //토픽이름 , 큐사이즈 , 콜백함수

    
    ros::spin();  //스핀이 없으면 바로 종료됨 꼭 넣어주기~

    return 0;
}
