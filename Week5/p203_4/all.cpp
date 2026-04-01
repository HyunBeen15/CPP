#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 5

enum { Left=75, Right=77, Up=72, Down=80 };

int map[MAX][MAX];
int DIM, x, y;
int nMove;
clock_t tStart;

int moves[1000], moveCount=0;
int useChar=0;

// 초기화
void init(){
    int v=1;
    for(int i=0;i<DIM;i++)
        for(int j=0;j<DIM;j++)
            map[i][j]=v++;

    map[DIM-1][DIM-1]=0;
    x=DIM-1; y=DIM-1;
    nMove=0;
    moveCount=0;
    tStart=clock();
}

// 출력
void display(){
    system("clear");

    printf("Puzzle (%dx%d)\n",DIM,DIM);

    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            if(map[i][j]==0) printf("   ");
            else if(useChar)
                printf("%3c",'A'+map[i][j]-1);
            else
                printf("%3d",map[i][j]);
        }
        printf("\n");
    }

    double t=(double)(clock()-tStart)/CLOCKS_PER_SEC;
    printf("\n이동:%d 시간:%.1f\n",nMove,t);
}

// 이동
int move(int d){
    if(d==Right && x>0){
        map[y][x]=map[y][x-1];
        map[y][--x]=0;
    }
    else if(d==Left && x<DIM-1){
        map[y][x]=map[y][x+1];
        map[y][++x]=0;
    }
    else if(d==Up && y<DIM-1){
        map[y][x]=map[y+1][x];
        map[++y][x]=0;
    }
    else if(d==Down && y>0){
        map[y][x]=map[y-1][x];
        map[--y][x]=0;
    }
    else return 0;

    moves[moveCount++] = d;
    nMove++;
    return 1;
}

// 섞기
void shuffle(int n){
    int key[4]={Left,Right,Up,Down};
    for(int i=0;i<n;i++){
        int d = rand()%4;
        if(!move(key[d])) i--;
    }
    moveCount=0;
}

// 완료 체크
int isDone(){
    for(int i=0;i<DIM;i++)
        for(int j=0;j<DIM;j++){
            if(i==DIM-1 && j==DIM-1) return 1;
            if(map[i][j]!=i*DIM+j+1) return 0;
        }
    return 1;
}

// (3) 저장
void saveGame(){
    FILE *fp = fopen("save.txt","w");

    if(fp == NULL){
        printf("파일 열기 실패\n");
        return;
    }

    fprintf(fp,"%d %d %d %d\n",DIM,x,y,nMove);

    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++)
            fprintf(fp,"%d ",map[i][j]);
        fprintf(fp,"\n");
    }

    fclose(fp);
    printf("게임 저장 완료!\n");
}

// (4) 불러오기
void loadGame(){
    FILE *fp = fopen("save.txt","r");

    if(fp == NULL){
        printf("save.txt 파일이 없습니다!\n");
        return;
    }

    fscanf(fp,"%d %d %d %d",&DIM,&x,&y,&nMove);

    for(int i=0;i<DIM;i++)
        for(int j=0;j<DIM;j++)
            fscanf(fp,"%d",&map[i][j]);

    fclose(fp);
    tStart = clock();
}

// (2) 리플레이
void replay(){
    printf("\n리플레이 시작...\n");
    sleep(1);

    init();
    for(int i=0;i<moveCount;i++){
        move(moves[i]);
        display();
        usleep(200000);
    }
}

// (6) 랭킹
typedef struct{
    int move;
    double time;
} Rank;

void saveRank(int move,double time){
    FILE *fp = fopen("rank.dat","ab");

    if(fp == NULL){
        printf("파일 열기 실패\n");
        return;
    }

    Rank r = {move,time};
    fwrite(&r,sizeof(Rank),1,fp);

    fclose(fp);
}

// 메인
int main(){
    srand(time(NULL));

    int sel;
    printf("1. 새 게임\n2. 이어하기\n선택: ");
    scanf("%d",&sel);

    if(sel==2){
        loadGame();
    } else {
        printf("크기 선택 (3/4/5): ");
        scanf("%d",&DIM);

        printf("문자 퍼즐? (1/0): ");
        scanf("%d",&useChar);

        init();
        shuffle(100);
    }

    while(!isDone()){
        display();

        char cmd;
        printf("w/a/s/d 이동, q 저장: ");
        scanf(" %c",&cmd);

        if(cmd=='q') saveGame();
        else if(cmd=='a') move(Left);
        else if(cmd=='d') move(Right);
        else if(cmd=='w') move(Up);
        else if(cmd=='s') move(Down);
    }

    display();
    printf("\n 퍼즐 완료!\n");

    replay();

    double t=(double)(clock()-tStart)/CLOCKS_PER_SEC;
    saveRank(nMove,t);

    return 0;
}