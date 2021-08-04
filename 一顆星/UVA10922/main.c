#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[10000];
    while(1){
        scanf("%s",&input);
        if(!strcmp("0",input))
            break;

        int i;
        int length = strlen(input);
        int sum = 0;
        int degree = 0;
        for(i=0;i<length;i++)
            sum = sum + input[i]-'0';
        if(sum%9 == 0){
            degree++;
            int temp;
            while(sum>9){
                temp = 0;
                while(sum > 0){
                    temp = temp + sum%10;
                    sum = sum/10;
                }
                //printf("%d\n",temp);
                if(temp%9 == 0){
                    degree++;
                    sum = temp;
                }
                else
                    break;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n",input,degree);
        }
        else
            printf("%s is not a multiple of 9.\n",input);
    }
    return 0;
}
