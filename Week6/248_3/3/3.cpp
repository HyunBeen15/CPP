#include "addTime.h"

void addTime(MyTime t1, MyTime t2, MyTime* pt)        // 함수 정의
{
    pt->sec = t1.sec + t2.sec;                        // 포인터를 사용하기에 -> 연산자 사용
    pt->min = t1.min + t2.min + pt->sec / 60;
    pt->sec %= 60;

    pt->hour = t1.hour + t2.hour + pt->min / 60;
    pt->min %= 60;
}

int main() 
{
    MyTime t1, t2, result;

    std::cout << "첫 번째 시간 입력 (시 분 초): ";
    std::cin >> t1.hour >> t1.min >> t1.sec;

    std::cout << "두 번째 시간 입력 (시 분 초): ";
    std::cin >> t2.hour >> t2.min >> t2.sec;

    addTime(t1, t2, &result);                         // 함수를 호출할 때 변수의 주소를 전달해야 함

    std::cout << "결과: " << result.hour << ":" << result.min << ":" << result.sec << std::endl;

    return 0;
}