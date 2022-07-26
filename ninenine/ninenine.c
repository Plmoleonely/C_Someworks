//U10810026 地生三  王均揚
//1*9個 (1+1)*9個   (1+2)*9個
//1+3   (1+1+3)     (1+2+3)*9個
//1+3+3 (1+1+3+3)   (1+2+3+3)*9個   

#include <stdio.h>

int main(){
    int i, j;

    for(i = 1;  i<= 9; i = i + 3){
        for(j = 1; j<= 9; j++){
        printf("%d* %d= %2d\t\t%d* %d= %2d\t\t%d* %d= %2d\n",i,j,i*j,i+1,j,(i+1)*j,i+2,j,(i+2)*j);
        }
        printf("\n");
    }
    return 0;
}