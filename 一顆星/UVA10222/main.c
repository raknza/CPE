#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 UVA10222 20171004

*/
int main()
{   //
    char input[100];
    char keyboard[4][13] = {'`','1','2','3','4','5','6','7','8','9','0','-','='
                            ,'q','w','e','r','t','y','u','i','o','p','[',']','\\'
                            ,'a','s','d','f','g','h','j','k','l',';','\'','\0','\0'
                            ,'z','x','c','v','b','n','m',',','.','/','\0','\0','\0'};
    char keyboard_encypt[4][13] = {'-','=','`','1','2','3','4','5','6','7','8','9','0'
                            ,']','\\','q','w','e','r','t','y','u','i','o','p','['
                            ,';','\'','a','s','d','f','g','h','j','k','l','\0','\0'
                            ,'.','/','z','x','c','v','b','n','m',',','\0','\0','\0'};
    char keyboard_caps[4][13] = {'`','1','2','3','4','5','6','7','8','9','0','-','='
                            ,'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'
                            ,'A','S','D','F','G','H','J','K','L',';','\'','\0','\0'
                            ,'Z','X','C','V','B','N','M',',','.','/','\0','\0','\0'};
    int i,j,k;
    while(fgets(input, sizeof(input), stdin)!=NULL){
        for(i=0;input[i]!='\0';i++){
            //printf("input[%d] = %c\n",i,input[i]);
            if(input[i] ==' ')
                printf(" ");
            for(j=0;j<4;j++){
                for(k=0;k<13;k++){
                    if(input[i]==keyboard[j][k] || input[i]==keyboard_caps[j][k])
                        printf("%c",keyboard_encypt[j][k]);
                }

            }
        }
        printf("\n");
    }
    return 0;
}
