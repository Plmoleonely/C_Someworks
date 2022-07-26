//U10810026 地生三 王均揚

#include <stdio.h>
#include <assert.h>
#define ARRAYSIZE 10

main(){
    int n;
    scanf("%d", &n);
    assert(n % 2 != 0 && n < ARRAYSIZE);
    int array[ARRAYSIZE][ARRAYSIZE];
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            scanf("%d", &(array[r][c]));
        }
    }
    
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int row = (n - 1) / 2;
    int col = (n - 1) / 2;
    int direction = 0;

    printf("\n%2d ", array[row][col]);
    for(int dist = 1; dist < n; dist++){
        for(int step = 0; step < ((dist == n - 1)? 3 : 2); step++){
            for(int i = 0; i < dist; i++){
                row += dr[direction];
                col += dc[direction];
                int counter;
                counter += 1;   //計數器，每n個一數。

                if((counter % n) == 0 ){
                    printf("\n");   //每n個換列。
                }

                printf("%2d ", array[row][col]);    //2d靠右對齊。
            }
            direction = ((direction + 1) % 4);
        }
    }
}