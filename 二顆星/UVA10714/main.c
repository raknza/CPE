#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,num;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        int length,n,position;
        int max = -1;
        int min = -1;
        scanf("%d %d",&length,&n);
        for(j=0;j<n;j++){
            scanf("%d",&position);
            if(position - 0 > max)
                max = position-0;
            if(length - position > max)
                max = length - position;
            if(position - 0 > min && position < length-position)
                min = position-0;
            else if( length-position >min && length-position < position )
                min = length - position;
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}
