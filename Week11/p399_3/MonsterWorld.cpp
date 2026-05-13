#include "MonsterWorld.h"
#include "Monster.cpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

MonsterWorld::MonsterWorld(int w, int h) {
    width = w;   
    height = h;  
    nMon = 0;    
    nMove = 0;   
}

MonsterWorld::~MonsterWorld() {
    for (int i = 0; i < nMon; i++) {
        delete pMon[i];                     // 동적으로 생성한 몬스터 객체 삭제
    }
}

void MonsterWorld::add(Monster* m) {
    if (nMon < 10) {                        // 최대 10마리까지만 추가
        pMon[nMon] = m;                     // 배열에 몬스터 주소 저장
        nMon++;                             // 몬스터 수 증가
    }
}

void MonsterWorld::checkStarvation() {
    for (int i = 0; i < nMon; i++) {
        if (pMon[i]->getEnergy() <= 0) {    // 에너지가 0 이하인지 검사
            delete pMon[i];                 // 에너지 0인 몬스터 삭제

            pMon[i] = pMon[nMon - 1];       // 마지막 몬스터를 삭제된 자리로 이동
            nMon--;                         // 몬스터 수 감소

            cout << "Monster 하나가 굶어죽습니다" << endl;        // 삭제 메시지 출력

            i--;                                              // 새로 들어온 몬스터도 다시 검사하기 위해 i 감소
        }
    }
}

void MonsterWorld::play(int turns) {
    for (int t = 0; t < turns; t++) {                              // 지정한 횟수만큼 반복
        cout << "\n[ Monster World (Dynamic World) ]" << endl;

        for (int i = 0; i < nMon; i++) {
            pMon[i]->move(width, height);                          // 몬스터 이동
            pMon[i]->print();                                      // 몬스터 정보 출력
        }

        nMove++;             // 전체 이동 횟수 증가

        cout << "전체 이동 횟수 = " << nMove << endl;                 // 이동 횟수 출력

        checkStarvation();                                         // 에너지 0인 몬스터 삭제

        Monster::printCount();                                     // static 함수로 전체 몬스터 수 출력
    }
}

int main() {
    srand((unsigned int)time(NULL));                               // 랜덤 이동을 위한 난수 초기화

    MonsterWorld game(40, 20);                                     // 가로 40, 세로 20 크기의 월드 생성

    game.add(new Monster("몬스터", "@", 10, 10, 10));              // 몬스터 추가
    game.add(new Monster("도깨비", "#", 20, 5, 15));                // 도깨비 추가
    game.add(new Monster("별그대", "$", 30, 3, 20));                // 별그대 추가
    game.add(new Monster("고스트", "%", 5, 15, 25));                // 고스트 추가
 
    game.play(30);          // 30번 반복 실행

    return 0;               // 프로그램 정상 종료
}