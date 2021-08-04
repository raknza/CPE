#include <stdio.h>
#include <stdlib.h>

int recur(int n){
    if(n%10>0){
        return n%10;
    }
    else if(n==0)
        return 0;
    else
        return recur(n/10);
}

int main()
{
    long int i,j,n;
    long int sum;
    long int p,q;
    scanf("%ld %ld",&p,&q);
    while(p!=-1 || q!=-1){
        sum = 0;
        flag:
        if(q-p<10){
            for(;p<=q;p++)
                sum = sum + recur(p);
        }
        else{
            while(p%10!=0){
                sum = sum + recur(p);
                printf("p:%d\n",p);
                p++;
            }
            //printf("%P:%d\n",sum);
            while(q%10!=0){
                sum = sum + recur(q);
                printf("q:%d\n",q);
                q--;
            }
        //printf("%Q:%d\n\n",sum);
            sum = sum + ((q-p+1)/10)*45;
            p = p/10;
            q = q/10;
            if(!(p<=1 && q<=1))
                goto flag;
        }
        printf("%ld\n",sum);
        scanf("%ld %ld",&p,&q);
    }
    return 0;
}
