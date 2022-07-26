// u10810026 地生三 王均揚
#include <stdio.h>
#include <string.h>
#define StringLength 80
#define StringNumber 100

int main(void) {
    int i, j;
    char string[StringNumber][StringLength];
    int num = 0;    //統計實際上有幾個單字。
    char* stringPtr[StringNumber];  //儲存位址的陣列指標。
    char* tempPtr;
    int stringTimes[StringNumber] = {0};
    int maxCount = 0;   //最大次數的次數。

    while (scanf("%s", string[num]) != EOF && num <= 100) {
        stringPtr[num] = string[num];
        num++;
    }

    for (i = 0; i <= num - 2; i++) {
        for (j = 0; j <= num - 2 - i; j++) {
            if (strcmp(stringPtr[j], stringPtr[j + 1]) > 0) {
                tempPtr = stringPtr[j];
                stringPtr[j] = stringPtr[j + 1];
                stringPtr[j + 1] = tempPtr;
            }
        }
    }

    for(i = 0; i < num;){
        for(j = i + 1; j < num && strcmp(stringPtr[i], stringPtr[j]) == 0; j++);
        stringTimes[i] = j - i;
        if(maxCount > stringTimes[i]){
            maxCount = maxCount;
        }
        else{
            maxCount = stringTimes[i];
        }
        i = j;
    }

    for(i = maxCount; i >= 1; i--){
        for(j = 0; j < num; j++){
            if(stringTimes[j] == i){
                printf("%d %s\n", i, stringPtr[j]);
            }
        }
    }
    
    return 0;
}