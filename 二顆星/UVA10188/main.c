#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE二顆星考題 - UVA10188 20171015

*/

void safe_flush(FILE *fp)
{
    int ch;
    while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}

int main()
{   int n,i,j,count = 1,lines;
    char text[2][121];
    char temp[121];
    while(1){
        strcpy(text[0],"");
        strcpy(text[1],"");
        strcpy(temp,"");
        for(i=0;i<2;i++){
            scanf("%d",&n);
            safe_flush(stdin);
            for(j=0;j<n;j++){
                gets(temp);
                strcat(text[i],temp);
            }
        }
        if(n==0)
            break;
        int length1 = strlen(text[0]);
        int length2 = strlen(text[1]);
        char temp2[100]={},temp3[100]={};
        int len_t2 = 0,len_t3 = 0,compare = 0;
        if(!strcmp(text[0],text[1]))
            printf("Run #%d: Accepted\n",count);
        else{
            for(i=0;i<length1;i++)
                if(text[0][i] >='0' && text[0][i]<='9')
                    temp2[len_t2++] = text[0][i];
            for(i=0;i<length2;i++)
                if(text[1][i] >='0' && text[1][i]<='9')
                    temp3[len_t3++] = text[1][i];
            for(i=0;i<len_t2;i++)
                if(temp2[i] == temp3[i])
                    compare++;
            if(compare == len_t2 && compare == len_t3)
                printf("Run #%d: Presentation Error\n",count);
            else
                printf("Run #%d: Wrong Answer\n",count);
        }
        count++;
    }
    return 0;
}
