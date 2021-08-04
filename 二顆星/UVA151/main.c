#include <stdio.h>
#include <stdlib.h>



int main()
{
    int i,j,k,N;
    int light[101]={};
    while(1){
        for(i=0;i<101;i++)
            light[i] = 0;
        scanf("%d",&N);
        if(N==0)
            break;
        int m = 1;
        int now = 1;
        int num = 0;
        light[now] = 1;
        while(1){
            now = now+1;
            if(now>N)
                now = now%N;
            if(light[now] == 0)
                num++;
            if(num == m){
                num = 0;
                light[now] = 1;
                //printf("%d\n",now);
                for(i=1;i<=N;i++){
                    if(!light[i])
                        break;
                }
                if(i>N && now == 13){
                    break;
                }
                else if(i>N){
                    for(i=1;i<=N;i++)
                        light[i] = 0;
                    now = 1;
                    light[now] = 1;
                    m++;
                }

            }
        }
        printf("%d\n",m);

    }

    return 0;
}
