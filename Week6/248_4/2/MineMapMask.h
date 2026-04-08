#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 40
#define MAX_COL 80

void initMap(int row, int col);                         // 함수 선언
void placeMines(int row, int col, int mineCount);
void printMap_basic(int row, int col);
void printMap_index(int row, int col);
