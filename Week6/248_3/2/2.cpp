#include "addTime.h"

void addTime(MyTime t1, MyTime t2, MyTime& t3)      // 함수 정의, & -> 참조 변수
{
    t3.sec = t1.sec + t2.sec;                       // 초를 먼저 더한 뒤 60으로 나눈 몫을 분으로 올림 처리
    t3.min = t1.min + t2.min + t3.sec / 60;         // 같은 방식으로 분을 더한 뒤 시로 올림 처리
    t3.sec %= 60;

    t3.hour = t1.hour + t2.hour + t3.min / 60;
    t3.min %= 60;
}

int main() 
{
    MyTime t1, t2, result;

    std::cout << "첫 번째 시간 입력 (시 분 초): ";
    std::cin >> t1.hour >> t1.min >> t1.sec;

    std::cout << "두 번째 시간 입력 (시 분 초): ";
    std::cin >> t2.hour >> t2.min >> t2.sec;

    addTime(t1, t2, result);                        // 함수 호출 할 때 결과를 저장할 변수에 넘겨주기

    std::cout << "결과: " << result.hour << ":" << result.min << ":" << result.sec << std::endl;

    return 0;
}