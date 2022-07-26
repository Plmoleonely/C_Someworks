#include<stdio.h>
#include <assert.h>
#define ARRAYSIZE 32

int main(void){
    int n = ARRAYSIZE;
    int rabbit[n];
    int fox[n];
    rabbit[0] = 100;
    fox[0] = 100;

    for(int i = 1; i < n; i++){
        rabbit[i] = 4*rabbit[i - 1] - 2*fox[i - 1];
        fox[i] = rabbit[i - 1] + fox[i - 1];
    }

    int year;
    scanf("%d", &year);
    assert(year >= 0);
    printf("第%d年,兔有%d隻,狐有%d隻。\n", year, rabbit[year], fox[year]);

    return 0;
}