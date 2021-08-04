#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

CPE兩顆星題目 UVA10295  20171011
輸入m筆單字資料 及n筆文章 求文章價值

*/
int main()
{
    int m,n,i,j,k,count=0;
    scanf("%d %d",&m,&n);
    char word[m+1][100];
    int word_price[m];
    for(i=0;i<m;i++) // 輸入單字價格
        scanf("%s %d",word[i],&word_price[i]);
    count =0;
    while(count < n ){
        char article[1000000] = {};
        char temp[1000000] = {};
        while(count < n){
            fgets(temp,sizeof(temp),stdin);
            if(temp[0] =='.'){
                count++;
                break;
            }
            else
                strcat(article,temp);
        }
        //printf("結算：\n");
        // 檢查是否存在單字
        int sum_price = 0;
        int article_length = strlen(article);
        int find = 0;
        i = 0;
        while(i<m){
            for(j=find?j:0;j<article_length;j++){ // 尋找該單字第一個字母
                if(article[j] == word[i][0]){
                    //printf("findj:%d %c\n",j,word[i][0]);
                    break;
                }
            }
            if(j == article_length){
                find = 0;
                i++;
                //printf("cant' find j\n",j);
                continue; // 沒找到該單字字首的情況
            }
            // 找到word[i]單字的第一個字母
            int word_length = strlen(word[i]);
            for(k=0;k<word_length;k++){
                if( article[j++] != word[i][k]){
                    find = 1;
                    //printf("not true:%c %c\n",article[j-1],word[i][k]);
                    break; // 單字非一致的情況
                }
            }
            if( k == word_length ){ // 找到的情況
                sum_price = sum_price + word_price[i];
                find = 1;
            }
        }
        printf("%d\n",sum_price);
        sum_price = 0;
    }
    return 0;
}
