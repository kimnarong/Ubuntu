#include "ros/ros.h" //ROS 헤더파일
#include "yh_tutorial_5/yh_srv_5.h" //서비스 헤더 파일
                                     //빌드 후 생성

//서비스 요청이 있을 경우 실행되는 함수
//서비스 요청은 req, 서비스 응답은 res로 설정  

//서버니까(server) 요청이 왔을 때 실행 될 콜백함수 
bool srvCallbadk(yh_tutorial_5::yh_srv_5::Request &req,yh_tutorial_5::yh_srv_5::Response &res) //반환형
{

    res.result = req.a*req.b; //리절트에 값 넣어주기
    
    return true;

}                 

int main(int argc, char ** argv) //메인함수
{
    ros::init(argc,argv, "yh_server_5"); //노드 이름 초기화
    ros::NodeHandle nh; //노드 핸들 선언

    ros::ServiceServer service_server = nh.advertiseService("yh_service_5",srvCallbadk);           
                                                           //★ 서비스 이름 설정  //요청이 왔을 때 실행할 콜백함수


    ROS_INFO("service server ready");

    ros::spin();
    return 0;

}