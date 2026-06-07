#ifndef TIMEHMS_H
#define TIMEHMS_H

#include <iostream>
#include <iomanip>
using namespace std;

class TimeHMS {
    int hour, min, sec;

    void normalize() {
        int total = hour * 3600 + min * 60 + sec;
        if (total < 0) total = 0;

        hour = total / 3600;
        total %= 3600;
        min = total / 60;
        sec = total % 60;
    }

public:
    TimeHMS(int h = 0, int m = 0, int s = 0)
        : hour(h), min(m), sec(s) {
        normalize();
    }

    TimeHMS operator+(TimeHMS t) {
        return TimeHMS(hour + t.hour, min + t.min, sec + t.sec);
    }

    TimeHMS operator-(TimeHMS t) {
        return TimeHMS(hour - t.hour, min - t.min, sec - t.sec);
    }

    bool operator==(TimeHMS t) {
        return hour == t.hour && min == t.min && sec == t.sec;
    }

    bool operator!=(TimeHMS t) {
        return !(*this == t);
    }

    TimeHMS& operator++() {
        hour++;
        normalize();
        return *this;
    }

    TimeHMS& operator--() {
        hour--;
        normalize();
        return *this;
    }

    TimeHMS operator++(int) {
        TimeHMS temp = *this;
        sec++;
        normalize();
        return temp;
    }

    TimeHMS operator--(int) {
        TimeHMS temp = *this;
        sec--;
        normalize();
        return temp;
    }

    int& operator[](int index) {
        if (index == 0) return hour;
        if (index == 1) return min;
        return sec;
    }

    operator int() {
        return hour * 3600 + min * 60 + sec;
    }

    operator double() {
        return hour + min / 60.0 + sec / 3600.0;
    }

    friend TimeHMS operator*(int n, TimeHMS t) {
        return TimeHMS(t.hour * n, t.min * n, t.sec * n);
    }

    friend istream& operator>>(istream& in, TimeHMS& t) {
        cout << "시 분 초 입력: ";
        in >> t.hour >> t.min >> t.sec;
        t.normalize();
        return in;
    }

    friend ostream& operator<<(ostream& out, TimeHMS t) {
        out << setfill('0')
            << setw(2) << t.hour << ":"
            << setw(2) << t.min << ":"
            << setw(2) << t.sec;
        return out;
    }
};

#endif