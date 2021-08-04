#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE一顆星考題 - UVA11005 20171110 進位制 + 陣列

*/
int main()
{
    int n,con=0;
    scanf("%d",&n);
    while(con<n){
        int cost[36]={};
        int i,j;
        for(i=0;i<36;i++)
            scanf("%d",&cost[i]);
        int lines;
        int word;
        int count = 0;
        scanf("%d",&lines);
        // 輸入要計算的數字
        printf("Case %d:\n",++con);
        for(count=0;count<lines;count++){
            int total[37] = {};
            scanf("%d",&word);
            for(i=2;i<37;i++){
                int temp = word;
                // 轉換進制
                while(temp >0){
                    //printf("i:%d轉換中:%d\n",i,temp);
                    //new_word[length++] = temp%i;
                    total[i] = total[i] + cost[temp%i];
                    temp = temp/i;
                }
                //printf(" total[%d] = %d\n",i,total[i]);
            }
            // 各total比較
            int min = total[2];
            int min_num = 2;
            for(i=2;i<37;i++){
                if( total[i] < min){
                    min = total[i];
                    min_num = i;
                }
            }
            printf("Cheapest base(s) for number %d:",word);
            for(i=2;i<37;i++){
                if( total[i] == min )
                    printf(" %d",i);
            }
            printf("\n");

        }
        if(con != n)
            printf("\n");
    }
    return 0;
}
