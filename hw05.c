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

//翻棋
int rule4(int i,int j,int k,int m,int color){
    if(i>k && j>m){
        for(int s=1;i-s>k && j-s>m ;s++){
            chessBoard[i-s][j-s]=color;
        }
    }

    if(i>k && j<m){
        for(int s=1;i-s>k && j+s<m ;s++){
            chessBoard[i-s][j+s]=color;
        }
    } 

    if(i<k && j>m){
        for(int s=1;i+s<k && j-s>m ;s++){
            chessBoard[i+s][j-s]=color;
        }
    } 

    if(i<k && j<m){
        for(int s=1;i+s<k && j+s<m ;s++){
            chessBoard[i+s][j+s]=color;
        }
    } 

    if(i==k){
        if(j>m){
            int s;
            for(int s=1; j-s>m ;s++){
                chessBoard[i][j-s]=color;
            }
        }
        else{
            int s;
            for(int s=1;j+s<m ;s++){
                chessBoard[i][j+s]=color;
            }
        }
    }

    if(j==m){
        if(i>k){
            int s;
            for(int s=1;i-s>k;s++){
                chessBoard[i-s][j]=color;
            }
        }
        else{
            for(int s=1;i+s<k ;s++){
                chessBoard[i+s][j]=color;
            }
        }
    } 
}

//選擇下子位置
int rule3(int i,int j,int color){
    int newx,newy;
    printf("Which one do you want to choose?\n");
    scanf("%d,%d",&newx,&newy);
    printf("\n");

    chessBoard[newx][newy]=color;
    rule4(i,j,newx,newy,color);
    chessBoard_();
    askPosition_();
}

//判斷該方向是否有子可下
int rule2(int x,int i,int y,int j){
    int chance=0;
        for(int k=1;x+k*i<7 && x+k*i>-1 &&y+k*j<7 && y+k*j>-1 && k<7;k++){
            if(chessBoard[x+k*i][y+k*j]==0){
                printf("You can choose (%d,%d).  ",x+k*i,y+k*j);
                printf("%d steps away from (%d,%d).\n",k,x,y);                              
                chance++;
            }
        }

        if(chance==0){
            int color;
            color=chessBoard[x][y];
            printf("There are no pieces to play during the round.\n");
            allPossibleSituations(3-color);
        }
    return 0;
}

//判斷8個方向中是否有非該回合顏色的棋子
int direction(int x,int y,int color){
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){

            if(chessBoard[x][y]!=chessBoard[x+i][y+j] ){
                if(chessBoard[x+i][y+j]==3-color){
                    rule2(x,i,y,j);
                }              
            }           
        }
    }
}

//找出所有該回合的棋子
int allPossibleSituations(int color){  
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(chessBoard[i][j]==color){
                    direction(i,j,color);
                }
            }
        }
    
}