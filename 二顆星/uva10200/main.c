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
	// �M���n�ӽ�� ����count = n �ɪ�^
    for(i=0;count<n;i++){
        if(prime[i]==1){
            count++;
        }
    }
}
