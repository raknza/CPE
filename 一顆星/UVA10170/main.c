#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA10170 20171020 等差級數總和

*/
int main()
{   long long int S,D,i=1;
    long long int sum;
    while(scanf("%lld %lld",&S,&D)!=EOF){
        i = S;
        sum = 0;
        while(1){
            sum = sum + (i);
            if(D<=sum){
                printf("%lld\n",i);
                break;
            }
            else
                i++;
        }
    }
    return 0;
}
