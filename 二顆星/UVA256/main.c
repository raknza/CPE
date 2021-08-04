#include <stdio.h>
#include <stdlib.h>
/*

CPE二顆星考題 - UVA256 20171101

*/
int main()
{
    int i=1,n,sum[10000]={};
    int length=0;
    for(i=0;i<10000 && i*i<=19998*19998;i++)
        sum[length++] = i*i;
    for(i=0;i<10;i++){
    }
    while(~scanf("%d",&n)){
        i = 0;
        if(n==2){
            for(i=0;sum[i]<100;i++){
                if( (sum[i]/10 + sum[i]%10)*(sum[i]/10 + sum[i]%10) == sum[i])
                    printf("%02d\n",sum[i]);
            }
        }
        else if(n==4){
            for(i=0;sum[i]<10000;i++){
                if( (sum[i]/100 + sum[i]%100)*(sum[i]/100 + sum[i]%100) == sum[i])
                    printf("%04d\n",sum[i]);
            }
        }
        else if(n==6){
            for(i=0;sum[i]<1000000;i++){
                if( (sum[i]/1000 + sum[i]%1000)*(sum[i]/1000 + sum[i]%1000) == sum[i])
                    printf("%06d\n",sum[i]);
            }
        }
        else if(n==8){
            for(i=0;sum[i]<100000000;i++){
                if( (sum[i]/10000 + sum[i]%10000)*(sum[i]/10000 + sum[i]%10000) == sum[i])
                    printf("%08d\n",sum[i]);
            }
        }
    }
    return 0;
}
