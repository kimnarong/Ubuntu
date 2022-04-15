#include "ros/ros.h" //ROS 헤더파일
#include "yh_tutorial_5/yh_srv_5.h" //서비스 헤더 파일
                                     //빌드 후 생성
#include <cstdlib> // atoll 함수 사용을 위한 라이브러리

//클라이언트는 바로 메인문 선언
int main(int argc, char **argv) //메인 함수
{
    ros::init(argc,argv,"yh_client_5"); //노드 이름 초기화

    
    if (argc !=3) //입력값 오류 처리   , argc = 문자열 카운트
    {
        ROS_INFO("wrong commad"); //갯수가 3이 아닐때 출력하고 싶은 문구
        return 1; //에러 종료
    }

    ros::NodeHandle nh; //노드 핸들
    ros::ServiceClient yh_service_client_5 = nh.serviceClient<yh_tutorial_5::yh_srv_5>("yh_service_5");
                                                                                        //서비스 이름
    yh_tutorial_5::yh_srv_5 srv;  
    
    //서비스 요청 값으로 노드 실행시 입력된 매개변수를 a,b 에 저장한다.
    srv.request.a = atoll(argv[1]);  //숫자형으로 변환 python은 인트형으로 감싸기
    srv.request.b = atoll(argv[2]);

    //서비스를 요청하고 응답이 정상적으로 왔을 경우, 값을 표시한다.
    if(yh_service_client_5.call(srv))
    {
        ROS_INFO("%ld",srv.response.result); //잘되면 반환된 결과값 출력
    }
    else
    {
        ROS_INFO("Failed to call service");
        return 1;
    }

    return 0;


}

    

