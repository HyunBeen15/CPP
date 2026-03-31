#include "printMap.h"

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
    printf("=== 체커 보드 ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int board[5][5];

    srand(time(NULL));

    randomMap(board);
    printMap(board);

    return 0;
}