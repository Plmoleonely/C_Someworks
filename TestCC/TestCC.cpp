// u10810026 地生三 王均揚
#include <stdio.h>
#include <string.h>
#define StringLength 80
#define StringNumber 100

int main(void) {

    char string[StringNumber][StringLength];
    int num = 0;    //統計實際上有幾個單字。
    int stringTimes[StringNumber];

    while (scanf("%s", string[num]) != EOF && num <= 100) {
        num++;
    }

    for (int i = 0; i <= num - 1; i++) {
        for (int j = 0; j <= num - 1 - i; j++) {
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
        if (strcmp(string[i], string[i + 1]) == 0) {
            stringTimes[i]++;
            stringTimes[i + 1] = stringTimes[i];
        }
    }

    for (int i = 0; i <= num; i++) {
        if (strcmp(string[i], string[i + 1]) == 0) {
            continue;
        }
        else {
            printf("%d %s\n", stringTimes[i], string[i]);
        }
    }

    return 0;
}