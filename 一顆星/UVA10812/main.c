#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA10812 20171023 方程式

*/
int main()
{
    int n,a,b,z,i;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            z = (a + b)/2;
            if(z<0 || (a-z)<0 || (a+b)%2!=0)
                printf("impossible\n");
            else
                printf("%d %d\n",z,a-z);
        }
    }
    return 0;
}
