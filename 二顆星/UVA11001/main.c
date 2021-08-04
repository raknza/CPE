#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int equal(double,double);

int main()
{
    int Vt,V0;
    while( ~scanf("%d %d",&Vt,&V0) ){
        if(Vt == 0 && Vt == V0)
            break;
        int i=1;
        int num = 0;
        double disc_length=0;
        double V = Vt/i;
        while(V > V0){
            if( equal(disc_length,(double)sqrt(V-V0)*0.3*i) ){
                num = 0;
                break;
            }
            if( (double)sqrt(V-V0)*0.3*i > disc_length){
                disc_length = (double)sqrt(V-V0)*0.3*i;
                num = i;
            }
            V = (double)Vt/++i;
        }
        printf("%d\n",num);
        disc_length =0.0;
        i = 1;
        num = 0;
    }
    return 0;
}


int equal(double a,double b){
    if((a - b) < 0.0001 && a-b>0)
        return 1;
    else if((b - a) <0.0001 && b-a>0)
        return 1;
    else
        return 0;
}
