#include <stdio.h>
#include <string.h>
#define EQU(p,q) (p.x==q.x,p.y==q.y) 
typedef struct axis axis_t;
typedef struct stack stack_t;
char mark[10][10]={0};
int maze[10][10] ={
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

struct axis{
    int x;
    int y;
};

struct stack{
    axis_t elements[5*5];
    int top;
};

int isEmpty(stack_t *stackPtr){
    if(stackPtr->top==-1) return 1;
    else return 0;
}

int isFull(stack_t *stackPtr){
    if(stackPtr->top==99) return 1;
    else return 0;
}

axis_t pop(stack_t *stackPtr){
    axis_t temp={-1,-1};
    if (isEmpty(stackPtr)==1) return temp;
    return stackPtr->elements[stackPtr->top--];
}

int push(stack_t *stackPtr,axis_t element){
    if (isFull(stackPtr)==1) return 0;
    stackPtr->top++;
    stackPtr->elements[stackPtr->top]=element;
    return 1;
}

axis_t findMove(stack_t *stackPtr,axis_t position){
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(i+j!=0 && (-1.5<i+j && i+j<1.5)){
                axis_t space;
                space.x=position.x+i;
                space.y=position.y+j;

                if(maze[space.x][space.y]==0 &&
                    mark[space.x][space.y]!=2){
                    mark[space.x][space.y]=2;
                    push(stackPtr,space);
                    }
            }
        }
    }
    return pop(stackPtr);
}

int main(){
    stack_t myStack;
    axis_t currentPosition;
    axis_t entry={1,0};
    axis_t exit={6,9};
    axis_t noExit={-1,-1};

    myStack.top=-1;
    currentPosition=entry;
    mark[currentPosition.x][currentPosition.y]=2;

    while (!EQU(currentPosition,exit)){
        currentPosition=findMove(&myStack,currentPosition);
        printf("move to %d,%d\n",currentPosition.x,currentPosition.y);
        if(EQU(currentPosition,noExit)){
            printf("no Exit\n");
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    printf(" %d ",mark[i][j]+maze[i][j]);
                }
                printf("\n");
            }
            break;
        }
        if(EQU(currentPosition,exit)){
            printf("good\n");
            break;  
        }     
    }
}