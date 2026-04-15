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
    void convert(double duration) {
        hour = (int)(duration / 3600);
        duration = duration - hour * 3600;

        min = (int)(duration / 60);
        duration = duration - min * 60;

        sec = (int)duration;
        duration = duration - sec;

        msec = (int)(duration * 1000);
    }

    void print() {
        cout << setfill('0')                    // 빈칸을 0으로 채움
             << setw(2) << hour << ":"          // 시간을 2자리로 출력
             << setw(2) << min << ":"           // 분을 2자리로 출력 
             << setw(2) << sec << ":"           // 초를 2자리로 출력
             << setw(3) << msec << endl;        // 밀리초를 3자리로 출력
    }
};

int main() {
    MyTime t;
    t.convert(3754.567);
    t.print();

    return 0;
}