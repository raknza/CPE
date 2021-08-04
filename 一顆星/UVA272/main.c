#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE一顆星考題 - UVA272 20171014

*/
int main()
{
    char sentence[1000] = {};
    char temp[1000] = {};
    int i,j,count = 0;
    strcpy(sentence,"");
    while(gets(temp)){
        strcat(sentence,temp);
        strcat(sentence,"\n");
    }
    char temp2[1000] = {};
    char temp3[1000] = {};
    for(i=0;i<strlen(sentence);i++){
        if( sentence[i] == '"'){
			strncpy(temp2,sentence,i);
			strncpy(temp3,sentence+i+1,strlen(sentence)-i);
            if( (count)%2 == 1)
            	strcat(temp2,"''");
            if( (count)%2 == 0)
            	strcat(temp2,"``");
            count++;
            strcpy(sentence,temp2);
            strcat(sentence,temp3);
		}
    }
    printf("%s",sentence);
    return 0;
}
