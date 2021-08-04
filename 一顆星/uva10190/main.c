#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i;
    int stack[100];
    int top = -1;
    while(~scanf("%d %d",&m,&n)){
        top = -1;
        while(1){
            if(m%n!=0 || n == 1){
                printf("Boring!\n");
                break;
            }
            stack[++top] = m;
            m = m/n;
            if(m == 1){
                for(i=0;i<=top;i++){
                    printf("%d ",stack[i]);
                }
                printf("1\n");
                break;
            }
        }
    }
    return 0;
}
