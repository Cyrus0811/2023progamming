#include <stdio.h>

int main(void){

    for(int i=1;i<=7;i=i+3){
        for(int j=1;j<=9;j++){

            int k=i+1;
            int m=i+2;
            printf("%dx%d=%2d  %dx%d=%2d  %dx%d=%2d\n",i,j,i*j,k,j,k*j,m,j,m*j);
                    
        }

        printf("\n");
    }
}
