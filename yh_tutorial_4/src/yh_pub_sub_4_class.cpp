#include "ros/ros.h" // ROS 헤더 파일
#include "yh_tutorial_4/yh_msg_4.h" //


class SubAndPub():



class SubAndPub
{
    public: //SubAndPub. 멤버 접근 가능
            // 함수 (메소드)
        SubAndPub()  //생성자 클래스 내에서 직접적으로 접근 가능
        {
            pub=nh.advertise<yh_tutorial_4::yh_msg_4>("raspberry_pie",100); 
            sub=nh.subscribe("yh_topic_4",100,&SubAndPub::msgCallback,this);
        }
        void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg) 
        //메세지 받기(거의 고정 상태)
        {
            if (msg->data %5==0)
            {
                pub.publish(msg);
            }

        }


    private: //직접 접근 불가 클래스 내에서만 접근 가능
             //변수
        ros::Publisher pub;
        ros::Subscriber sub;     
        ros::NodeHandle nh;
}

int main(int argc,char **argv) 
{
    ros::init(argc,argv,"yh_pub_sub_4"); //노드 이름 초기화
    
    SubAndPub sub_and_pub();

    ros::spin(); 
    
    return 0;
}                                 