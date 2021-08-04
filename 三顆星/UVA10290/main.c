#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10000000

long long int prime[SIZE];
long long int primeTable[SIZE];

void FindPrime(int );
int main()
{
    long long int i,n;
    FindPrime(500000);
    /*for(i=0;i<100;i++)
        printf("%d\n",primeTable[i]);*/
    while(~scanf("%lld",&n)){
        int count = 1;
        int sum = 1;
        int flag = 0;
        for(i=0;n!=1;i++){
            if( n%primeTable[i] == 0){
                //printf(" tab:%lld n:%lld n/tab:%lld \n",primeTable[i],n,n%primeTable[i]);
                sum++;
                n = n/primeTable[i];
                i--;
                flag = 1;
            }
            else if(flag == 1){
                //printf("t %d ",primeTable[i]);
                if(i!=0)
                    count = count*(sum);
                sum = 1;
                flag = 0;
                //printf("1dsf\n");
            }
        }
        //printf("sum:%d\n",sum);
        if(flag == 1 && i!=0)
            count = count*sum;
        printf("%d\n",count);
    }
    return 0;
}


void FindPrime(int n){
    int i,j,k=0,count =0;
    // �إ߽�ƪ� 1~10000000
    for(i=0;i<SIZE;i++)
        prime[i] = 1;
    prime[0] = 0; // 0,1���P�w���D���
    prime[1] = 0;
	for(i = 2;i < sqrt(SIZE) ;i++){ // ��2�}�l�R�h�䭿�ƨ�Ӽƶ}�ڸ��]�ھڿz�k�^
		if(prime[i]){
			for(j = i*i; j < SIZE; j+=i) // �qi*i�}�l�R �]��i*�]i-1) �e�w�Q�W�@���j�餺��i�R��
				prime[j] = 0; // �P�w���D���
		}
	}
	int length = 0;
	// �M���n�ӽ�� ����count = n �ɪ�^
    for(i=0;count<n;i++){
        if(prime[i]==1){
            count++;
            primeTable[length++] = i;
        }
    }
}
