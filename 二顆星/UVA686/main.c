#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime[80000]={};
int primetable[80000]={};
int num = 0;
void Mprime();

int main()
{
    Mprime();
    while(1){
        int input;
        int ans = 0;
        int temp[40000]={};
        scanf("%d",&input);
        if(!input)
            break;
        int i,j;
        for(i=0;primetable[i]<=input/2;i++){
            if( prime[input - primetable[i]]  ){
                ans++;
                //temp[ input - primetable[i] ] = 1;
                //temp[primetable[i]] = 1;
            }
        }
        printf("%d\n",ans);
        for(i=0;i<40000;i++)
            temp[i] = 0;

    }
    return 0;
}

void Mprime(){
    int i,j;
    for(i=0;i<80000;i++){
        prime[i] = 1; // ��l�� �]�����
    }
    prime[0] = 0; // 0,1���P�w���D���
    prime[1] = 0;
	for(i = 2;i < sqrt(80000) ;i++){ // ��2�}�l�R�h�䭿�ƨ�Ӽƶ}�ڸ��]�ھڿz�k�^
		if(prime[i]){
			for(j = i*i; j < 80000; j+=i) // �qi*i�}�l�R �]��i*�]i-1) �e�w�Q�W�@���j�餺��i�R��
				prime[j] = 0; // �P�w���D���
		}
	}
    for(i=0;i<80000;i++){
        if(num < 80000 && prime[i]==1){
            primetable[num] = i;
            num++;
        }
    }
}
