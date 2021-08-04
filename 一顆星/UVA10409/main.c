#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,k,n;
    char command[10];
    while(1){
        int top = 1;
        int bottom = 6;
        int front = 2;
        int right = 4;
        int left = 3;
        int back = 5;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++){
            int temp1,temp2,temp3,temp4;
            scanf("%s",&command);
            if(!strcmp(command,"north")){ // 向前轉
                temp1 = top;
                temp2 = front;
                temp3 = back;
                temp4 = bottom;
                top = back;
                back = bottom;
                front = temp1;
                bottom = temp2;
            }
            else if(!strcmp(command,"south")){ // 向後轉
                temp1 = top;
                temp2 = front;
                temp3 = back;
                temp4 = bottom;
                top = front;
                back = temp1;
                bottom = temp3;
                front = temp4;
            }
            else if(!strcmp(command,"east")){ // 向右轉
                temp1 = top;
                temp2 = left;
                temp3 = right;
                temp4 = bottom;
                top = left;
                right = temp1;
                bottom = temp3;
                left = temp4;

            }
            else if(!strcmp(command,"west")){ // 向左轉
                temp1 = top;
                temp2 = left;
                temp3 = right;
                temp4 = bottom;
                top = right;
                left = temp1;
                bottom = temp2;
                right = temp4;
            }
        }
        printf("%d\n",top);
    }

    return 0;
}
