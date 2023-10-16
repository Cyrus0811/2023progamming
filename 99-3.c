#include <stdio.h>

int main (void){
    
    for(int i=1;i<=3;i++){
        for(int j=1;j<=9;j++){
            
            int k=i+3;
            int m=i+6;

            printf("%dx%d=%d ",i,j,j*i);

            if(i*j>9)
                printf(" ");
            else
                printf("  ");
            
            printf("%dx%d=%d ",k,j,k*j);


             if(k*j>9)
                printf(" ");
            else
                printf("  ");
            printf("%dx%d=%d\n",m,j,m*j);

        }
    printf("\n");} 
    return 0;
}