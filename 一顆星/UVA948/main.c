#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA948 20171030 費氏數列

*/
int main()
{   int n,count=0,i;
    long long int fib[50];
    fib[0] = 0;
    fib[1] = 1;
    for(i=2;i<50;i++)
        fib[i] = fib[i-1] + fib[i-2];
    scanf("%d",&n);
    while(count++ < n){
        int f=0;
        scanf("%d",&f);
        printf("%d = ",f);
        int find = 0;
        int k = 0;
        for(i=49;i>=1;i--){
            if (f>=fib[i]){
                find = 1;
                k = 1;
                printf("%d",f/fib[i]);
                if(f!=0)
                    f = f%fib[i];
            }
            else
                find = 0;
            if(find == 0 && k==1 && i>=2)
                printf("0");
        }
        printf(" (fib)\n");
    }
    return 0;
}

