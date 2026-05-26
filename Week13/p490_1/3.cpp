#include <iostream>
using namespace std;

class Human {
protected:
    int x, y;

public:

    Human(int px = 0, int py = 0) {

        x = px;                   // x좌표 초기화
        y = py;                   // y좌표 초기화
    }

    void printPosition() {
        cout << "현재 위치 : ("     // 현재 위치 출력
             << x << ", "
             << y << ")\n";
    }
};

class Tuman : public Human {

public:

    Tuman(int px = 0, int py = 0) 
        : Human(px, py) {          // Human 클래스를 상속받아 부모 생성자를 호출
    }

    void moveHuman(char ch) {      // 사람 전용 이동 함수 

        if (ch == 'a')
            x--;                   // 왼쪽 이동

        else if (ch == 'd')
            x++;                   // 오른쪽 이동

        else if (ch == 'w')
            y--;                   // 위 이동

        else if (ch == 's')
            y++;                   // 아래 이동
    }
};

int main() {

    Tuman player(5, 5);

    player.moveHuman('d');         // 오른쪽 이동

    player.printPosition();

    return 0;
}