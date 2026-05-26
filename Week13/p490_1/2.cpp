#include <iostream>
using namespace std;

class Player {
private:
    string icon;

public:

    Player(string i) {

        icon = i;                   // 아이콘 저장
    }

    void print() {
        cout << "플레이어 아이콘 : "    // 플레이어 아이콘 출력
             << icon << endl;
    }
};

int main() {

    Player left("좌");    // 왼쪽 플레이어 아이콘
    Player right("우");   // 오른쪽 플레이어 아이콘

    left.print();
    right.print();

    return 0;
}