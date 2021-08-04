#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
CPE 一顆星考題 UVA11332 20171006

*/
int main()
{   char input[11];
	int i,input_sum;
    while(scanf("%s",input)!=EOF){
    	if(input[0]=='0')
    		break;
        input_sum=0;
        int length = strlen(input);
        for(i=0;i<length;i++){
            input_sum = input_sum + input[i] - '0';
        }
        i = 10;
        while(input_sum>=10){
        	while(input_sum>=i && input_sum >=(i*10))
        		i = i*10;
            input_sum = (input_sum/i) + (input_sum%i);
            i = i/10;
        }
        printf("%d\n",input_sum);
    }
    return 0;
}
