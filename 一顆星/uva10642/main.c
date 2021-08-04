#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int count = 0;
        int nowx,nowy,endx,endy;
        int tempx,tempy;
        scanf("%d %d %d %d",&nowx,&nowy,&endx,&endy);
        tempx = nowy+nowx;
        tempy = 0;
        if(nowx==0&& nowy==0){
            nowy = 1;
            count++;
            tempx = 1;
        }
        while(nowx!=endx || nowy!=endy){
            //printf("%d %d\n",nowx,nowy);
            nowx++;
            nowy--;
            count++;
            if(tempx == nowx && tempy == nowy &&!(nowx==endx&&nowy==endy)){
                tempx++;
                nowx = 0;
                nowy = tempx;
                count++;
            }
        }
        printf("Case %d: %d\n",i+1,count);
    }
    return 0;
}
