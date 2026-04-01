#include <stdio.h>
#include <unistd.h>

int moves[100];
int count = 0;

int main(){
    printf("이동 입력 (-1 입력 시 종료):\n");

    int input;
    while(1){
        scanf("%d",&input);
        if(input == -1) break;
        moves[count++] = input;
    }

    printf("\n리플레이 시작\n");
    for(int i=0;i<count;i++){
        printf("Move: %d\n", moves[i]);
        usleep(300000);
    }
}