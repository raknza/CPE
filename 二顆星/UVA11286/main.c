#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int lesson[5];
}lessons;
int compare(lessons A,lessons B){
    int i,j;
    for(i=0;i<5;i++){
        int flag = 0;
        for(j=0;j<5;j++){
            if(A.lesson[i]==B.lesson[j]){
                flag = 1;
                break;
            }
        }
        if( flag == 0 ){
            //printf("¥¢±Ñ\n");
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i,j,n;
    lessons student[100000];
    scanf("%d",&n);
    while(n!=0){
        //printf("input student:\n");
        int max = 1;
        int max_num = 0;
        for(i=0;i<n;i++){
            for(j=0;j<5;j++){
                scanf("%d",&student[i].lesson[j]);
            }
            int count = 1;
            for(j=i-1;j>=0;j--){
                if(compare(student[i],student[j]) && compare(student[j],student[i]))
                    count++;
            }

            if(count > max){
                max = count;
                max_num = count;
            }
            else if(count == max)
                max_num = max_num +1;
        }
        printf("%d\n",max_num);
        scanf("%d",&n);
    }
    return 0;
}
