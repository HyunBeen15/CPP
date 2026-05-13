#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
using namespace std;

class Monster {
private:
    string name;        // 몬스터 이름
    string icon;        // 몬스터 모양
    int x, y;           // 위치
    int nEnergy;        // (1) 에너지

    static int nCount;  // (4) 전체 몬스터 수

public:
    Monster(string n, string i, int px, int py, int e);
    ~Monster();

    void move(int maxX, int maxY);       // 몬스터 이동
    void eat();                          // 아이템을 먹었을 때 에너지 증가
    void print();                        // 몬스터 정보 출력

    int getX();
    int getY();
    string getIcon();

    int getEnergy();          // (2) 에너지 반환
    static void printCount(); // (4) 전체 몬스터 수 출력
};

#endif