#include <iostream>
using namespace std;

class Tuman {
private:
    int x, y;

public:
    Tuman(int px = 5, int py = 5) {

        x = px;   // 시작 x좌표 저장
        y = py;   // 시작 y좌표 저장
    }

    void moveHuman(char ch) {           // 사용자가 입력한 키에 따라 이동하는 함수

        if (ch == 'a')
            x--;                        // a 입력 시 왼쪽 이동

        else if (ch == 'd')
            x++;                        // d 입력 시 오른쪽 이동

        else if (ch == 'w')
            y--;                        // w 입력 시 위 이동

        else if (ch == 's')
            y++;                        // s 입력 시 아래 이동
    }

    void print() {

        cout << "현재 위치 : ("           // 현재 좌표 출력
             << x << ", "
             << y << ")\n";
    }
};

int main() {

    Tuman player;   // 플레이어 객체 생성

    char key;

    cout << "이동 키 입력 (w/a/s/d) : ";
    cin >> key;

    player.moveHuman(key);   // 입력 키에 따라 이동

    player.print();          // 결과 출력

    return 0;
}