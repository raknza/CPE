#include <stdio.h>
#include <stdlib.h>

int main()
{
    int case_num = 0;
    scanf("%d",&case_num);
    while(case_num--){
       // char c = getchar();
        int p,count;
        scanf("%d %d",&p,&count);
        int i,j;
        for(i=0;i<count;i++){
            // 1,22,333
            int time = 0;
            for(j=1;j<p+1;){
                printf("%d",j);
                time++;
                if(time == j){
                    j++;
                    time = 0;
                    printf("\n");
                }
            }
            // 22,1
            for(j=p-1;j>=1;){
                printf("%d",j);
                time++;
                if(time == j){
                    j--;
                    time = 0;
                    if( !(i-1==count && j==0)  )
                        printf("\n");
                }
            }
            if( !(i == count-1) ){
            	printf("\n");
            }
        }
    }
    return 0;
}
