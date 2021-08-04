#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count,i,j;
    int num[10000];
    scanf("%d",&count);
    for(i=0;i<count;i++){
        int numbers;
        int K;
        scanf("%d %d",&numbers,K);
        for(j=0;j<numbers;j++)
            scanf("%d",&num[j]);

    }
    return 0;
}
