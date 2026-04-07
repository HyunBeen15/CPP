#include <iostream>

struct MyTime                  // 시간 표현하기 위해 MyTime 구조체 만듬
{
    int hour, min, sec;
};

MyTime addTime ( MyTime t1, MyTime t2 );             // 함수 선언
void addTime( MyTime t1, MyTime t2, MyTime& t3 );    // 함수 선언
void addTime( MyTime t1, MyTime t2, MyTime* pt );    // 함수 선언