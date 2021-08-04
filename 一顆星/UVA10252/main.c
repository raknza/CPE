#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE一顆星考題 - UVA10252 20171012

*/
int main()
{   char a[100],b[100];
    int a_length,b_length,i,j,k;
    int alphabet[26];
    while(scanf("%s %s",a,b)!=EOF){
        for(i=0;i<26;i++)
            alphabet[i] = 0;
        a_length = strlen(a);
        b_length = strlen(b);
        int bool_b[b_length];
        for(i=0;i<b_length;i++)
            bool_b[i] = 0;
        for(i=0;i<a_length;i++){
            for(j=0;j<b_length;j++){
                if(a[i] == b[j] &&bool_b[j]==0){
                    for(k=0;k<26;k++)
                        if( k+'a' == a[i]){
                            bool_b[j] = 1;
                            alphabet[k]++;
                        }
                    break;
                }
            }
        }
        for(i=0;i<26;i++)
            if(alphabet[i]!=0)
                for(j=alphabet[i];j>0;j--)
                    printf("%c",i+'a');
        printf("\n");
    }
    return 0;
}
