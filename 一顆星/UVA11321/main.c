#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M;
    while(1){
        scanf("%d %d",&N,&M);
        if(N== 0 && M == 0)
            break;
        int i,j;
        int num[10000]={};
        int ans[10000]={};
        for(i=0;i<N;i++){
            scanf("%d",&num[i]);
            ans[i] = num[i]%M;
            for(j=i;j>0;j--){
                if(ans[j] <  ans[j-1]){
                    int temp1 = ans[j-1];
                    int temp2 = num[j-1];
                    ans[j-1] = ans[j];
                    num[j-1] = num[j];
                    ans[j] = temp1;
                    num[j] = temp2;
                }
                else if( ans[j] == ans[j-1] ){
                    if(num[j]%2 != 0 && num[j-1]%2==0){
                        int temp1 = ans[j-1];
                        int temp2 = num[j-1];
                        ans[j-1] = ans[j];
                        num[j-1] = num[j];
                        ans[j] = temp1;
                        num[j] = temp2;
                    }
                    else if( num[j]%2 == 0 && num[j-1]%2 ==0 && num[j-1] > num[j] ){
                        int temp1 = ans[j-1];
                        int temp2 = num[j-1];
                        ans[j-1] = ans[j];
                        num[j-1] = num[j];
                        ans[j] = temp1;
                        num[j] = temp2;
                    }
                    else if( num[j]%2 != 0 && num[j-1]%2 != 0 && num[j-1] < num[j]){
                        int temp1 = ans[j-1];
                        int temp2 = num[j-1];
                        ans[j-1] = ans[j];
                        num[j-1] = num[j];
                        ans[j] = temp1;
                        num[j] = temp2;
                    }
                }
            }
        }
        printf("%d %d\n",N,M);
        for(i=0;i<N;i++)
            printf("%d\n",num[i]);
    }
    printf("0 0\n");
    return 0;
}
