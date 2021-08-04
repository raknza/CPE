#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10000000

int prime[SIZE];
int primeTable[SIZE];
void FindPrime(int );
int main()
{
    FindPrime(10000);
    int i,j,n;
    int factor[1000]={};
    int count;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        count = -1;
        int input;
        scanf("%d",&input);
        if(input<10)
            printf("%d\n",input);
        else{
            j = 0;
            int flag = 0;
            while(input > 1){
                if(!(input%primeTable[j])){
                    factor[++count] = primeTable[j];
                    input = input/primeTable[j];
                    if(primeTable[j]>10){
                        flag = 1;
                        break;
                    }
                }
                else
                    j++;
            }
            if(flag == 0){
                for(j=0;j<=count;j++)
                    printf("%d",factor[j]);
                printf("\n");
            }
            else
                printf("-1\n");
        }
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
            primeTable[count++] = i;
        }
    }
}


