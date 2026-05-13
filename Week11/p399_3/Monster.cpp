#include "Monster.h"  // Monster.cpp에서는 클래스 구현 파일. main함수가 없어서 실행 X, MonsterWorld에 main함수 존재.
#include <cstdlib>

int Monster::nCount = 0;                      // static 변수 초기화

Monster::Monster(string n, string i, int px, int py, int e) {
    name = n;
    icon = i;
    x = px;
    y = py;
    nEnergy = e;

    nCount++;                                 // 몬스터 생성 시 전체 수 증가
}

Monster::~Monster() {
    nCount--;                                 // 몬스터 삭제 시 전체 수 감소
}

void Monster::move(int maxX, int maxY) {
    x += rand() % 3 - 1;                      // x좌표를 -1, 0, 1 중 하나만큼 이동
    y += rand() % 3 - 1;                      // y좌표를 -1, 0, 1 중 하나만큼 이동

    if (x < 0) x = 0;                         // x가 왼쪽 경계를 벗어나지 않게 함
    if (x >= maxX) x = maxX - 1;              // x가 오른쪽 경계를 벗어나지 않게 함

    if (y < 0) y = 0;                         // y가 왼쪽 경계를 벗어나지 않게 함
    if (y >= maxY) y = maxY - 1;              // y가 오른쪽 경계를 벗어나지 않게 함

    nEnergy--;                                // 이동할 때마다 에너지 감소
}

void Monster::eat() {
    nEnergy += 8;                             // 먹이를 먹으면 에너지 증가
}

void Monster::print() {
    cout << name << icon                      // 몬스터 이름, 아이콘 출력
         << " : " << x
         << " E:" << nEnergy << endl;
}

int Monster::getX() {
    return x;
}

int Monster::getY() {
    return y;
}

string Monster::getIcon() {
    return icon;
}

int Monster::getEnergy() {
    return nEnergy;
}

void Monster::printCount() {
    cout << "전체 몬스터의 수 = " << nCount << endl;
}