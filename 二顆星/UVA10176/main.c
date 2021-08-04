#include <stdio.h>
#include <stdlib.h>
#define con 131071
/*

CPE二顆星考題 - UVA10176 20171028 大數除法（X）同餘（O）

*/
int main()
{
    char c;
    int num=0;
    while( scanf("%c",&c)!=EOF){
        if(c !='#'){
            if( c!='\n'){
                num = num*2 + (c - '0');
                if(num >= con)
                    num = num - con;
            }
        }
        else{
        	if(!num)
            	printf("YES\n");
            else
            	printf("NO\n");
            num = 0;
        }
    }
    return 0;
}
