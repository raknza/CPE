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
        sum = 0; // stick�`����
        max = 0; // �̤jstick
        for(i=0;i<M;i++){
            scanf("%d",&stick[i]);
            sum += stick[i];
            // ��l��used���A
            stick_used[i] = 0;
            if(stick[i] > max)
                max = stick[i];
            // ���J�Ƨ�
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
        // ����p��
        side_length = sum/4;
        int ans = 0;
        // ���`�M�i/4 �B �̤j�� < �����
        if(sum%4==0 && max <= side_length){
            // �a�|
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
    // �զ�3�����
    if (side == 3){
        return 1;

    }
    else if(sum == side_length) // �ثe����׬�0�� �զ��@�ӷs����
        return dfs(side+1,0,0);
    else if(i == M ) // ���ޭȻݤp�����
        return 0;
    else{
        // �a�|stick�[�J
        // stick���ϥΥB sum�� >= stick��
        if(!stick_used[i] && sum + stick[i] <= side_length ){
            stick_used[i] = 1;
            // �a�|�᭱���t��
            if( dfs(side,i+1 ,sum + stick[i] ) )
                return 1;
            stick_used[i] = 0;
        }
        // �~��U�@��stick���հt��
        if(dfs(side,i +1 , sum) )
            return 1;
        return 0;
    }
}
