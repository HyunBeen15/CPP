#include "checkMap.h"

void randomMap(int map[5][5])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

void printMap(int map[5][5])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void checkMap(int map[5][5]) 
{
    printf("\n=== 검사 결과 ===\n");
    
    for (int i = 0; i < 5; i++) {
        if (map[i][0] == map[i][1] && map[i][1] == map[i][2] && map[i][2] == map[i][3] && map[i][3] == map[i][4]) {

            printf("가로 %d번째 줄: 모두 %d\n", i, map[i][0]);
        }
    }

    for (int j = 0; j < 5; j++) {
        if (map[0][j] == map[1][j] && map[1][j] == map[2][j] && map[2][j] == map[3][j] && map[3][j] == map[4][j]) {

            printf("세로 %d번째 줄: 모두 %d\n", j, map[0][j]);
        }
    }

    if (map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[2][2] == map[3][3] && map[3][3] == map[4][4]) {

        printf("좌상 -> 우하 대각선: 모두 %d\n", map[0][0]);
    }

    if (map[0][4] == map[1][3] && map[1][3] == map[2][2] && map[2][2] == map[3][1] && map[3][1] == map[4][0]) {

        printf("우상 -> 좌하 대각선: 모두 %d\n", map[0][4]);
    }
}

int main()
{
    int map[5][5];

    srand(time(NULL));       // 랜덤 초기화

    randomMap(map);          // (1) 생성
    printMap(map);           // (2) 출력
    checkMap(map);           // (3) 검사

    return 0;
}