#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hour;
    int min;
    int sec;
    int msec;

public:
    MyTime();                              // 기본 생성자
    MyTime(int h, int m, int s, int ms);   // 매개변수 생성자
    MyTime(double duration);               // 추가

    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void reset();
    void read();
};

#endif