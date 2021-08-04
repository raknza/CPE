#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   char R[100];
    char code[63]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I'
    ,'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i'
    ,'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int sum=0,i,j,k,digit,temp;
    while(~scanf("%s",R)){
        int length = strlen(R);
        digit  = 2;
        for(i=0;i<length;i++){
            for(j=0;j<62;j++){
                if(R[i] == code[j]){
                    temp = j+1;
                    sum = sum + j;
                }
            }
            if(temp > digit)
                digit = temp;
        }
        for(i=digit;i<=62;i++){
            if( sum % (i-1) == 0)
                break;
        }
        if(i == 63)
            printf("such number is impossible!\n");
        else
            printf("%d\n",i);
        sum = 0;
    }
    return 0;
}
