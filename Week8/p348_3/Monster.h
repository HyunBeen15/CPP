#pragma once
#include <iostream>
#include <string>
using namespace std;

#define DIM 40

class Canvas;  // 전방 선언

class Monster {
    string name, icon;      // 몬스터 이름, 아이콘
    int x, y;               // 위치
    int nItem;              // 먹은 아이템 수
    int nEnergy;            // (1) 에너지 추가 

    void clip(int maxx, int maxy) {      // 맵 범위 벗어나지 않도록 제한
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int map[DIM][DIM]) {       // 아이템 먹기
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            nEnergy += 8;          // (3) 먹으면 +8
        }
        else {
            nEnergy--;             // (3) 못 먹으면 -1

            if (nEnergy < 0)       // 최소값 0 제한
                nEnergy = 0;
        }
    }

public:
    Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)          // (2) 생성자: 에너지 100으로 초기화 
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}

    ~Monster() {          // 소멸자
        cout << "\t" << name << icon << " 이만 갑니다~~\n";
    }

     void draw(Canvas &canvas) {           // 화면에 그리기
        canvas.draw(x, y, icon);
    }                                

    void move(int map[DIM][DIM], int maxx, int maxy) {          // 이동
        switch (rand() % 8) {
        case 0: y--; break;
        case 1: x++; y--; break;
        case 2: x++; break;
        case 3: x++; y++; break;
        case 4: y++; break;
        case 5: x--; y++; break;
        case 6: x--; break;
        case 7: x--; y--; break;
        }

        clip(maxx, maxy);
        eat(map);
    }

    void print() {                         // (4) 상태 출력 (에너지 포함)
        cout << "\t" << name << icon << ":"
             << nItem << " E:" << nEnergy << endl;
    }
};