#include "MineMapMask.h"

static int MineMapMask[40][80];
static int MineMapLabel[40][80];

void initMap(int row, int col)                     // 초기화
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            MineMapMask[i][j] = 0;
            MineMapLabel[i][j] = -1;
        }
    }
}

void printMap_basic(int row, int col)              // 기본 출력
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%2d ", MineMapMask[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col;

    printf("맵 크기 입력: ");
    scanf("%d %d", &row, &col);

    initMap(row, col);
    printMap_basic(row, col);

    return 0;
}