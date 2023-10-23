#include <stdio.h>
#include <string.h>

int chessBoard[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}
                        ,{0,0,0,2,1,0,0,0},{0,0,0,1,2,0,0,0}
                        ,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};

int chessBoard_()
{
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d",chessBoard[i][j]);  
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

int askPosition_();

int rule4(int i,int j,int k,int m,int color){
   //i,j是實際的位置從0到7
    if(i>k && j>m){
        int s;
        for(s=1;i-s>k && j-s>m ;s++){
            chessBoard[i-s][j-s]=color;
            printf("(%d,%d)",i-s,j-s);
        }
    }

    if(i>k && j<m){
        int s;
        for(s=1;i-s>k && j+s<m ;s++){
            chessBoard[i-s][j+s]=color;
            printf("(%d,%d)",i-s,j+s);
        }
    } 

    if(i<k && j>m){
        int s;
        for(s=1;i+s<k && j-s>m ;s++){
            chessBoard[i+s][j-s]=color;
            printf("(%d,%d)",i+s,j-s);
        }
    } 

    if(i<k && j<m){
        int s;
        for(s=1;i+s<k && j+s<m ;s++){
            chessBoard[i+s][j+s]=color;
            printf("(%d,%d)",i+s,j+s);
        }
    } 

    if(i==k){
        if(j>m){
            int s;
            for(s=1; j-s>m ;s++){
                chessBoard[i][j-s]=color;
                printf("(%d,%d)",i,j-s);
            }
        }
        else{
            int s;
            for(s=1;j+s<m ;s++){
                chessBoard[i][j+s]=color;
                printf("(%d,%d)",i,j+s);
            }
        }
    }

    if(j==m){
        if(i>k){
            int s;
            for(s=1;i-s>k;s++){
                chessBoard[i-s][j]=color;
                printf("(%d,%d)",i-s,j);
            }
        }
        else{
            int s;
            for(s=1;i+s<k ;s++){
                chessBoard[i+s][j]=color;
                printf("(%d,%d)",i+s,j);
            }
        }
    } 
}


int rule3(int i,int j,int color){
    int newx,newy;
    char answer2[3];
    printf("Which one do you want to choose?\n");
    scanf("%d,%d",&newx,&newy);
    printf("Are you sure? y/n \n");
    scanf("%s",&answer2);
    if(strcmp(answer2,"y")==0){
        chessBoard[newx-1][newy-1]=color;
        rule4(i,j,newx-1,newy-1,color);
        chessBoard_();
        askPosition_();
    }
    else{
        chessBoard_();
        askPosition_();
    } 
    

}

int rule2(int i,int j){
    int center;
    int x,y,k,color;

    center=chessBoard[i][j];
    if(center==1){
        color=2;
    }
    else{
        color=1;
    }

    x=i; y=j;
    int a,b,c,d,e,f,g,h;
    a=chessBoard[i-1][j-1];
    b=chessBoard[i-1][j];
    c=chessBoard[i-1][j+1];
    d=chessBoard[i][j-1];
    e=chessBoard[i][j+1];
    f=chessBoard[i+1][j-1];
    g=chessBoard[i+1][j];
    h=chessBoard[i+1][j+1];
    //西北方
    if(a==color){
        for(k=1;y-k>-1 && x-k>-1;k++){
            if(chessBoard[x-k][y-k]==0){
                printf("1You can choose (%d,%d).\n",x-k+1,y-k+1);
                break;
            }

        }  
    }
    //北方
    if(b==color){
        
        for(k=1;x-k>-1;k++){
            if(chessBoard[x-k][y]==0){
                printf("2You can choose (%d,%d).\n",x-k+1,y+1);
                break;
            }   
           
        } 
    }
    //東北方
    if(c==color){
        for(k=1;y+k<8 && x-k>-1;k++){
            if(chessBoard[x-k][y+k]==0){
                printf("3You can choose (%d,%d).\n",x-k+1,y+k+1);
                break;
            }           
        }
    } 

    //東方
    if(e==color){
        for(k=1;y+k<8;k++){
            if(chessBoard[x][y+k]==0){
                printf("4You can choose (%d,%d).\n",x+1,y+k+1);
                break;
            }          
        } 
    }
    //東南方
    if(h==color){
        for(k=1;y+k<8 && x+k<8;k++){
            if(chessBoard[x+k][y+k]==0){
                printf("5You can choose(%d,%d).\n",x+k+1,y+k+1);
                break;
            }           
        }    
    }
    //南方
    if(g==color){
        for(k=1;x+k<8;k++){
            if(chessBoard[x+k][y]==0){
                printf("6You can choose(%d,%d).\n",x+k+1,y+1);
                break;
            }           
        }
    }
    //西南方
    if(f==color){
        for(k=1;y-k>-1 && x+k<8;k++){
            if(chessBoard[x+k][y-k]==0){
                printf("7You can choose(%d,%d).\n",x+k+1,y-k+1);
                break;
            }           
        } 
    }
    //西方
    if(d==color){
        for(k=1;y-k>-1;k++){
            if(chessBoard[x][y-k]==0){
                printf("8You can choose (%d,%d).\n",x+1,y-k+1);
                break;
            }         
        } 
    }            
}

int rule1(int i,int j){
    int sum=0;
    int a,b,c,d,e,f,g,h;

    a=chessBoard[i-1][j-1];
    b=chessBoard[i-1][j];
    c=chessBoard[i-1][j+1];
    d=chessBoard[i][j-1];
    e=chessBoard[i][j+1];
    f=chessBoard[i+1][j-1];
    g=chessBoard[i+1][j];
    h=chessBoard[i+1][j+1];
    if(i==1 && j==1){
        a,b,c,d,f=0;        
    }
    if(i==8 && j==8){
        c,e,f,g,h=0;
    }
    if(i-1<0 && j-1>0 && j<8){
        a,b,c=0;
    }
    if(i+1>8 && j-1>0 && j<8){
        f,g,h=0;
    }
    if(j-1<0 && i-1>0 && i<8){
        a,d,f=0;
    }
    if(j+1>8 && i-1>0 && i<8){
        c,e,h=0;
    }
    if(i-1<0 && j+1>8){
        a,b,c,e,h=0;
    }
    if(i+1>8 && j-1<0){
        a,d,f,g,h=0;
    }
    sum=a+b+c+d+e+f+g+h;
    while(sum==0){
        printf("This position cannot be used.\n");
        break;
    }
}

int askPosition_(){
    int i,j,a1,b1;
    printf("Please enter the position.\n");
    scanf("%d,%d",&i,&j);

    a1=i-1;
    b1=j-1;

     while(chessBoard[a1][b1]==0){
        printf("There is no chess.\n");
        rule1(a1,b1);
        printf("Please enter the position.\n");
        scanf("%d,%d",&i,&j);
        a1=i-1; b1=j-1;

    }

    if(chessBoard[a1][b1]==1){
        printf("There is black chess.\n");
        rule2(a1,b1);
        rule3(a1,b1,1);
    }
    else{
        printf("There is white chess.\n");
        rule2(a1,b1);
        rule3(a1,b1,2);
    }
}


int main(){
    homeLobby_();
    askPosition_();
    return 0;    
}