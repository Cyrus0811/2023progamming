#include <stdio.h>
#include <string.h>
#define white 2
#define black 1
#define INBOUND (x+k*i<7 && x+k*i>-1 &&y+k*j<7 && y+k*j>-1 && k<7)
void askPosition_();
int result02_,result04_;

int chessBoard[8][8]={
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,2,1,0,0,0},
                    {0,0,0,1,2,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}};


void chessBoard_()
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

void flip(int x,int y,int color){
    int newx,newy;
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(chessBoard[x][y]!=chessBoard[x+i][y+j] ){
                if(chessBoard[x+i][y+j]==3-color){
                    for(int k=1;INBOUND;k++){
                        if(chessBoard[x+k*i][y+k*j]==3-color && 
                           chessBoard[x+(k+1)*i][y+(k+1)*j]==color){
                            chessBoard[x+k*i][y+k*j]=color;
                        }
                    }
                }              
            }           
        }
    }
}

int rule4(int x,int i,int y,int j,int color){
    int maxStep=0 ,step=-1;
    for(int k=1;INBOUND;k++){
        if(chessBoard[x+k*i][y+k*j]==0){
            step=k;
            break;
        }
    }

    int newx,newy=-1;
    for(int k=1;INBOUND;k++){
        if(chessBoard[x+k*i][y+k*j]==0){
            if(step>maxStep){
                maxStep=step;
                newx=x+k*i;
                newy=y+k*j;
                break;;
            }
        }
    }
    if(maxStep>0) return maxStep;
    if(step<0) return 0;
}

void rule3(int newx,int newy,int color){

    chessBoard[newx][newy]=color;

    flip(newx,newy,color);
    chessBoard_();
    printf("\n");
}

int rule2(int x,int i,int y,int j,int color){
    int step=0;
    for(int k=1;INBOUND;k++){
        if(chessBoard[x+k*i][y+k*j]==0){
            step=k;
            return step;
        }
    }
    if(step<0) return 0;
}

int conversion(int x,int i,int y,int j,int color){
    if(color==black){
        rule2(x,i,y,j,color);
        int k=rule2(x,i,y,j,color);
        if(k!=0){
            printf("You can choose ");
            printf("(%d,%d)and then capture %d pieces.  ",x+k*i,y+k*j,k);
        }
        result02_== rule2(x,i,y,j,color);         
    }
    else {
        rule4(x,i,y,j,white);/*
        int k=rule2(x,i,y,j,color);
        printf("%d,",k);*/
    } 
}

int direction(int x,int y,int color){
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(chessBoard[x][y]!=chessBoard[x+i][y+j] ){
                if(chessBoard[x+i][y+j]==3-color){               
                    conversion(x,i,y,j,color);
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

void askPosition_(){
    int i,j=0;
    printf("Now it's black's turn.\n");
    allPossibleSituations(black);
    printf("Which one do you want to choose?\n");
    scanf("%d,%d",&i,&j);
    chessBoard[i][j]=black;  
    rule3(i,j,black);
}

void computerTurn_(){
    printf("Now it's white's turn.\n");
    allPossibleSituations(white);

}

int gameLogic_(){
    askPosition_();
    computerTurn_();
    int i,j,blackChessNumber,whiteChessNunber;

    while (result02_!=0 && result04_!=0){
        askPosition_();
        computerTurn_();
    }

    while(result02_!=0 || result04_!=0){
        if(result02_==0) askPosition_();
        if(result04_==0) computerTurn_();
        if(result02_ && result04_==0) break;
    }
    blackChessNumber=whiteChessNunber=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(chessBoard[i][j]==black) blackChessNumber++;
            if(chessBoard[i][j]==white) whiteChessNunber++;
        }
    }
    if( blackChessNumber>whiteChessNunber) printf("Black victory!!\n");
    if( blackChessNumber<whiteChessNunber) printf("White victory!!\n");

}

int main(){
    homeLobby_();
    askPosition_();
    computerTurn_();
    gameLogic_();
    return 0;
}
