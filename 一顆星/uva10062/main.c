#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int ascii[200]={};
    int i,j;
    char input[1000]={};
    int ct = 0;
    while(fgets(input, sizeof(input), stdin)!=NULL) {
        if(input[0] == '\0')
            break;
        //printf("%s\n%d",input,strlen(input));
        if(ct==1 && input[0]!=10)
            printf("\n");
        int length = strlen(input);
        for(i=0;i<length;i++)
            ascii[input[i]]++;
        //printf("%s\n",input);
        //printf("%s %d",input,length);
        int start = 1;
        int repeat = 0;
        for(i=128;i>=28;i--){
            if(ascii[i] == start){
                printf("%d %d\n",i,ascii[i]);
                ascii[i] = 0;
                i = 129;
                repeat = 0;
            }
            if(repeat == 1 && i==28 && start<1001){
                start++;
                i = 129;
            }
            else if(repeat == 0 && i==28){
                repeat++;
                i = 129;
            }
        }
        input[0] = '\0';
        ct = 1;
    }
    return 0;
}
