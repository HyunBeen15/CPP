#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Jiangshi {             // 강시 클래스
protected:
    int x, y;

public:
    Jiangshi(int xx, int yy)
        : x(xx), y(yy) {
    }

    virtual void move() {                 // 기본 강시는 가로로만 이동
        x++;
    }

    void print() {
        cout << "현재 위치: (" << x << ", " << y << ")\n";
    }
};

class Siangshi : public Jiangshi {         // (2) 상시 클래스
private:
    int count;                             // 이동 횟수 저장

public:
    Siangshi(int xx, int yy)               // 생성자
        : Jiangshi(xx, yy), count(0) {
    }

    void move() override {                 // 이동 함수 재정의

        count++;
 
        if (count % 3 == 0) {              // 일정 시간마다 방향 변경
 
            y++;         // 세로 이동
        }

        else {

            x++;         // 가로 이동
        }
    }
};

int main() {
    Siangshi s(3, 3);                      // 객체 생성

    for (int i = 0; i < 5; i++) {          // 여러 번 이동

        s.move();
        s.print();
    }

    return 0;
}