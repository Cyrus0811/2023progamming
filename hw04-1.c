#include <stdio.h>
#define white 2
#define black 1
int askPosition_();
int chessBoard[8][8]={
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,2,1,0,0,0},
                    {0,0,0,1,2,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}};



int rule2(int x,int i,int y,int j){
        for(int k=1;x+k*i<7 && x+k*i>-1 &&y+k*j<7 && y+k*j>-1 && k<7;k++){
            if(chessBoard[x+k*i][y+k*j]==0){
                printf("You can choose (%d,%d).  ",x+k*i,y+k*j);
                printf("%d steps away from (%d,%d).\n",k,x,y);
                return 1;
            }
        }
}

int direction(int x,int y){
    int center,color;
    center=chessBoard[x][y];
    if(center==black){
        color=white;
    }
    else{
        color=black;
    }

    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(chessBoard[x][y]!=chessBoard[x+i][y+j] ){
                if(chessBoard[x+i][y+j]==color){
                    rule2(x,i,y,j);
                }              
            }
            
        }
    }
    return 0;
}

int allPossibleSituations(int color){
    if(3-color==2){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(chessBoard[i][j]==color){
                    direction(i,j);
                }
            }
        }
    }
}