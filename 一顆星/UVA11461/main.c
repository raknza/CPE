#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

CPE一顆星考題 - UVA11461 20171027 找完全平方數

*/
int main()
{
    int a,b,i,j,num,count=0;
    int square_root[10000];
    for(i=0;i<sqrt(100000);i++)
        square_root[i] = (i+1)*(i+1);
    while(scanf("%d %d",&a,&b)!=EOF && count<202){
        if (a==b && b==0)
            break;
        num = 0;
        for(i=a;i<=b;i++){
            j = 0;
            while(square_root[j] <= i){
                if(square_root[j] == i)
                    num++;
                j++;
            }

        }
        printf("%d\n",num);
        count++;
    }
    return 0;
}
