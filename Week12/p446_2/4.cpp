#include <iostream>
using namespace std;

class Monster {                     // 기본 몬스터 클래스
protected:
    int x, y;

public:
    Monster(int xx, int yy): x(xx), y(yy) {
    }

    virtual void move() {}

    void print() {
        cout << "(" << x << ", " << y << ")\n";
    }
};

class Smombi : public Monster {                 // 스몸비 클래스
public:
    Smombi(int xx, int yy): Monster(xx, yy) {
    }

    void move() override {
        x++;
        y++;
    }
};

class Siangshi : public Monster {              // 상시 클래스
public:
    Siangshi(int xx, int yy): Monster(xx, yy) {
    }

    void move() override {
        x++;
    }
};

class FastMonster : public Monster {           // 빠른 몬스터 클래스
public:
    FastMonster(int xx, int yy): Monster(xx, yy) {
    }

    void move() override {
        x += 2;
    }
};

int main() {
    Smombi s(1, 1);          // 객체 생성
    Siangshi si(2, 2);       // 객체 생성
    FastMonster f(3, 3);     // 객체 생성
  
    s.move();       // 이동
    si.move();      // 이동
    f.move();       // 이동

    cout << "Smombi ";         // 출력
    s.print();

    cout << "Siangshi ";       // 출력
    si.print();

    cout << "FastMonster ";    // 출력
    f.print();

    return 0;
}