#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i,j;
    while(~scanf("%d",&num)){
        int flag = 0;
        for(i=2;i<num&&flag == 0;i++){
            if(num%i == 0){
                printf("%d is not prime.\n",num);
                flag = 1;
                break;
            }
        }
        if(flag == 0&& num<10){
            printf("%d is prime.\n",num);
            flag = 1;
        }
        int num2 = 0;
        int temp = num;
        if(flag == 0){
            while(temp%10 != 0 || temp/10 >0){
                num2 = num2*10 + temp%10;
                temp = temp/10;
            }
            for(i=2;i<num2;i++){
                if(num2%i == 0 || num2 == num){
                    printf("%d is prime.\n",num);
                    break;
                }
            }
            if(i == num2)
                printf("%d is emirp.\n",num);
        }
    }
    return 0;
}
