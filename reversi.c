#include <stdio.h>
#include <string.h>
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


int chessBoard_()
{
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d  ",chessBoard[i][j]);  
        }
        printf("\n");
    } 
}

int homeLobby_(){
    char answer1[4];
    printf("Welcome players to the game of Reversi.\n");
    printf("Do you want to start the game? yes/no \n");
    scanf("%s",&answer1);
    if(strcmp(answer1,"yes")==0){
        chessBoard_();}
    else{
        return 0;} 
}

int rule6(int i,int j,int color){
    int newx,newy;
    chessBoard[newx][newy]=color;
    flip(i,j,newx,newy,color);
    chessBoard_();

}

int rule5(int x,int i,int y,int j,int color){
        for(int k=1;x+k*i<7 && x+k*i>-1 &&y+k*j<7 && y+k*j>-1 && k<7;k++){
            if(chessBoard[x+k*i][y+k*j]==0){
                rule6(x+k*i,y+k*j,k);
                return k;   
            } 
        }
        return 0;
}

int flip(int i,int j,int k,int m,int color){
    if(i>k && j>m){
        int s;
        for(s=1;i-s>k && j-s>m ;s++){
            chessBoard[i-s][j-s]=color;
        }
    }

    if(i>k && j<m){
        int s;
        for(s=1;i-s>k && j+s<m ;s++){
            chessBoard[i-s][j+s]=color;
        }
    } 

    if(i<k && j>m){
        int s;
        for(s=1;i+s<k && j-s>m ;s++){
            chessBoard[i+s][j-s]=color;
        }
    } 

    if(i<k && j<m){
        int s;
        for(s=1;i+s<k && j+s<m ;s++){
            chessBoard[i+s][j+s]=color;
        }
    } 

    if(i==k){
        if(j>m){
            int s;
            for(s=1; j-s>m ;s++){
                chessBoard[i][j-s]=color;
            }
        }
        else{
            int s;
            for(s=1;j+s<m ;s++){
                chessBoard[i][j+s]=color;
            }
        }
    }

    if(j==m){
        if(i>k){
            int s;
            for(s=1;i-s>k;s++){
                chessBoard[i-s][j]=color;
            }
        }
        else{
            int s;
            for(s=1;i+s<k ;s++){
                chessBoard[i+s][j]=color;
            }
        }
    } 
}

int rule3(int i,int j,int color){
    int newx,newy;
    printf("Which one do you want to choose?\n");
    scanf("%d,%d",&newx,&newy);
    printf("\n");

    chessBoard[newx][newy]=color;
    flip(i,j,newx,newy,color);
    chessBoard_();
}

int rule2(int x,int i,int y,int j,int color){
        for(int k=1;x+k*i<7 && x+k*i>-1 &&y+k*j<7 && y+k*j>-1 && k<7;k++){
            if(chessBoard[x+k*i][y+k*j]==0){
                printf("You can choose (%d,%d).  ",x+k*i,y+k*j);
                printf("%d steps away from (%d,%d).\n",k,x,y);
            }
        }
        rule3(x,y,color);
}

int direction(int x,int y,int color){


    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(chessBoard[x][y]!=chessBoard[x+i][y+j] ){
                if(chessBoard[x+i][y+j]==3-color){
                    if(color==black){
                       rule2(x,i,y,j,color); 
                    }
                    else rule2(x,i,y,j,color);
                }              
            }
            
        }
    }
}

int allPossibleSituations(int color){
    
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(chessBoard[i][j]==color){
                    direction(i,j,color);
                }
            }
        }
    
}


int askPosition_(){

    int i,j;
    printf("Now it's black's turn.\n");
    allPossibleSituations(black);
}

int computerTurn_(){

    int i,j;
    printf("Now it's white's turn.\n");
    allPossibleSituations(white);
}

int main(){
    homeLobby_();
    askPosition_();
    computerTurn_();

    return 0;
}