#include <iostream>
using namespace std;

class Monster {                      // 기본 몬스터 클래스
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

class FastMonster : public Monster {         // 빠르게 움직이는 몬스터
public:
    FastMonster(int xx, int yy)              // 생성자
        : Monster(xx, yy) {
    }

    void move() override {                   // 이동 함수 재정의

        x += 2;                              // 가로로 2칸 이동
    }
};

int main() {
    FastMonster f(0, 0);             // 객체 생성

    f.move();                        // 이동
    f.print();                       // 출력

    return 0;
}