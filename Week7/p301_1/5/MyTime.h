#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hour;
    int min;
    int sec;
    int msec;

public:
    void convert(double duration); // 변환
    void print();                 // 출력
    MyTime add(MyTime t);        // 덧셈
    void reset();                // 초기화
    void read();                 // 입력
};

#endif