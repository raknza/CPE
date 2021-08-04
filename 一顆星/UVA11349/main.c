#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA11349 20171025

*/
int main()
{
    int i,j,k,n,line,sym=1;
    char temp[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %s %d",temp,temp,&line);
        int matrix[line][line];
        for(j=0;j<line;j++){
            for(k=0;k<line;k++){
                scanf("%d",&matrix[j][k]);
                if(matrix[j][k]<0)
                    sym = 0;
            }
        }
        if(sym==0){
            printf("Test #%d: Non-symmetric.\n",i+1);
            sym = 1;
            continue;
        }
        else{
            for(j=0;j<line;j++){
                for(k=0;k<line;k++){
                    if(matrix[j][k]!=matrix[line-1-j][(line-1)-k])
                        sym = 0;
                }
            }
        }
        if(sym==0)
            printf("Test #%d: Non-symmetric.\n",i+1);
        else
            printf("Test #%d: Symmetric.\n",i+1);
        sym = 1;
    }
    return 0;
}
