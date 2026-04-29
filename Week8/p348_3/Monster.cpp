#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Canvas.h"
#include "Monster.h"

void initMap(int map[DIM][DIM], int w, int h) {
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            map[y][x] = rand() % 2;   // 0 또는 1 랜덤 (아이템)
}

void drawMap(Canvas &canvas, int map[DIM][DIM], int w, int h) {
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (map[y][x] == 1)
                canvas.draw(x, y, "@");  // 아이템 표시
}

int main() {
    srand((unsigned int)time(NULL));

    int map[DIM][DIM];
    int width = 20, height = 10;

    Canvas canvas(width, height);
    initMap(map, width, height);

    Monster m1("좀비", "%", rand() % width, rand() % height);      // 몬스터 생성
    Monster m2("스켈레톤", "#", rand() % width, rand() % height);
    Monster m3("크리퍼", "$", rand() % width, rand() % height);

    for (int step = 0; step < 20; step++) {
        canvas.clear();

        drawMap(canvas, map, width, height);

        m1.move(map, width, height);         // 몬스터 이동
        m2.move(map, width, height);
        m3.move(map, width, height);

        m1.draw(canvas);        // 몬스터 출력
        m2.draw(canvas);
        m3.draw(canvas);

        canvas.print();

        cout << "[STEP " << step << "]" << endl;

        m1.print();         // 상태 출력 (여기서 에너지 보임!)
        m2.print();         
        m3.print();         
 
        cout << "----------------------" << endl;
    }

    return 0;
}