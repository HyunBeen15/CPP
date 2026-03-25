#include <iostream>                // 입출력
#include <cstdlib>                 // rand() 함수를 사용하기 위해 필요
#include <ctime>                   // 랜덤 값을 매번 다르게 만들기 위해 사용
#include <cmath>                   // pow() 함수 사용을 위해 필요
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

bool playAddition(int digits)                   // 여러 자리 수 덧셈
{
    int a = rand() % (int)pow(10, digits);      // digits는 자리수(3~9)
    int b = rand() % (int)pow(10, digits);      // pow(10, digits)는 자리 수 범위 설정
    int result;

    std::cout << a << " + " << b << " = ";
    std::cin >> result;

    if (result == a + b) {
        std::cout << "정답!\n";
        return true;
    } else {
        std::cout << "틀렸습니다.\n";
    }   return false;
}

bool startGame() 
{
    srand(time(0));        // 랜덤 초기화
    int choice;

    std::cout << "게임을 선택하세요. \n";  
    std::cout << "1: 구구단 게임\n";
    std::cout << "2: 두 자리 수 곱셈\n";
    std::cout << "3~9: 해당 자리 수 덧셈\n";
    std::cout << "게임을 선택하세요 : ";
    std::cin >> choice;

    if (choice == 1) {
        return playGuguOnce();
    } else if (choice == 2) {
        return playMultiplication();
    } else if (choice >= 3 && choice <= 9) {
        return playAddition(choice);
    } else {
        std::cout << "잘못된 선택입니다.\n";
        return false;
    }
}

int main() {                  // 메인 함수
    startGame();
    return 0;
}