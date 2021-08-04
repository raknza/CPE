#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

CPE一顆星考題 - UVA10056 20171019 遊戲勝率計算 無窮等比級數

*/
int main()
{
    int sets,N,num,i,j;
    double p,probability = 1.0;
    scanf("%d",&sets);
    for(i=0;i<sets;i++){
        scanf("%d %lf %d",&N,&p,&num);
        if(p < 0.00001)
            printf("0.0000\n");
        else{
        	probability = pow((1-p),(double)num-1)*p/(1-(pow((1-p),(double)N)));
            printf("%.4lf\n",probability);
        }
    }
    return 0;
}
