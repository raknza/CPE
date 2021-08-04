#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10000000

int prime[SIZE];
int primeTable[SIZE];

void FindPrime(int );

int main()
{
    FindPrime(500000);
    int a,b;
    /*int k;
    for(k=0;k<100;k++)
        printf("%d\n",primeTable[k]);*/
    while(~scanf("%d %d",&a,&b)){
        int i=0;
        int minset[2]={};
        int maxset[2]={};
        int min = 999999999;
        int max = 0;
        while(primeTable[i] < a)
            i++;
        for(i=i;primeTable[i+1]<=b;i++){
            if( primeTable[i+1] - primeTable[i] < min){
                minset[0] = primeTable[i];
                minset[1] = primeTable[i+1];
                min = primeTable[i+1] - primeTable[i];
            }
            if( primeTable[i+1] - primeTable[i] > max ){
                maxset[0] = primeTable[i];
                maxset[1] = primeTable[i+1];
                max = primeTable[i+1] - primeTable[i];
            }
        }
        if( minset[0] && minset[1] )
            printf("%d,%d are closest, %d,%d are most distant\n",minset[0],minset[1],maxset[0],maxset[1]);
        else
            printf("There are no adjacent primes.\n");
    }
    return 0;
}


void FindPrime(int n){
    int i,j,k=0,count =0;
    // 建立質數表 1~10000000
    for(i=0;i<SIZE;i++)
        prime[i] = 1;
    prime[0] = 0; // 0,1先判定為非質數
    prime[1] = 0;
	for(i = 2;i < sqrt(SIZE) ;i++){ // 由2開始刪去其倍數到該數開根號（根據篩法）
		if(prime[i]){
			for(j = i*i; j < SIZE; j+=i) // 從i*i開始刪 因為i*（i-1) 前已被上一次迴圈內的i刪除
				prime[j] = 0; // 判定為非質數
		}
	}
	int length = 0;
	// 尋找第n個質數 滿足count = n 時返回
    for(i=0;count<n;i++){
        if(prime[i]==1){
            count++;
            primeTable[length++] = i;
        }
    }
}
