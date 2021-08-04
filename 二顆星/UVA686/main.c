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
        prime[i] = 1; // 初始化 設為質數
    }
    prime[0] = 0; // 0,1先判定為非質數
    prime[1] = 0;
	for(i = 2;i < sqrt(80000) ;i++){ // 由2開始刪去其倍數到該數開根號（根據篩法）
		if(prime[i]){
			for(j = i*i; j < 80000; j+=i) // 從i*i開始刪 因為i*（i-1) 前已被上一次迴圈內的i刪除
				prime[j] = 0; // 判定為非質數
		}
	}
    for(i=0;i<80000;i++){
        if(num < 80000 && prime[i]==1){
            primetable[num] = i;
            num++;
        }
    }
}
