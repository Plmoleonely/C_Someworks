#include <stdio.h>

main (){
    int i, j, z;
    for(i = 0, j = 100; i<j;i++,j--){
        z++;
        printf("i=%d, j=%d \n", i, j);
    }
    printf("%d, %d\n",i,z);
}