#include <stdio.h>
#include <stdlib.h>
long int fnum[450000000]={};

int main()
{

    int start,end;
	int case_num = 1;

    while(scanf("%d %d",&start,&end)){
        if(start==0 && end == 0)
            break;
        long long int sum = 0;
        while(start <= end){
            int count = 0;
            int num = start;
            while(num!=0){
                if(start < 395000000 && fnum[start]){
                    sum += fnum[start];
                    break;
                }
                long  long int t = 2;
                while(t <= num)
                    t *= 2;
                if(num >= 2){
                    num -= (t/2);
                    sum++;
                    count++;
                }
                else{
                    num = 0;
                    sum++;
                    count++;
                }
            }
            /*if( start < 450000000 )
                fnum[start] = count;
            }
            else{
                sum += fnum[start];
            }*/
            if( start < 395000000 && !fnum[start] ){
                fnum[start] = count;
            }
            start++;
        }
        printf("Case %d: %lld\n",case_num++,sum);
    }
    return 0;
}
