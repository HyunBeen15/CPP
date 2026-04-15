#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
private:
    int hour;
    int min;
    int sec;
    int msec;

public:
    inline void convert(double duration) {
        hour = (int)(duration / 3600);                  // 전체 초 → 시 계산
        duration = duration - hour * 3600;              // 남은 초 계산

        min = (int)(duration / 60);                     // 분 계산
        duration = duration - min * 60;                 // 남은 초 계산
 
        sec = (int)duration;                            // 초 계산
        duration = duration - sec;                      // 소수 부분 남기기
 
        msec = (int)(duration * 1000);                  // 밀리초 변환
    }

    inline void print() {
        cout << setfill('0')
             << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << ":"
             << setw(3) << msec << endl;
    }

    inline MyTime add(MyTime t) {
        MyTime result;                                  // 결과 저장 

        int total1 = hour * 3600 * 1000 + min * 60 * 1000 + sec * 1000 + msec;
        int total2 = t.hour * 3600 * 1000 + t.min * 60 * 1000 + t.sec * 1000 + t.msec;

        int total = total1 + total2;                    // 두 시간 합

        result.hour = total / (3600 * 1000);            // 시 계산 
        total = total % (3600 * 1000);

        result.min = total / (60 * 1000);               // 분 계산
        total = total % (60 * 1000);

        result.sec = total / 1000;                      // 초 계산
        result.msec = total % 1000;                     // 밀리초 계산

        return result;
    }

    inline void reset() {
        hour = 0;
        min = 0;
        sec = 0;
        msec = 0;
    }
};

int main() {
    MyTime t1, t2, t3;

    t1.convert(3723.456);
    t2.convert(61.789);

    cout << "t1 = ";
    t1.print();

    cout << "t2 = ";
    t2.print();

    t3 = t1.add(t2);
    cout << "t3 = ";
    t3.print();

    t3.reset();
    cout << "reset 후 t3 = ";
    t3.print();

    return 0;
}