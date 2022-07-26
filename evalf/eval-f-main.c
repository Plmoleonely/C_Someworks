//U10810026 地生三  王均揚
#include <stdio.h>

int eval_f(int *iptr[], int n, int *index);

#define N 256

int main(void)
{
  int n = 0;  //有幾組xy。
  int x, y;
  int xy[2 * N];  //存放x,y的陣列。
  int xy_n = 0; //x跟y的個數總和。
  int max, max_index;
  int *iptr[N];

  while (scanf("%d%d", &x, &y) != EOF) {
    iptr[n] = &(xy[xy_n]);
    n++;
    xy[xy_n] = x;
    xy_n++;
    xy[xy_n] = y;
    xy_n++;
  }

  max = eval_f(iptr, n, &max_index);
  printf("%d %d\n", max, max_index);

  return 0;
}

int eval_f(int *iptr[], int n, int *index){
  int maxValue = 4 * (*iptr[0]) - 6 * (*(iptr[0] + 1));
  *index = 0;

  for(int i = 0; i <= n - 1; i++){
    int value = 4 * (*iptr[i]) - 6 * (*(iptr[i] + 1));
    if(value >= maxValue){
      maxValue = value;
      *index = i;
    }
  }
  
  return maxValue;
}
