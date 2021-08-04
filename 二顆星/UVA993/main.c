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
            primeTable[count++] = i;
        }
    }
}


