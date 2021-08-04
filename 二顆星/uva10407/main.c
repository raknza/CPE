#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[100];
    int remainder[100];
    int i,j;
    while(1){
        for(i=0;i<100;i++){
            scanf("%d",&num[i]);
            if(num[i] == 0)
            break;
        }
        if(i == 0)
            break;
        int k;
        int flag = 0;
        int max_d = 1;
        int d = 1;
        while(flag == 0){
            int flag2 = 0;
            for(j=0;j<i;j++){
                if(d > num[j] && num[j]>0){
                    flag = 1;
                    flag2 = 1;
                    break;
                }
                remainder[j] = num[j]%d;
                if(remainder[j] < 0 && num[j] < 0)
                    remainder[j] = remainder[j]+d;
                if(j>0 && remainder[j]!=remainder[j-1]){
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0 )
                max_d = d;
            d++;
        }
        printf("%d\n",max_d);
    }
    return 0;
}
