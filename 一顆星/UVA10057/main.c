#include <stdio.h>
#include <stdlib.h>


void Sort(int data[],int n){ // 選擇排序
    int min,temp,i,j;
    for(i=0;i<n;i++){
        min = data[i];
        for(j=i;j<n;j++){
            if(data[j]<min){ // 尋找最小值
                temp = min;
                min = data[j];
                data[j] = temp;
            }
        }
        data[i] = min; // 將當前數字最小者排至首位
    }
}


int main()
{
    int i,n,j;
    int input[10000]={};
    while(~scanf("%d",&n)){
        int count = 0;
        for(i=0;i<n;i++){
        scanf("%d",&input[count++]);
        }
        Sort(input,count);
        int repeat = 1;
        int repeat2 = 1;
        if(count%2==0){
            j = (count)/2+1;
            while(input[j]==input[j-1]){
                repeat++;
                j++;
            }
            j = (count-1)/2-1;
            while(j>=0 && input[j]==input[j+1]){
                repeat++;
                j--;
            }
            j = count/2;
            while(input[j]!=input[(count-1)/2]&&input[j]==input[j-1]){
                repeat2++;
                j++;
            }
            printf("%d %d %d\n",input[(count-1)/2],repeat+repeat2,input[count/2]-input[count/2-1]+1);
        }
        else{
            j = count/2+1;
            while(input[j]==input[j-1]){
                repeat++;
                j++;
            }
			j = (count-1)/2-1;
            while(j>=0 && input[j]==input[j+1]){
                repeat++;
                j--;
            }
            printf("%d %d %d\n",input[(count-1)/2],repeat,1);
        }

    }
    return 0;
}
