#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int map[MAX][MAX];
int DIM, x, y;

void init(){
    int v=1;
    for(int i=0;i<DIM;i++)
        for(int j=0;j<DIM;j++)
            map[i][j]=v++;

    map[DIM-1][DIM-1]=0;
    x=DIM-1; y=DIM-1;
}

void display(){
    system("clear");
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            if(map[i][j]) printf("%3d",map[i][j]);
            else printf("   ");
        }
        printf("\n");
    }
}

int main(){
    printf("크기 선택 (3/4/5): ");
    scanf("%d",&DIM);

    init();
    display();
}