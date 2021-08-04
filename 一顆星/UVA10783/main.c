#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA10783 20171023 等差級數

*/
int main()
{   int n,i,j,a,b,sum,count=1;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            sum = 0;
            scanf("%d %d",&a,&b);
            if(a%2==0)
                a++;
            if(b%2==0)
                b--;
            for(j=a;j<=b;j+=2)
                sum = sum + j;
            printf("Case %d:%d\n",count,sum);
            count++;
        }

    }
    return 0;
}
