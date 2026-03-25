#include <iostream>                // 입출력
#include <cstdlib>                 // rand() 함수를 사용하기 위해 필요
#include <ctime>                   // 랜덤 값을 매번 다르게 만들기 위해 사용
#include "GuguOnce.h"              // 헤더파일

bool playMultiplication()          // 두 자리 수 곱셈
{
    int a = rand() % 90 + 10;      // 10~99 두 자리 수
    int b = rand() % 90 + 10;
    int result;

    std::cout << a << " x " << b << " = ";
    std::cin >> result;

    if (result == a * b) {
        std::cout << "정답!\n";
        return true;
    } else {
        std::cout << "틀렸습니다.\n";
        return false;
    }
}

int main() {                  // 메인 함수
    srand(time(0));           // 랜덤 초가화
    playMultiplication();     // 정의된 함수 호출
    return 0;
}