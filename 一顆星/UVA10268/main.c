#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

CPE�@���P���D - UVA10268 20171020 �h�����L���D��ƭ�

*/

int a[10000000];

int main()
{
    int x,i=0;
   	double sum = 0;
    while(scanf("%d",&x)!=EOF){
        while(scanf("%d",&a[i])!=EOF){
            i++;
			if(getchar()=='\n')
        		break;
        }
        int length = i-1;
        for(i=0;i<=length;i++){
            sum = sum + a[i]*(length-i)*pow(x,length-i-1);
        }
        printf("%.0lf\n",sum);
        sum = 0;
        i = 0;
    }
    return 0;
}
