//U10810026 地生三 王均揚
//輸入多項式的最大次方、多項式每個次方係數值以及輸入要帶入的值可以計算出該多項式的值。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#define ArraySize 100
double polynomial(double x, double coef[], int n);

int main() {
    double x = 0;   //帶入值
    int n = 0;  //多項式最大次方
    double coef[ArraySize]; //每個係數

    printf("Please enter the degree of the polynomial.\n"); //輸入最大次方數。
    scanf("%d", &n);
    assert(n <= 100);
    printf("Please enter the coefficient of the polynomial.(From GREATEST to LEAST.)\n");   //由大到小依序輸入對應次方的係數。
    for (int i = n; i >= 0; i--) {
        scanf("%lf", &coef[i]);
    }
    printf("Please enter the input for X.\n");  //輸入要計算的x。
    scanf("%lf", &x);
    printf("The value of polynomial is : %lf", polynomial(x, coef, n)); //最後顯示出答案。

   
}

double polynomial(double x, double coef[], int n) {
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += coef[i] * pow(x, i); //引入math.h使用計算次方函式，x的i次方。
    }
    return ans;
}
