#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N,i,j;
    scanf("%d",&N);
    int num;
    for(i=0;i<N;i++){
        int b1 = 0;
        int b2 = 0;
        scanf("%d",&num);
        int temp = num;
        while(temp>=2){
            b1 = b1 + temp%2;
            temp = temp/2;
        }
        b1 = b1 + temp;
        temp = 0 ;
        int a=0;
        for(j=3;j>=1;j--){
            if(j==2)
                a = 1;
            else
                a = 0;
            temp = temp + (num/(int)(a + pow(10,j))) * (int)pow(16,j);
            num = num%(int)(a + (pow(10,j)));
            if(j==1)
                temp = temp + num;
        }
        while(temp>=2){
            b2 = b2 + temp%2;
            temp = temp/2;
        }
        b2 = b2 + temp;
        printf("%d %d\n",b1,b2);
    }
    return 0;
}
