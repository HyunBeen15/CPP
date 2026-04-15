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
    void read() {                              // 입력 함수
        cout << "시(hour): ";
        cin >> hour;

        cout << "분(min): ";
        cin >> min;

        cout << "초(sec): ";
        cin >> sec;

        cout << "밀리초(msec): ";
        cin >> msec;
    }

    void print() {                             // 출력 함수
        cout << setfill('0')
             << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << ":"
             << setw(3) << msec << endl;
    }
};

int main() {
    MyTime t;

    t.read();  // 사용자 입력

    cout << "입력된 시간 = ";
    t.print();

    return 0;
}