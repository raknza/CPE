#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R;
    int vol[10001]={};
    while(~scanf("%d %d",&N,&R)){
        int i,count;
        count = 0;
        for(i=0;i<R;i++){
            int vol_return;
            scanf("%d",&vol_return);
            vol[vol_return] = 1;
        }
        for(i=1;i<=N;i++){
            if(!vol[i]){
                printf("%d ",i);
                count++;
            }
        }
        if(count == 0 )
            printf("*");
        printf("\n");
        count = 0;
        for(i=1;i<10001;i++)
            vol[i] = 0;
    }
    return 0;
}
