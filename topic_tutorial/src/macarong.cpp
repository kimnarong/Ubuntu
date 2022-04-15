int a =100;
int *a_ptr=&a //int형 포인터 /a나 100이 아니고 주소값을 넣겠다
printf("%d",*a_ptr); //a_ptr - a의 주소값 
                    //*붙여주면 - 주소값에 가서 들어있는 a의 값을 가져온다

//구조체
//자료형을 임의로 지정


//파이썬 클래스 (파이썬이랑 같은 함수인데 언어에 따라 표기가 다름)
class Person():
    name = "이름"
    age = 12




//C++클래스
class Person
{
    char[] name = "이름";
    int age = 12;
}    
person1=Person()
Person.name //.을 통해서 안에 있는 값을 꺼내 쓸 수 있다
Person.age


//C
Person person1;
person1.age;
person1.name;

Person *person_ptr = &person1;  //내가 선언한 클래스 펄슨형의 변수의 주소값을 가져올 포인터 값을 읽어오기위해
int    *a_ptr      = &a;

//주소값은 보통 정수형 실수값이다.
*person_ptr.name == person_ptr->name  //*안붙이면 주소값이므로 name을 읽을 수 없다.

