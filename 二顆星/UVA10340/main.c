#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE兩顆星考題 - UVA10340 20171006

*/

int main()
{   char string_a[100],string_b[100],string_temp[100];
    int i,j,k,count,length_a,length_b,bool_string[100];
    while(scanf("%s %s",string_a,string_b)!=EOF){
        for(i=0;i<100;i++)
            bool_string[i] = 0;
        for(i=0;i<100;i++)
            string_temp[i] = 0;
        length_a = strlen(string_a);
        length_b = strlen(string_b);
        count = 0;

        for(i=0;i<length_a;i++){
            for(j=0;j<length_b;j++){
                if(string_a[i] == string_b[j] && bool_string[j]==0){
                    for(k=0;k<=i;k++){
                        if(string_temp[k]>j)
                            break;
                        else if(string_temp[k]<=j && k == (i)){
                            bool_string[j] = 1;
                            string_temp[i] = j;
                        }

                    }
                    if(bool_string[j]==1)
                        break;
                }
            }
        }
        for(i=0;i<length_a;i++){
            if(string_a[i] == string_b[string_temp[i]])
                count++;
        }
        if(count == length_a)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
