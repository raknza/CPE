#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int );

int main()
{
    int num;
    while(scanf("%d",&num) && num!=0){
        int next = num;
        int pre = num;
        while(prime(next)!=1){

            next++;
        }
        while(pre > 1 && !prime(pre) ){
            pre--;
        }
        if(pre == 1)
            printf("0");
        else
            printf("%d",next-pre);
        printf("\n");
    }
    return 0;
}


int prime(int num){
    if(num == 1)
        return 0;
    if(num == 2)
        return 1;
    int i;
    int j;
    int k = sqrt(num);
    for(i=2;i<=k;i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}
