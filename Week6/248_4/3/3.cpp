#include "MineMapMask.h"

static int MineMapMask[40][80];
static int MineMapLabel[40][80];

void initMap(int row, int col)                        // 초기화
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            MineMapMask[i][j] = 0;                    // 지뢰 여부 저장
            MineMapLabel[i][j] = -1;                  // 사용자에게 보여지는 상태
        }
}

void placeMines(int row, int col, int mineCount)      // 지뢰 배치
{
    int count = 0;

    while (count < mineCount) {
        int r = rand() % row;
        int c = rand() % col;

        if (MineMapMask[r][c] == 0) {
            MineMapMask[r][c] = 1;
            count++;
        }
    }
}

void printMap_index(int row, int col)                 // 행/열 번호 출력
{ 
    printf("   ");                                    // 열 번호
    for (int j = 0; j < col; j++)                     // 각 행마다 행 번호를 출력하고, 맵 데이터를 함께 출력
        printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < row; i++) {
        printf("%2d ", i);

        for (int j = 0; j < col; j++) {
            printf("%2d ", MineMapMask[i][j]);
        }
        printf("\n");
    }
}

int main()                                            // 초기화와 지뢰 배치를 수행한 뒤 인덱스가 포함된 맵을 출력
{
    int row, col, mineCount;

    srand(time(NULL));

    printf("맵 크기 입력: ");
    scanf("%d %d", &row, &col);

    printf("지뢰 개수 입력: ");
    scanf("%d", &mineCount);

    initMap(row, col);
    placeMines(row, col, mineCount);
    printMap_index(row, col);

    return 0;
}