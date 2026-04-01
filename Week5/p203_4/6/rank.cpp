#include <stdio.h>

typedef struct{
    int move;
    double time;
} Rank;

int main(){
    Rank r[3] = {
        {20,10.5},
        {15,8.2},
        {30,15.0}
    };

    FILE *fp = fopen("rank.dat","wb");

    if(fp == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }

    fwrite(r,sizeof(Rank),3,fp);
    fclose(fp);

    printf("이진 저장 완료\n");

    Rank load[3];

    fp = fopen("rank.dat","rb");

    if(fp == NULL){
        printf("파일 읽기 실패\n");
        return 1;
    }

    fread(load,sizeof(Rank),3,fp);
    fclose(fp);

    printf("\n랭킹 출력:\n");
    for(int i=0;i<3;i++){
        printf("%d회 %.1f초\n",load[i].move,load[i].time);
    }
}