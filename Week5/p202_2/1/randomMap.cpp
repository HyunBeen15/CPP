#include "randomMap.h"

void randomMap(int map[5][5])                 // 함수 정의, 5x5 크기의 정수형 배열을 매개변수로 받음
{
    for (int i = 0; i < 5; i++) {             // 행 반복
        for (int j = 0; j < 5; j++) {         // 열 반복
            map[i][j] = rand() % 2;           // 0과 1을 랜덤 생성, 랜덤 수를 2로 나눈 나머지 반환
        }
    }
}

int main()
{
    int map[5][5];

    srand(time(NULL));                        // 난수 초기화 -> 프로그램 실행 때마다 다른 난수 생성 가능

    randomMap(map);                           // 함수 호출 

    for (int i = 0; i < 5; i++) {             // 결과 출력
        for (int j = 0; j < 5; j++) {         
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}