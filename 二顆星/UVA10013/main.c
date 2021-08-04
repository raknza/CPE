#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE二顆星考題 - UVA10013 20171018

*/
void safe_flush(FILE *fp)  {
    int ch;
    while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}
int main()
{
    int i,j,N,M;
    char intgerA[1001]={},intgerB[1001]={}; // A是左邊 B是右邊
    while(scanf("%d",&N)!=EOF){
        // N筆資料
        for(i=0;i<N;i++){
            scanf("%d",&M); // M位數
            safe_flush(stdin);
            char temp[M][5];
            for(j=0;j<M;j++){
                gets(temp[j]);
            }
            for(j=0;j<M;j++){
                intgerA[j] = temp[j][0] - '0';
                intgerB[j] = temp[j][2] - '0';
            }
            int e = 0;
            for(j=(M-1);j>=0;j--){
                if (e == 1)
                    intgerA[j]++;
                e = 0;
                intgerA[j] = intgerB[j] + intgerA[j];
                if (intgerA[j] >=10){
                    intgerA[j] = intgerA[j] - 10;
                    e++;
                }
                intgerA[j] = intgerA[j] + '0';
            }
            if(e == 1){
                for(j=(M-1);j>=0;j--)
                    intgerA[j+1] = intgerA[j];
                intgerA[0] = '1';
            }
            printf("%s\n",intgerA);
            for(j=0;j<=M;j++){
                intgerA[j] = '\0';
                intgerB[j] = '\0';
            }
            if(i<N-1)
            	printf("\n");

        }
    }
    return 0;
}
