#include <iostream>
using namespace std;

class Tuman {
private:
    int x, y;
    string icon;

public:

    Tuman(string i, int px, int py) {

        icon = i;                  // 플레이어 아이콘 저장

        x = px;                    // 시작 x좌표 저장
        y = py;                    // 시작 y좌표 저장
    }

    void move(char ch) {           // 왼쪽 플레이어 이동 함수

        if (ch == 'a')
            x--;                   // 왼쪽 이동

        else if (ch == 'd')
            x++;                   // 오른쪽 이동

        else if (ch == 'w')
            y--;                   // 위 이동

        else if (ch == 's')
            y++;                   // 아래 이동
    } 

    void moveArrow(char ch) {      // 오른쪽 플레이어 이동 함수

        if (ch == 'j')
            x--;                   // 왼쪽 이동

        else if (ch == 'l')
            x++;                   // 오른쪽 이동

        else if (ch == 'i')
            y--;                   // 위 이동

        else if (ch == 'k')
            y++;                   // 아래 이동
    }

    void print() {
        cout << icon               // 현재 플레이어 위치 출력
             << " 위치 : ("
             << x << ", "
             << y << ")\n";
    }
};

int main() {

    Tuman left("좌", 3, 3);    // 왼쪽 플레이어 생성
    Tuman right("우", 7, 7);   // 오른쪽 플레이어 생성

    char key1, key2;

    cout << "왼쪽 플레이어 입력(w/a/s/d) : ";
    cin >> key1;

    cout << "오른쪽 플레이어 입력(i/j/k/l) : ";
    cin >> key2;

    left.move(key1);          // 왼쪽 플레이어 이동

    right.moveArrow(key2);    // 오른쪽 플레이어 이동

    left.print();
    right.print();

    return 0;
}