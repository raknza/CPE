#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10000000

int prime[SIZE];
void FindPrime(int );

int main()
{
    FindPrime(500000);
    int a,b;
    while(~scanf("%d %d",&a,&b)){
        int i,sum=0;
        for(i=a;i<=b;i++){
            int temp = i*i + i +41;
            if(prime[temp])
                sum++;
        }
        printf("%.2lf\n",(double)sum/(b-a+1)*100);
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
	// 尋找第n個質數 滿足count = n 時返回
    for(i=0;count<n;i++){
        if(prime[i]==1){
            count++;
        }
    }
}
