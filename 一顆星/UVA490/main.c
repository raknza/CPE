#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE一顆星考題 - UVA490 20171013

*/
int main()
{   char New_sentence[101][101]={};
    int i=0,j;
    char sentence[101][101]={};
	int length2 = 0;
    while(gets(sentence[i])!=NULL){
        strncpy(sentence[i],sentence[i],strlen(sentence[i]));
        if(strlen(sentence[i])>length2)
        	length2 = strlen(sentence[i]);
    	if(i == 100)
    		break;
    	else
    		i++;

    }
    int length = i;
    for(i=0;i<length2;i++){
    	for(j=0;j<length-1;j++){
    		New_sentence[i][j] = ' ';
    		//printf("New_sentence[%d][%d]:「%c」\n",i,j,New_sentence[i][j]);
    	}
    }
    for(i=0;i<length;i++){
        //printf("strlen(sentence[i]):%d\n",strlen(sentence[i]));
        //printf("le:%d\n",strlen(sentence[i]));
        for(j=0;j<strlen(sentence[i]);j++){
            New_sentence[j][length-1-i] = sentence[i][j];
        }
    }
	//printf("le2:%d\n",length2);
    for(i=0;i<length2;i++){
    	for(j=0;j<length;j++){
        	printf("%c",New_sentence[i][j]);
        }
        printf("\n");
    }
    return 0;
}
