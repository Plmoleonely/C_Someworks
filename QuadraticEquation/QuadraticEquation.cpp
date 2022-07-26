// 地生三 U10810026 王均揚
// 原本想說直接輸出輸入數字就好，但還是多加一點中文好了，所以程式碼看起來很冗長。
// 重根只會輸出一個值，所以不是少打。

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cmath>
#define STRINGLEN 80

void main()

{
	int a, b, c;
	double x1, x2, dis;
	char ask[STRINGLEN] = "方程式:ax^2+bx+c\n請依序輸入a,b,c";
	char aska[STRINGLEN] = "請輸入a:";
	char askb[STRINGLEN] = "請輸入b:";
	char askc[STRINGLEN] = "請輸入c:";
	char ans[STRINGLEN] = "根為:";
	char noans[STRINGLEN] = "判別式小於零，沒有實根";

	printf("%s\n", ask);
	printf("%s\n", aska);
	scanf("%d", &a);
	printf("%s\n", askb);
	scanf("%d", &b);
	printf("%s\n", askc);
	scanf("%d", &c);

	x1 = (- b + sqrt(b * b - 4 * a * c)) / (2*a);
	x2 = (- b - sqrt(b * b - 4 * a * c)) / (2*a);
	dis = b * b - 4 * a * c;

	if (dis > 0) {
		printf("%s\n%f\n%f\n", ans, x1, x2);
	}
	else if (dis == 0) {
		printf("%s%f\n", ans, x1);
	}
	else if (dis < 0) {
		printf("%s\n", noans);
	}
}

