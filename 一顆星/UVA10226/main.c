#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    char name[31];
    int num;
}element;

void swap(element tree[],int j,int k){
    int tmp;
    char temp[31];
    strcpy(temp,tree[j].name);
    tmp = tree[j].num;
    tree[j].num = tree[k].num;
    tree[k].num = tmp;
    strcpy(tree[j].name,tree[k].name);
    strcpy(tree[k].name,temp);
}


int main()
{
    element tree[10000];
    int n,i,j,k;
    scanf("%d",&n);
    char temp[31];
    gets(temp);
    gets(temp);
    for(i=0;i<n;i++){
        for(j=0;j<10000;j++)
            tree[j].num = 0;
        int total = 0;
        int num = 0;
        while(gets(temp)){
        	if(temp[0] == 0)
        		break;
            for(j=0;j<total;j++){
                if( !strcmp(temp,tree[j].name) ){
                    tree[j].num++;
                    break;
                }
                else if( j+1 == total ){
                    strcpy(tree[j+1].name,temp);
                    tree[j+1].num = 1;
                    total++;
                    break;
                }
            }
            if(total == 0){
                strcpy(tree[total].name,temp);
                    tree[total].num = 1;
                total++;
            }
            num++;
        }
        if(i!=0)
        	printf("\n");
        int tmp;
        for(j=0;j<total;j++){
            for(k=j;k<total;k++){
                if( strcmp(tree[j].name,tree[k].name) > 0 ){
                    swap(tree,j,k);
                }
            }
        }
        for(j=0;j<total;j++)
            printf("%s %.4lf\n",tree[j].name,((double)tree[j].num/(double)num)*100);
        //            prilntf("%s %d\n",tree[j].name,tree[j].num);
    }
    return 0;
}
