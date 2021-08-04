#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20000000

long long int prime[SIZE];
long long int primeTable[SIZE];
void FindPrime(long long int );

int main(){

    FindPrime(100000);
    //printf("%lld\n",primeTable[999999]);
    int i,n;
    /*for(i=0;i<200;i++)
        printf("%d\n",primeTable[i]);*/
    scanf("%d",&n);
    for(i=0;i<n;i++){
        long int count = -1;
        long int factor[1000]={};
        long int input;
        long int j;
        long int sum1;
        long int sum2;
        long int temp;
        long int temp2;
        scanf("%ld",&input);
        input++;
        while(1){
        sum1 = 0;
        sum2 = 0;
        temp = input;
        while(temp > 0){
            sum1 = sum1 + temp%10;
            temp = temp/10;
        }
        temp = input;
        //printf("%ld\n",input);
        while(temp > 0){
            long int a = 0;
            for(j=0;primeTable[j]<=temp&&j<100000;j++){
                if( temp == primeTable[j] || j== 99999){
                    factor[++count] = temp;
                    a = 1;
                    break;
                }
                else if(temp%primeTable[j] == 0){
                    factor[++count] = primeTable[j];
                    temp = temp/primeTable[j--];
                }
            }
            if(a==1)
                break;
        }
        if(temp == input){
            factor[++count] = 1;
        }

        /*for(j=0;j<=count;j++){
            printf("%d *",factor[j]);
        }
        printf("\n");*/
        for(j=0;j<=count;j++){
            if(factor[j] < 10)
                sum2 = sum2 + factor[j];
            else{
                while(factor[j]>0){
                    sum2 = sum2 + factor[j]%10;
                    factor[j] = factor[j]/10;
                }
            }
        }
        if(sum1 == sum2){
            printf("%ld\n",input);
            break;
        }
        else{
            input = input + 1;
            count = -1;

        }
        }

    }
    return 0;
}


void FindPrime(long long int n){
    long long int i,j,k=0,count =0;
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
