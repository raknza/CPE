#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long long int input,i;
	while(scanf("%lld",&input)!=0){
		if (input==0)
			break;
		for(i=1000000000;input>=10;i/=10){
			//printf("%d\n",input);
			input = (input/i) + (input%i);
			if (input>=i)
				i = i*10;
		}
		printf("%lld\n",input);
	}
	return 0;
}
