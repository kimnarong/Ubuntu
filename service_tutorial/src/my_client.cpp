#include "ros/ros.h" //ROS 헤더파일
#include "service_tutorial/my_srv.h" //서비스 헤더 파일
                                     //빌드 후 생성
#include <cstdlib> // atoll 함수 사용을 위한 라이브러리

int main(int argc, char **argv) //메인 함수
{
    ros::init(argc,argv,"my_client"); //노드 이름 초기화

    //rosrun 패키지이름 노드이름 a b
    //argv = {노드이름, a , b} a는 첫번째[1] b는 두번째[2]
    if (argc !=3) //입력값 오류 처리   , argc = 문자열 카운트
    {
        ROS_INFO("comman: rosrun service_tutorial my_client arg1 arg2");
        ROS_INFO("arg1,arg2: int64 number");

        return 1; //에러 종료
    }

    //서비스 클라이언트 선언
    //서비스 클라이언트 ( my_service_client )를 선언한다.
    //서비스 이름은 ( my_service )이고 패키지 ( service_tutorial )의 ( my_srv )서비스 파일을 사용한다.
    ros::NodeHandle nh; //노들 핸들
    ros::ServiceClient my_service_client = nh.serviceClient<service_tutorial::my_srv>("my_service");

    service_tutorial::my_srv srv;
    
    //서비스 요청 값으로 노드 실행시 입력된 매개변수를 a,b 에 저장한다.
    srv.request.a = atoll(argv[1]);  //숫자형으로 변환 python은 인트형으로 감싸기
    srv.request.b = atoll(argv[2]);

    //서비스를 요청하고 응답이 정상적으로 왔을 경우, 값을 표시한다.
    if(my_service_client.call(srv))
    {
        ROS_INFO("send srv, srv.request.a,b: %ld, %ld",srv.request.a,srv.request.b);
        ROS_INFO("receive srv, srv.response.result %ld", srv.response.result);
        ROS_INFO("Message %s", srv.response.error.c_str());
    }
    else
    {
        ROS_INFO("Failed to call service");
        return 1;
    }

    return 0;


}

    

