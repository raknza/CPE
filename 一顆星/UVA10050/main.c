#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T>0){
        int days;
        int day[8] = {0,0,0,0,0,0,0,0};
        scanf("%d",&days);
        int nums;
        scanf("%d",&nums);
        for(i=0;i<nums;i++){
            int temp;
            scanf("%d",&temp);
            switch (temp%7){
                case 1:
                    day[1] = 1;
                    break;
                case 2:
                    day[2] = 1;
                    break;
                case 3:
                    day[3] = 1;
                    break;
                case 4:
                    day[4] = 1;
                    break;
                case 5:
                    day[5] = 1;
                    break;
                case 6:
                    day[6] = 1;
                    break;
                case 0:
                    day[7] = 1;
            }

        }
        int sum = 0;
        int start = 1;
        for(i=0;i<days;i++){
            if(day[start++] == 1)
                sum++;
            if(start >7)
                start = start - 7;
        }
        printf("%d\n",sum);
    }
    return 0;
}
