#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE�����P�D�� UVA10298  20171004
��Ѥ@�r�� ���Ѧ�a^n  �D���Ƥ���

*/

int main()
{   char input[1000001];
    int i,j,k,count=0,n=1,max_n=1,wrong=0,temp=0;
    while(scanf("%s",input)!=EOF){
   		if(input[0]=='.')
   			break;
        int length = strlen(input);
        // i ���@���ˬd�X��
        for(i=1;i<=(length);i++){
            for(j=0;j<i;j++){ // j���_�l�ˬd��m
                //printf("i=%d �ˬd�G%d\n",i,j);
                count =1;
                //printf("(length-i+j):%d\n",(length-i+j));
                for(k=j;k<(length-i+j);k=k+i){
                    //printf("K:%d count:%d n:%d    %c %c\n",k,count,n,input[k],input[k+i]);
                    if(input[k+i]!=input[k]){
                        wrong = 1;
                        break;
                    }
                    else
                        count++;
                    if(j==i-1)
                        n = count;
                }
                if(n>max_n && k==(length-i+j) && wrong ==0)
                    max_n = n;
                n = 1;
                if(wrong==1){
                    wrong = 0;
                    //printf("break\n");
                    break;
                }
            }
        }
        printf("%d\n",max_n);
        max_n = 1;
    }
    return 0;
}
