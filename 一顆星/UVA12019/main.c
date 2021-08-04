#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA12019 20171016

*/

int main()
{   int n,i,j,months,days;
    int num_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    // 1 月 1 號%8為1 是星期六
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&months,&days);
        for(j=1;j<months;j++)
            days = days + num_days[j];
        if(days %7 == 1)
            printf("Saturday\n");
        if(days %7 == 2)
            printf("Sunday\n");
        if(days %7 == 3)
            printf("Monday\n");
        if(days %7 == 4)
            printf("Tuesday\n");
        if(days %7 == 5)
            printf("Wednesday\n");
        if(days %7 == 6)
            printf("Thursday\n");
        if(days %7 == 0)
            printf("Friday\n");

    }
    return 0;
}
