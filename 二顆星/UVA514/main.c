#include <stdio.h>
#include <stdlib.h>

int target[1000]={};
int stack[3][1000]={};
int top[3] = {-1,-1,-1};

int sol(int N);

void push(int index,int value);
int pop(int index);

int main()
{
    while(1){
        int N,i,j;
        scanf("%d",&N);
        if(!N)
            break;
        while(1){
            scanf("%d",&target[0]);
            if(target[0] == 0){
                printf("\n");
                break;
            }
            for(i=1;i<N;i++)
                scanf("%d",&target[i]);
            for(i=N;i>0;i--)
                push(0,i);
            int ans = sol(N);
            if(ans)
                printf("Yes\n");
            else
                printf("No\n");
            while(pop(0));
            while(pop(1));
        }
    }
    return 0;
}

int sol(int N){
    int i;
    for(i=0;i<N;i++){
        while(1){
            if( top[1]!=-1 && stack[1][top[1]] == target[i] ){
                pop(1);
                //printf("1:%d",target[i]);
                break;
            }
            else if( top[0]!=-1 && stack[0][top[0]]== target[i]  ){
                pop(0);
                //printf("0:%d",target[i]);
                break;
            }
            else{
                if(top[0]== -1)
                    return 0;
                push(1,stack[0][top[0]]);
                pop(0);
            }

        }
    }
    return 1;
}


void push(int index,int value){
    top[index]++;
    stack[index][top[index]] = value;
}

int pop(int index){
    if(top[index]!=-1){
        return stack[index][top[index]--];
    }
    return 0;
}
