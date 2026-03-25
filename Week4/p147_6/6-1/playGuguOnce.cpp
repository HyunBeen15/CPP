#include <iostream>                // 입출력
#include <cstdlib>                 // rand() 함수를 사용하기 위해 필요
#include "GuguOnce.h"              // 헤더파일

bool playGuguOnce()                // 구구단
{
    int a = rand() % 9 + 1;        // 1~9단 생성
    int b = rand() % 9 + 1;
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
    playGuguOnce();           // 정의된 함수 호출
    return 0;
}