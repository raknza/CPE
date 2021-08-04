#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE二顆星考題 - UVA495 20171025

*/
int main()
{   int n,i,j;
    int A[1000]={},B[1000]={};
    A[0] = 0;
    B[0] = 1;
    int length1 = 1,length2 = 1;
    while(scanf("%d",&n)!=EOF){
        for(i=2;i<=n;i++){
            for(j=0;j<length1 || j<length2;j++){
                if(i%2==0){ // A在後的情況
                    A[j] = A[j] + B[j];
                    if(A[j]>=10){
                        A[j+1]++;
                        A[j] = A[j] - 10;
                        if(j==length1-1)
                            length1++;
                    }
                }
                else{ // B在後的情況
                    B[j] = B[j] + A[j];
                    if(B[j]>=10){
                        B[j+1]++;
                        B[j] = B[j] - 10;
                        if(j==length2-1)
                            length2++;
                    }
                }
            }
        }
        int first=0;
        if(n%2==0){
            printf("The Fibonacci number for %d is ",n);
            for(i=length1;i>=0;i--){
                if(first==0){
                    if(A[i]!=0){
                        first = 1;
                        i++;
                    }
                }
                else
                    printf("%d",A[i]);
            }
            printf("\n");
            first = 0;
        }
        else{
            printf("The Fibonacci number for %d is ",n);
            for(i=length2;i>=0;i--){
                if(first==0){
                    if(B[i]!=0){
                        first = 1;
                        i++;
                    }
                }
                else
                    printf("%d",B[i]);
            }
            printf("\n");
        }
        length1 = 1;
        length2 = 1;
        A[0] = 0;
        B[0] = 1;
        for(i=1;i<1000;i++){
            A[i] = 0;
            B[i] = 0;
        }
    }

    return 0;
}
