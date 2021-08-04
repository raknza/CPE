#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int num;
    long long int i,j;
    while(scanf("%lld",&num) && num!=0){
        long long int N;
        long long int M;
        long long int temp = num*10/9;
        if(num*10%9 == 0){
            printf("%lld %lld",temp-1,temp);
        }
        else
            printf("%lld",temp);
        printf("\n");

    }
    return 0;
}
