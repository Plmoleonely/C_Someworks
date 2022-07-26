#include<stdio.h>
#include <assert.h>
int rabbit(int t){
    int r = 100;
    if(t == 0){
        return r;
    }
    return (4*rabbit(t - 1) - 2*fox(t - 1));
}
int fox(int t){
    int f = 100;
    if(t == 0){
        return f;
    }
    return (rabbit(t - 1) + fox(t -1));
}

int main(void){
    int t = 0;
    scanf("%d", &t);
    assert(t >= 0);
    printf("第%d年,兔有%d隻,狐有%d隻。\n", t, rabbit(t), fox(t));
}