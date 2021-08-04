#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int input;
    while(~scanf("%d",&input)){
        if(input == 0)
            break;
        int i,j;
        int sum = 0;
        for(i=1;i<input;i++){
            for(j=i+1;j<=input;j++){
            sum =sum + gcd(i,j);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}


int gcd(int m, int n) {
  m = abs(m);
  n = abs(n);
  if (m % n == 0) return n;
  else return gcd(n, m % n);
}
