#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d",&num);
    while(num--){
        int side[4]={};
        int i;
        int max = 0;
        for(i=0;i<4;i++){
            scanf("%d",&side[i]);
            if(max < side[i])
                max = side[i];
        }
        if(side[0] == side[1] && side[1] == side[2] && side[2] == side[3])
            printf("square\n");
        else if( ( side[0] == side[1] && side[2] == side[3] )  ||  ( side[0] == side[2] && side[1] == side[3] ) || ( side[0] == side[3] && side[1] == side[2] )  )
            printf("rectangle\n");
        else if( (side[0]+side[1]+side[2]+side[3]-max) <= max )
            printf("banana\n");
        else
            printf("quadrangle\n");
    }
    return 0;
}
