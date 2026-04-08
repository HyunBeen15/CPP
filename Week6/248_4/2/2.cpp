#include "MineMapMask.h"

static int MineMapMask[40][80];
static int MineMapLabel[40][80];

void initMap(int row, int col)                       // 초기화
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            MineMapMask[i][j] = 0;
            MineMapLabel[i][j] = -1;
        }
}

void placeMines(int row, int col, int mineCount)     // 지뢰 배치
{
    int count = 0;

    while (count < mineCount) {
        int r = rand() % row;                        // 랜덤 위치 생성
        int c = rand() % col;                        

        if (MineMapMask[r][c] == 0) {                // 해당 위치에 지뢰가 없는 경우에만 지뢰를 배치하여 중복 방지
            MineMapMask[r][c] = 1;
            count++;
        }
    }
}

void printMap_basic(int row, int col)                // 출력
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%2d ", MineMapMask[i][j]);
        }
        printf("\n");
    }
}

int main()                                           // 맵 크기와 지뢰 개수를 입력받고, 초기화 후 지뢰를 배치한 뒤 출력
{
    int row, col, mineCount;

    srand(time(NULL));

    printf("맵 크기 입력: ");
    scanf("%d %d", &row, &col);

    printf("지뢰 개수 입력: ");
    scanf("%d", &mineCount);

    initMap(row, col);
    placeMines(row, col, mineCount);
    printMap_basic(row, col);

    return 0;
}