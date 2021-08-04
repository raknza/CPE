#include <stdio.h>
#include <stdlib.h>

int main()
{
    int case_num;
    scanf("%d",&case_num);
    while(case_num--){
        int N;
        scanf("%d",&N);
        int start = 2;
        int sum = 1;
        while(start < N){
            if(N%start==0){
                sum += start;
            }
            start++;
        }
        if(sum == N)
            printf("perfect\n");
        else if(sum > N)
            printf("abundant\n");
        else
            printf("deficient\n");
    }
    return 0;
}
