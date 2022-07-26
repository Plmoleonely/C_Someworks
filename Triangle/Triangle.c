//U10810026 地生三 王均揚
//double型態的scanf要設%lf不然會出錯，但目前vs有自行設定所以不用，但保險起見我還是加上去。

#include <stdio.h>
#include <math.h>
#include <string.h>

#define Stringlength 80

void main()
{
    double a, b, c;
    double s, area;
    char ask[Stringlength] = "請輸入三角形三邊長";
    char ansyes[Stringlength] = "這個三角形的面積為:";
    //下面這列原本要寫可以重新輸入，但因為最後一行的else會產生小bug所以先暫時不採用。
    char reset[Stringlength] = "邊長不能輸入<=0的值歐~請重新輸入!!";
    printf("%s\n" ,ask);
    scanf("%lf%lf%lf", &a, &b, &c);
    
    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));

    if(a + b > c && a + c > b && b + c > a){
        printf("%s %f\n", ansyes, area);
    }
    else{
        printf("%d\n", 0);
    }
}