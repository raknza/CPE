#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pow(int a,int b){
    int i,j;
    j = a;
    for(i=1;i<b;i++){
        a = a*j;
        if(a>=10)
            a = a%10;
    }
    return a;
}

int main()
{
    int ans[101]={},i,j;
    for(i=1;i<101;i++){
        for(j=1;j<=i;j++){
            ans[i] = ans[i] + pow(j,j);
        }
        while(ans[i]>=10)
            ans[i] = ans[i]%10;
        //printf("%d \n",ans[i]);
    }

    char number[101];
    while(scanf("%s",&number)){
        if(!strcmp(number,"0"))
            break;
        int length = strlen(number);
        if(length>1)
            printf("%d\n",ans[10*(number[length-2]-'0')+(number[length-1]-'0')]);
        else
            printf("%d\n",ans[number[length-1]-'0']);


    }
    return 0;
}
