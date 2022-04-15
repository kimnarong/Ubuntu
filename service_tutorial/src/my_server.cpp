#include "ros/ros.h" //ROS 헤더파일
#include "service_tutorial/my_srv.h" //서비스 헤더 파일
                                     //빌드 후 생성
#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3 
#define DIVISION 4                                 

//서비스 요청이 있을 경우 실행되는 함수
//서비스 요청은 req, 서비스 응답은 res로 설정  
int my_operator = PLUS;
//서버니까(server) 요청이 왔을 때 실행 될 콜백함수 
bool calculation(service_tutorial::my_srv::Request &req,service_tutorial::my_srv::Response &res) //반환형
{
    switch(my_operator)
    {

        case PLUS:
            res.result=req.a+req.b;
            break;
        case MINUS:
            res.result=req.a-req.b;
            break;
        case MULTIPLICATION:
            res.result=req.a*req.b;
            break;
        case DIVISION:
            if(req.b==0){
                ROS_ERROR("Cannot divide by 0");
                res.error="ERROR";
                break;
            }
            res.result=req.a/req.b;
            break;

        default:
            res.result=req.a+req.b;
            break;
    }





    //res.result = req.a*req.b; //리절트에 값 넣어주기 이거 써져있어서 계속 곱하기됨;;;
    
    return true;

}                 

int main(int argc, char ** argv) //메인함수
{
    ros::init(argc,argv, "service_tutorial"); //노드 이름 초기화
    ros::NodeHandle nh; //노드 핸들 선언

    nh.setParam("calculation_method",PLUS);

    ros::ServiceServer service_server = nh.advertiseService("my_service",calculation);           
                                                           //★ 서비스 이름 설정  //요청이 왔을 때 실행할 콜백함수


    ROS_INFO("service server ready");

    //ros::spin()==while(True){ros::spinOnce()}; 
    //로스 스핀은 서비스 요청 대기  다른일은 못하고 스핀원스만 실행
    ros::Rate loop_rate(10);

    while(true)
    {
        nh.getParam("calculation_method",my_operator);
        ros::spinOnce(); //실행시켜야 할 콜백함수가 있을때
        loop_rate.sleep();
    }
    
    return 0;

}