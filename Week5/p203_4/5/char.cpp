#include <stdio.h>

int main(){
    char map[4][4];
    char ch='A';

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            map[i][j]=ch++;
        }
    }

    map[3][3]=' ';

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%3c",map[i][j]);
        }
        printf("\n");
    }
}