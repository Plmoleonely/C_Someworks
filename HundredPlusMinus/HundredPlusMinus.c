//U10810026 地生三 王均揚 
//輸入兩個一百位數以內的數做加減法，並可以決定是否重新執行此程式，剩下的註解在下方。
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define ArraySize 101

int main()
{   
    //字元陣列A跟B。
    char A[ArraySize];
    char B[ArraySize];
    
    //轉型成int陣列的A跟B，sftTemp為轉型時暫放的容器。
    int cvtA[ArraySize];
    int cvtB[ArraySize];
    int sftTemp[ArraySize];
    
    //字元0在int中為48，確定輸入的首位數字不可為0。
    printf("Pls enter ur first number\n");
    scanf("%s",&A);
    printf("Pls enter ur second number\n");
    scanf("%s",&B);
    assert(A[0] != 48);
    assert(B[0] != 48);
    
    int countA = 0;
    int countB = 0;
    
    //把字元換成int的方式，0~9在字元中為48~57，故減48得到該數字，A[i] != 0意思為非NULL時，將繼續迴圈。
    for(int i = 0;A[i] != 0;i++){
        countA++;
        cvtA[i] = A[i] - 48;
    }
    printf("MountA:%d\n",countA);
    for(int i = 0;B[i] != 0;i++){
        countB++;
        cvtB[i] = B[i] - 48;
    }
    printf("MountB:%d\n",countB);
    assert(countA && countB <= ArraySize);

    //選擇相加或相減。
    int choice = 0;
    printf("Select mode, 1 for PLUS, 2 for MINUS\n");
    scanf("%d", &choice);

    //shift為兩個數的數字量差
    int shift = 0;
    int maxCount = 0;
    
    //此迴圈為將數字靠右對齊，且較短的數字前方補0，直到該長度與較長的數字相同。
    if(countA > countB){
        shift = (countA - countB);
        maxCount = countA;
        for(int i = 0;i <= (countB - 1);i++){
            sftTemp[i] = cvtB[i];
            //printf("%d\n",sftTemp[i]);
        }
        for(int i = 0;i <= shift - 1;i++){
            cvtB[i] = 0;
        }
        for(int i = shift;i <= (countA - 1);i++){
            cvtB[i] = sftTemp[i - shift];
        }
        for(int i = 0;i <= (countA - 1);i++){
            //printf("%d",cvtB[i]);
        }
    }
    else if (countB > countA){
        shift = (countB - countA);
        maxCount = countB;
        for(int i = 0;i <= (countA - 1);i++){
            sftTemp[i] = cvtA[i];
            //printf("%d\n",sftTemp[i]);
        }
        for(int i = 0;i <= shift - 1;i++){
            cvtA[i] = 0;
        }
        for(int i = shift;i <= (countB - 1);i++){
            cvtA[i] = sftTemp[i - shift];
        }
        for(int i = 0;i <= (countB - 1);i++){
            //printf("%d",cvtA[i]);
        }
    }
    else{
        shift = (countB - countA);
        maxCount = countA;
    }
    
    //討論位數相同時的大小，bigger=0時代表B較大。
    int bigger = 0;
    if(countA == countB){
        for(int i = 0;i <= (maxCount - 1);i++){
            if(cvtA[i] > cvtB[i]){
                bigger++;
                break;
            }
            else{
                break;
            }
        }
    }

    //先將陣列初始化，ans為裝答案的陣列，expAns為當兩數數量相同，無法判斷大小時，使用的例外裝答案的陣列。
    int ans[ArraySize] = {0};
    int expAns[ArraySize] = {0};
    
    //計算加減法的方法。
    for(int i = (maxCount - 1);i >= 0;i--){
        if(choice == 1){
            ans[i] = cvtA[i] + cvtB[i];
            if(ans[i] >= 10 && i > 0){
                ans[i] = ans[i] % 10;
                cvtA[i - 1]++;
            }
        }else if(choice == 2){
            if(countA > countB){
                ans[i] = cvtA[i] - cvtB[i];
                if(ans[i] < 0 && i > 0){
                    ans[i] = ans[i] + 10;
                    cvtA[i - 1]--;
                }
            }else if(countB > countA){
                ans[i] = cvtB[i] - cvtA[i];
                if(ans[i] < 0 && i > 0){
                    ans[i] = ans[i] + 10;
                    cvtB[i - 1]--;
                }
            }else if(countA == countB && bigger != 0){
                ans[i] = cvtA[i] - cvtB[i];
                if(ans[i] < 0 && i > 0){
                    ans[i] = ans[i] + 10;
                    cvtA[i - 1]--;
                }
            }else{
                expAns[i] = cvtB[i] - cvtA[i];
                if(expAns[i] < 0 && i > 0){
                    expAns[i] = expAns[i] + 10;
                    cvtB[i - 1]--;
                }
            }
        }
    }

    //用迴圈將答案列出。
    printf("The Ans is:");
    for(int i = 0;i <= (maxCount - 1);i++){
        if(countA != countB || choice == 1 || bigger > 0){
            assert(ans[0] >= 0 && ans[0] <= 19); //將溢位的可能排除。
            printf("%d",ans[i]);
        }
        else if(countA == countB && bigger == 0){
            assert(expAns[0] >= 0);   //將溢位的可能排除。
            printf("%d",expAns[i]);
        }
    }

    //重跑此程式
    int run = 0;
    printf("\nDo you run this program again? (1 for YES, 2 for NO)\n");
    scanf("%d",&run);
    if(run == 1){
        return main();
    }
    return 0;
}