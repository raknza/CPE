#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;
    float cost[1000]={};
    while(~scanf("%d",&n)){
    	if(n == 0)
    		break;
        float average = 0.0;
        float d = 0.0,d2 = 0.0;
        for(i=0;i<n;i++){
            scanf("%f",&cost[i]);
            average = average + cost[i];
        }
        average = ((float)(int)(average*100/n+0.5))/100;
        for(i=i;i>=0;i--){
            if(cost[i]>=average){
                d = d + cost[i] - average;
            }
            else{
                d2 = d2 + average - cost[i];
            }
        }
        if(d < d2)
            printf("$%.2f\n",d);
        else
            printf("$%.2f\n",d2);

    }
    return 0;
}
