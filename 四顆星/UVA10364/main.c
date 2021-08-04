#include <stdio.h>
#include <stdlib.h>

int stick[25] ={};
int stick_used[25]={};
int side_length;
int M;
int dfs(int side,int i,int sum);

int main()
{
    int N;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&M);
        int i,j,sum,max;
        sum = 0; // stick總長度
        max = 0; // 最大stick
        for(i=0;i<M;i++){
            scanf("%d",&stick[i]);
            sum += stick[i];
            // 初始化used狀態
            stick_used[i] = 0;
            if(stick[i] > max)
                max = stick[i];
            // 插入排序
            int j=i;
            int k = j-1;
            for(j=i;k>=0;j--){
                if(stick[j] > stick[k]){
                    int temp = stick[k];
                    stick[k] = stick[j];
                    stick[j] = temp;
                }
                k--;
            }
        }
        // 邊長計算
        side_length = sum/4;
        int ans = 0;
        // 邊總和可/4 且 最大邊 < 邊長度
        if(sum%4==0 && max <= side_length){
            // 窮舉
            ans = dfs(0,0,0);
        }
        if(ans)
            printf("yes\n");
        else
            printf("no\n");

    }
    return 0;
}

int dfs(int side,int i,int sum){
    // 組成3個邊時
    if (side == 3){
        return 1;

    }
    else if(sum == side_length) // 目前邊長度為0時 組成一個新的邊
        return dfs(side+1,0,0);
    else if(i == M ) // 索引值需小於長度
        return 0;
    else{
        // 窮舉stick加入
        // stick未使用且 sum值 >= stick值
        if(!stick_used[i] && sum + stick[i] <= side_length ){
            stick_used[i] = 1;
            // 窮舉後面的配對
            if( dfs(side,i+1 ,sum + stick[i] ) )
                return 1;
            stick_used[i] = 0;
        }
        // 繼續下一個stick嘗試配對
        if(dfs(side,i +1 , sum) )
            return 1;
        return 0;
    }
}
