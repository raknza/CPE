#include <stdio.h>
#include <stdlib.h>

int dfs(int[],int ,int ,int ,int);

int main()
{
    int num;
    int suit[20]={};
    scanf("%d",&num);
    getchar();
    while(num--){
        int max = 0;
        int sum = 0;
        int length = 0;
        char str[500]={};
        fgets(str, sizeof(str), stdin);
        int i;
        int temp = 0;
        for(i=0;str[i]!='\0';i++){
            if(str[i] <= '9' && str[i]>='0'){
                temp = temp*10 + str[i]-'0';
            }
            if(str[i] == ' ' || str[i+1] == '\0'){
                suit[length] = temp;
                //printf("%d ",temp);
                temp = 0;
                int i;
                if(max < suit[length])
                    max = suit[length];
                sum += suit[length];
                for(i=length;i-1>=0;i--){
                    if(suit[i] > suit[i-1]){
                        int temp = suit[i-1];
                        suit[i-1] = suit[i];
                        suit[i] = temp;
                    }
                }
                length++;
            }
        }
        if(max > sum/2 || sum%2!=0)
            printf("NO\n");
        else if(dfs(suit,length,0,0,sum/2))
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}


int dfs(int suit[],int length,int now,int weight,int aims){
    if(weight == aims)
        return 1;
    if(weight > aims)
        return 0;
    int i;
    for(i=now+1;i<length;i++){
        if(dfs(suit,length,i,weight+suit[i],aims))
            return 1;
    }
    return 0;
}
