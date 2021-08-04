#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 UVA10038 20171016

*/
int main()
{   int i=0,j,num,n[3000] ={},d[2999]={};
    while(scanf("%d",&num)!=EOF){
        for(i =0;i<num;i++)
            scanf("%d",&n[i]);
        for(i=0;i<(num-1);i++){
            d[i] = n[i+1] - n[i];
            if(d[i]<0)
                d[i] = d[i]*(-1);
        }
        int current = 1;
        for(i=0;i<(num-1);i++){
            if(d[i] == current){
                current++;
                i = -1;
            }

        }
        if( current !=(num))
            printf("Not jolly\n");
        else
            printf("Jolly\n");

    }
    return 0;
}
