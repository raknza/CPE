#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int count,i,j;
    char numa[31]={};
    char numb[31]={};
    int num1,num2;
    int sum[30];
    scanf("%d",&count);
    getchar();
    for(i=0;i<count;i++){
        for(j=0;j<31;j++){
            numa[j] = '\0';
            numb[j] = '\0';
        }
        num1 = 0;
        num2 = 0;
        scanf("%s %s",numa,numb);
        int length1 = strlen(numa);
        int length2 = strlen(numb);
        int temp = 1;
        for(j=length1-1;j>=0;j--){
            num1 = num1 + temp*(numa[j]-'0');
            temp = temp*2;
        }
        temp = 1;
        for(j=length2-1;j>=0;j--){
            num2 = num2 + temp*(numb[j]-'0');
            temp = temp*2;
        }
        int gcd = 2;
        int flag = 0;
        while( gcd<= num1 && gcd <=num2 ){
            if( num1%gcd == 0 && num2%gcd == 0 ){
                flag = 1;
                break;
            }
            else
                gcd++;
        }
        if(flag == 1)
            printf("Pair #%d: All you need is love!\n",i+1);
        else
            printf("Pair #%d: Love is not all you need!\n",i+1);

    }
    return 0;
}

