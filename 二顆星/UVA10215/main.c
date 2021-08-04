#include <stdio.h>
#include <stdlib.h>

int floatcomp(double ,double );
int floatcomp2(double ,double );

int main()
{
    double width,length;
    while(~scanf("%lf %lf",&width,&length)){
        double x = 0.000001;
        double volume;
        int i = 0;
        double max_num,max = 0.0;
        double min_num,min = 999999.0;
        while( (width-2*x)>=0 && (length-2*x)>=0){
            volume = (width-2*x)*(length-2*x)*x;
            if(floatcomp2(volume,max)){
                //printf("%.3f\n",volume);
                max = volume;
                max_num = x;
            }
            if( ( floatcomp(width-2*x,0) || floatcomp(length-2*x,0) )){
                min = 0.0;
                min_num = x;
            }
            else if(floatcomp2(min,volume)){
                min = volume;
                min_num = x;
            }
            x = x + 0.0001;
        }
        printf("%.3lf %.3lf %.3lf\n",max_num,min,min_num);
    }
    return 0;
}

int floatcomp(double a,double b){
    if(a - b <=0.00000001 || b-a <= 0.00000001)
        return 1;
    else
        return 0;
}

int floatcomp2(double a,double b){
    if( a-b >= 0.0000001)
        return 1;
    else
        return 0;
}
