#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(~scanf("%d",&n)){
        int rd = 1;
        int count = 1;
        while(rd%n !=0){
            rd = (rd%n)*10 + 1;
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
