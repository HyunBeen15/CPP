#include <iostream>
#include <iomanip>
#include "MyTime.h"
using namespace std;

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

MyTime MyTime::add(MyTime t) {
    MyTime result;

    int total1 = hour * 3600 * 1000 + min * 60 * 1000 + sec * 1000 + msec;
    int total2 = t.hour * 3600 * 1000 + t.min * 60 * 1000 + t.sec * 1000 + t.msec;

    int total = total1 + total2;

    result.hour = total / (3600 * 1000);
    total %= (3600 * 1000);

    result.min = total / (60 * 1000);
    total %= (60 * 1000);

    result.sec = total / 1000;
    result.msec = total % 1000;

    return result;
}

void MyTime::reset() {
    hour = min = sec = msec = 0;
}

void MyTime::read() {
    cout << "시(hour): "; cin >> hour;
    cout << "분(min): "; cin >> min;
    cout << "초(sec): "; cin >> sec;
    cout << "밀리초(msec): "; cin >> msec;
}

int main() {
    MyTime t1, t2, t3;

    cout << "[t1 입력]" << endl;
    t1.read();

    cout << "[t2 입력]" << endl;
    t2.read();

    cout << "\nt1 = ";
    t1.print();

    cout << "t2 = ";
    t2.print();

    t3 = t1.add(t2);
    cout << "t1 + t2 = ";
    t3.print();

    t3.reset();
    cout << "reset 후 t3 = ";
    t3.print();

    return 0;
}