#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA11063 20171027 數列邏輯判斷

*/
int main()
{
    int N,i,j,k,count=1,B2=1;
    int input[100];
    int pair_sums[50000]={};
    int num=0;
    while(scanf("%d",&N)!=EOF){
        for(i=0;i<N;i++)
            scanf("%d",&input[i]);
        for(i=1;i<N;i++){
        	for(j=i-1;j>=0;j--)
        		if(input[i]<=input[j])
        			B2 = 0;
        }

        int length = i;
        for(i=0;i<length;i++){
            for(j=i;j<length;j++)
                pair_sums[num++] = input[i] + input[j];
        }
        for(i=0;i<num-1;i++){
            for(j=i+1;j<num;j++){
                if(pair_sums[i] == pair_sums[j]){
                    B2 = 0;
                    break;
                }
            }
            if(B2 == 0)
                break;
        }

        if(B2==1)
            printf("Case #%d: It is a B2-Sequence.\n\n",count++);
        else
            printf("Case #%d: It is not a B2-Sequence.\n\n",count++);
        B2 = 1;
        num = 0;

    }
    return 0;
}
