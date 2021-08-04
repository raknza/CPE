#include <stdio.h>
#include <stdlib.h>
#define con 131071
int main()
{
    char c;
    int temp_length=0;
    int length = 0;
    int digits = 1;
    int remainder=0,i,j;
    int temp[101]={};
    int intgerA[10001]={};
    while( scanf("%c",&c)!=EOF){
        if(c !='#'){
            if( c!='\n')
                temp[temp_length++] = (c - '0');
        }
        else{
            for(i=temp_length-1;i>=0;i--){
                intgerA[length] = intgerA[length] + temp[i]*digits;
               for(j=0;j<length;j++){
                    if(intgerA[j] >=10){
                        intgerA[j+1] = intgerA[j+1] + intgerA[j]/10;
                        intgerA[j] = intgerA[j]%10;
                        if(j == length-1)
                            length++;
                    }
                }
                digits = digits * 2;
            }
            for(i=length;i>=0;i--){
                //printf("int:%d\n",intgerA[i]);
                if(i==0)
                    remainder = intgerA[i]%con;
                if(intgerA[i]/con>0){
                    intgerA[i] = intgerA[i]%con;
                    intgerA[i-1] = intgerA[i]*10 + intgerA[i-1];
                }
                else{
                    intgerA[i-1] = intgerA[i]*10 + intgerA[i-1];
                    //printf("i-1:%d\n",sum_intger[i-1]);
                }
            }
            if (remainder == 0)
                printf("YES\n");
            else
                printf("NO\n");
            for(i=length;i>=0;i--)
                intgerA[i] = 0;
            digits = 1;
            length = 0;
            temp_length = 0;
            remainder = 0;
        }
    }
    return 0;
}
