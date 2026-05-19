#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Monster {             // 기본 몬스터 클래스
protected:
    int x, y;

public:
    Monster(int xx, int yy): x(xx), y(yy) {
    }

    virtual void move() {}

    void print() {
        cout << "현재 위치: (" << x << ", " << y << ")\n";
    }
};

class Smombi : public Monster {                 // (1) 대각선으로 이동하는 스몸비 클래스
public:
    Smombi(int xx, int yy): Monster(xx, yy) {   // 생성자
    }

    void move() override {                      // 이동 함수 재정의

        int dir = rand() % 4;

        if (dir == 0) {                         // 왼쪽 위 대각선 이동
            x--;
            y--;
        }

        else if (dir == 1) {                    // 오른쪽 위 대각선 이동
            x++; 
            y--;
        }

        else if (dir == 2) {                    // 왼쪽 아래 대각선 이동
            x--;
            y++;
        }

        else {                                  // 오른쪽 아래 대각선 이동
            x++;
            y++;
        }
    }
};

int main() {
    srand(time(0));

    Smombi s(5, 5);           // 객체 생성

    s.move();                 // 이동

    s.print();                // 위치 출력

    return 0;
}