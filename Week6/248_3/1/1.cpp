#include "addTime.h"

MyTime addTime(MyTime t1, MyTime t2)              // 함수 정의
{
    MyTime t3;

    t3.sec = t1.sec + t2.sec;                     // 초를 먼저 더한 뒤 60으로 나눈 몫을 분으로 올림 처리
    t3.min = t1.min + t2.min + t3.sec / 60;       // 같은 방식으로 분을 더한 뒤 시로 올림 처리.
    t3.sec %= 60;

    t3.hour = t1.hour + t2.hour + t3.min / 60;
    t3.min %= 60;

    return t3;
}

int main() {
    MyTime t1, t2;

    std::cout << "첫 번째 시간 입력 (시 분 초): ";     // 첫 번째 시간 입력 받기
    std::cin >> t1.hour >> t1.min >> t1.sec;

    std::cout << "두 번째 시간 입력 (시 분 초): ";     // 두 번째 시간 입력 받기
    std::cin >> t2.hour >> t2.min >> t2.sec;

    MyTime result = addTime(t1, t2);

    std::cout << "결과: " << result.hour << ":" << result.min << ":" << result.sec << std::endl;  // 시:분:초 형태로 출력

    return 0;
}