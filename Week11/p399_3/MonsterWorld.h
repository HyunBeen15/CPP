#ifndef MONSTERWORLD_H
#define MONSTERWORLD_H

#include "Monster.h"

class MonsterWorld {
private:
    int width;
    int height;
    int nMon;
    int nMove;

    Monster* pMon[10];                // 몬스터 객체를 저장하는 포인터 배열

public:
    MonsterWorld(int w, int h);       // 생성자
    ~MonsterWorld();                  // 소멸자

    void add(Monster* m);
    void checkStarvation();           // (3) 에너지 0인 몬스터 삭제
    void play(int turns);
};

#endif