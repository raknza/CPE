#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum;
    int cola;
    int empty_cola;
    while(~scanf("%d",&cola)){
        sum = 0;
        empty_cola = cola;
        sum = sum + cola;
        while(empty_cola >1){
            cola = empty_cola/3; // §I´«
            empty_cola = empty_cola%3 + cola;
            sum = sum + cola;
            if(empty_cola == 2)
                empty_cola++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
