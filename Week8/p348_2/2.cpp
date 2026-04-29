#include <iostream>
#include <iomanip>
#include "2.h"
using namespace std;

MyTime::MyTime() {                               // 기본 생성자
    hour = 0; 
    min = 0;
    sec = 0;
    msec = 0;
}

MyTime::MyTime(int h, int m, int s, int ms) {    // 매개변수 생성자
    hour = h; 
    min = m;
    sec = s;
    msec = ms;
}

MyTime::MyTime(double duration) {                // double 생성자
    convert(duration);     // 핵심
}

void MyTime::convert(double duration) {
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

int main() {              // 실행 main
    MyTime t1(3661.25);   // double 생성자

    cout << "t1 = ";
    t1.print();

    return 0;
}