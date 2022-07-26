// u10810026 地生三 王均揚
#include <stdio.h>
#include <string.h>
#define StringLength 80
#define StringNumber 100

int main(void) {

    char string[StringNumber][StringLength];
    int num = 0;    //統計實際上有幾個單字。
    int stringTimes[StringNumber] = {0};
    int num2 = 0;   //紀錄大於一個的個數。
    char string2[StringNumber][StringLength];
    while (scanf("%s", string[num]) != EOF && num <= 100) {
        num++;
    }

    for (int i = 0; i <= num - 2; i++) {
        for (int j = 0; j <= num - 2 - i; j++) {
            if (strcmp(string[j], string[j + 1]) > 0) {
                char temp[StringLength];
                strcpy(temp, string[j]);
                strcpy(string[j], string[j + 1]);
                strcpy(string[j + 1], temp);
            }
        }
    }

    for (int i = 0; i <= num - 1; i++) {
        stringTimes[i] = 1;
        strcpy(string2[i], string[i]);
    }

    for (int i = 0; i <= num - 1; i++) {
        if (strcmp(string[i], string[i + 1]) == 0) {
            stringTimes[i]++;
            stringTimes[i + 1] = stringTimes[i];
        }
    }

    for (int i = 0; i <= num - 2; i++) {
        for (int j = 0; i <= num - 2 - i; j++) {
            if (stringTimes[j] < stringTimes[j + 1]) {
                int temp = stringTimes[j];
                stringTimes[j]= stringTimes[j + 1];
                stringTimes[j + 1] = temp;

                char tempChar[StringLength];
                strcpy(tempChar, string2[j]);
                strcpy(string2[j], string2[j + 1]);
                strcpy(string2[j + 1], tempChar);
            }
        }
    }

    for (int i = 0; i <= num; i++) {
        if (stringTimes[i] > 1) {
            num2++;
        }
    }

    for (int i = 0; i <= num2; i++) {
        if (strcmp(string2[i], string2[i + 1]) == 0) {
            printf("%d %s", stringTimes[i], string2[i]);
        }
    }

    for (int i = num2 + 1; i <= num; i++) {
        printf("1 %s", string2[i]);
    }

    return 0;
}