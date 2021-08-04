#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE二顆星考題 - UVA10295 20171026

*/
int main()
{
    int N,F,i,j,count = 0;
    while(scanf("%d %d",&N,&F)!= EOF){
        if(N == F && N == 0)
            break;
        char intger[1000][1000];
        int sum_intger[1000]={};
        int average[1000] = {};
        int length[1000];
        int sum_length = 0;
        int ave_length = 0;
        for(i=0;i<N;i++){
        	scanf("%s",intger[i]);
            length[i] = strlen(intger[i]);
            if(length[i]>sum_length)
                sum_length = length[i];
            // 相加
            for(j=length[i]-1;j>=0;j--)
                sum_intger[(length[i]-1)-j] = sum_intger[(length[i]-1)-j] + intger[i][j] - '0';
        }
        // 進位
        for(i=0;i<=sum_length;i++){
            if(sum_intger[i]>=10){
                sum_intger[i+1] = sum_intger[i+1] + sum_intger[i]/10;
                sum_intger[i] = sum_intger[i]%10;
            }
        }
        // 輸出總金額
        int start = 0;
        printf("Bill #%d costs ",++count);
        for(i=sum_length;i>=0;i--){
            if(sum_intger[i]!=0)
                start = 1;
            if(start ==1)
            printf("%d",sum_intger[i]);
        }
        ave_length = sum_length;
        // 均分計算
        for(i=sum_length;i>=0;i--){
            if(sum_intger[i]/F>0){
                average[ave_length--] = sum_intger[i]/F;
                sum_intger[i] = sum_intger[i]%F;
                sum_intger[i-1] = sum_intger[i]*10 + sum_intger[i-1];
            }
            else{
                sum_intger[i-1] = sum_intger[i]*10 + sum_intger[i-1];
                sum_intger[i] = 0;
                //printf("i-1:%d\n",sum_intger[i-1]);
                ave_length--;
            }
        }
        // 輸出平均
        printf(": each friend should pay ");
        start = 0;
        for(i=sum_length;i>=0;i--){
            if(average[i]!=0)
                start = 1;
            if(start ==1)
                printf("%d",average[i]);
        }
        printf("\n\n");
    }
    return 0;
}
