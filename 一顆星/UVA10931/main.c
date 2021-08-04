#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA10931 20171110 進位制

*/
int main()
{
    int n;
    while(~scanf("%d",&n)){
        if(n == 0)
            break;
        int sum = 0;
        int length = 0;
        int temp[1000];
        printf("The parity of ");
        while(n>0){
            sum = n%2 + sum;
            temp[length++] = n%2;
            n = n/2;
        }
        while(length>0)
            printf("%d",temp[--length]);
        printf(" is ");
        printf("%d (mod 2).\n",sum);
    }
    return 0;
}
