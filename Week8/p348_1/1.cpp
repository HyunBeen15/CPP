#include <iostream>
#include <iomanip>
#include "1.h"
using namespace std;

MyTime::MyTime() {                                  // 기본 생성자
    hour = 0;
    min = 0;
    sec = 0;
    msec = 0;   // 모든 값을 0으로 초기화
}

MyTime::MyTime(int h, int m, int s, int ms) {       // 매개변수 생성자
    hour = h;
    min = m;
    sec = s;
    msec = ms;  // 입력값으로 초기화
}

void MyTime::convert(double duration) {             // 이하 기존 코드 그대로
    hour = (int)(duration / 3600);
    duration -= hour * 3600;

    min = (int)(duration / 60);
    duration -= min * 60;

    sec = (int)duration;
    duration -= sec;

    msec = (int)(duration * 1000);
}

void MyTime::print() {
    cout << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << min << ":"
         << setw(2) << sec << ":"
         << setw(3) << msec << endl;
}

int main() {                    // 실행 main
    MyTime t1;                  // 기본 생성자
    MyTime t2(2, 30, 15, 250);  // 매개변수 생성자

    cout << "t1 = ";
    t1.print();

    cout << "t2 = ";
    t2.print();

    return 0;
}