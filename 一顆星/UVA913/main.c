#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    while(~scanf("%d",&num)){
        long long int n = 0;
        long long int start = 1;
        long long int ans = 0;
        long long int i,j;
        for(i=1;i<num;i+=2){
            n += i;
        }
        start = n*2+1;
        start = (num-3)*2 + start;
        for(i=0;i<3;i++){
            ans += start;
            start += 2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
