#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE二顆星考題 - UVA10106 20171019 大數乘法

*/
int main()
{
    char intgerbig[2][252]={};
    int i=0,j,k;
    while(gets(intgerbig[i])){
        if(i==1){
            int length1 = strlen(intgerbig[0]);
            int length2 = strlen(intgerbig[1]);
            int e=0;
            for(j=0;j<length1;j++)
                intgerbig[0][j] = intgerbig[0][j] -'0';
            for(j=0;j<length2;j++)
                intgerbig[1][j] = intgerbig[1][j] -'0';
            // 有某數為0時直接輸出0
            if(intgerbig[0][0] == 0 ||intgerbig[1][0] ==0){
            	printf("0\n");
                i = 0;
                continue;
            }

            //
            int current = 0;
            int new_length = 0;
            int new_string[252]={};
            for(j=length2-1;j>=0;j--){
                current = new_length++;
                for(k=length1-1;k>=0;k--){
                    new_string[current] = new_string[current] + intgerbig[1][j] * intgerbig[0][k];
                    current++;
                }
            }
            new_length = current + 2;
            for(j=0;j<new_length;j++){
                if(e>0){
                    new_string[j] = new_string[j] + e;
                    e = 0;
                }
                if(new_string[j]>9){
                    e = new_string[j]/10;
                    new_string[j] = new_string[j]%10;
                }
            }
            int start  = 0;
            for(j=new_length-1;j>=0;j--){
                if(new_string[j]!=0)
                    start = 1;
                if(start==1)
                    printf("%d",new_string[j]);
                new_string[j] = 0;
            }
            printf("\n");
        }
        i++;
        if (i==2)
            i = 0;
    }
    return 0;
}
