#include <stdio.h>

int main(){
    int map[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,0}
    };

    int move = 10;
    double time = 5.5;

    FILE *fp = fopen("save.txt","w");

    if(fp == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }

    fprintf(fp,"%d %lf\n",move,time);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            fprintf(fp,"%d ",map[i][j]);
        fprintf(fp,"\n");
    }

    fclose(fp);
    printf("게임 저장 완료\n");
}