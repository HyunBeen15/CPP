#include <iostream>
using namespace std;

class Tuman {
private:
    string name;

public:

    Tuman(string n) {

        name = n;                        // 플레이어 이름 저장
    }

    void print() {
        cout << "플레이어 : "              // 플레이어 이름 출력
             << name << endl;
    }
};

int main() {

    Tuman leftPlayer("왼쪽 경기자");        // 왼쪽 플레이어 객체 생성
    Tuman rightPlayer("오른쪽 경기자");     // 오른쪽 플레이어 객체 생성

    leftPlayer.print();
    rightPlayer.print();

    return 0;
}