#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d",&num);
    char alphabet[27]={};
    char sub_alphabet[27]={};
    getchar();
    getchar();
    while(num--){
        int i;
        fgets(alphabet,sizeof(alphabet),stdin);
        fgets(sub_alphabet,sizeof(sub_alphabet),stdin);
        for(i=0;i<26;i++){
            sub_alphabet[i];
        }
		for(i=0;i<26;i++){
            printf("%c",sub_alphabet[i]);
        }
        printf("\n");
        for(i=0;i<26;i++){
            printf("%c",alphabet[i]);
        }

        char str[65]={};
        while(fgets(str,sizeof(str),stdin)!=NULL){
            for(i=0;str[i]!='\0';i++){
                if(str[i] <='z'&& str[i]>='a'){
                    int j=0;
                    for(j=0;j<26;j++){
                        if(str[i] == alphabet[j]){
                            printf("%c",sub_alphabet[j]);
                            break;
                        }
                    }
                }
                else
                    printf("%c",str[i]);
            }
        }

    }
    return 0;
}
