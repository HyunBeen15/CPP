#include <stdio.h>

int main(){
    int map[4][4];
    int move;
    double time;

    FILE *fp = fopen("save.txt","r");

    if(fp == NULL){
        printf("save.txt 파일이 없습니다! 먼저 저장하세요.\n");
        return 1;
    }

    fscanf(fp,"%d %lf",&move,&time);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            fscanf(fp,"%d",&map[i][j]);
        }
    }

    fclose(fp);

    printf("이동:%d 시간:%.1f\n",move,time);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            printf("%3d",map[i][j]);
        printf("\n");
    }
}