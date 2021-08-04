#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,z) (z=x,x=y,y=z)
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    int train[51]={};
    for(i=0;i<n;i++){
        int length;
        int times = 0;

        scanf("%d",&length);
        for(j=0;j<length;j++){
            scanf("%d",&train[j]);
        }
        int temp;
        for(j=0;j<length;j++){
            for(k=j;k<length;k++){
                if(train[j]>train[k]){
                    swap(train[j],train[k],temp);
                    times++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",times);
    }
    return 0;
}
