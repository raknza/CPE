#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA10019 20171030 進位制

*/
int main(){
	int n,i;
	int num;
	int b1,b2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		b1 = 0;
		b2 = 0;
		scanf("%d",&num);
		int temp = num;
		while(num>0){
			if(num%2 == 1)
				b1++;
			num = num/2;
		}
		int j = 1000;
		int c;
		while(temp>0){
			c = temp/j;
			while(c>0){
					if(c%2 == 1)
						b2++;
					c = c/2;
			}
			temp = temp%j;
			j = j/10;
		}
		printf("%d %d\n",b1,b2);
	}
}
