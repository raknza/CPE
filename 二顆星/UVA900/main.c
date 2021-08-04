#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n,i;
    long long int f[51]={};
    f[1] = 1;
    f[2] = 2;
    for(i=3;i<51;i++)
        f[i] = f[i-1]+f[i-2];
    scanf("%d",&n);
    while(n!=0){
        printf("%lld\n",f[n]);
        scanf("%lld",&n);
    }


    return 0;
}
