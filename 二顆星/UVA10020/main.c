#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j,k,n;
   int a[100000]={},b[100000]={},ans[1000]={};
   scanf("%d",&n);
   for(i=0;i<n;i++){
        // 以索引值50000為中點(0)
        for(j=0;j<100000;j++){
            a[j] = 0;
            b[j] = 0;
            if(j<1000)
                ans[j] = 0;
        }
        int M;
        int count = 0;
        scanf("%d",&M);
        scanf("%d %d",&a[0],&b[0]);
        count++;
        while(!(a[count-1]==0 && b[count-1]== 0)){
            scanf("%d %d",&a[count],&b[count]);
            count++;
        }
        int start=0,end=0,find=0;
        int lines=0;
        int max = -1;
        int temp = 0;
        if(M < 0){ // 負的
            for(j=0;j<count;j++){
                if( (a[j]==0 || b[j]==0) && (a[j]>0||b[j]>0) ){
                    if(a[j]>0){
                        end = a[j];
                        max = j;
                    }
                    else{
                        end = b[j];
                        max = j;
                    }
                    if(end>=M){
                        ans[lines++] = j;
                    }
                    break;
                }
            }
            while( end > M){
                for(j=0;j<count;j++){
                    if(a[j]<end && b[j]>=end && end-a[j]>temp ){
                        max = j;
                        temp = end-a[j];
                        //printf("????\n");
                    }
                    else if(b[j]>end && a[j]>=end && end-b[j]>temp){
                        max = j;
                        temp = end-b[j];
                        //printf("????????\n");
                    }
                }
                if(a[max]-b[max]>0){
                    end = b[max];
                }
                else{
                    end = a[max];
                }
                //printf("%d %d\n",a[max],b[max]);
                if(max==-1){
                    lines = 0;
                    break;
                }
                ans[lines++] = max;
                temp = 0;
                max = -1;
            }
        }
        else{ // 正的
            for(j=0;j<count;j++){
                if( (a[j]==0 || b[j]==0) && (a[j]>0||b[j]>0) ){
                    if(a[j]>0){
                        end = a[j];
                        max = j;
                    }
                    else{
                        end = b[j];
                        max = j;
                    }
                    if(M<=end){
                        ans[lines++] = j;
                    }
                    break;
                }
            }
            while( M > end){
                for(j=0;j<count;j++){
                    if(a[j]>end && b[j]<=end && a[j]-end>temp ){
                        max = j;
                        temp = a[j]-end;
                        //printf("????\n");
                    }
                    else if(b[j]>end && a[j]<=end && b[j]-end>temp){
                        max = j;
                        temp = b[j]-end;
                        //printf("????????\n");
                    }
                }
                if(a[max]-b[max]>0){
                    end = a[max];
                }
                else{
                    end = b[max];
                }
                //printf("%d %d\n",a[max],b[max]);
                if(max==-1){
                    lines = 0;
                    break;
                }
                ans[lines++] = max;
                temp = 0;
                max = -1;
            }
        }
        printf("%d\n",lines);
        for(j=0;j<lines;j++)
            printf("%d %d\n",a[ans[j]],b[ans[j]]);
        if(i+1<n)
        	printf("\n");

   }
    return 0;
}
