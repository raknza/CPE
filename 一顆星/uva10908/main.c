#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,T;
    char map[100][100]={};
    scanf("%d",&T);
    for(i=0;i<T;i++){
        for(j=0;j<100;j++){
            for(k=0;k<100;k++)
                map[j][k] = '\0';
        }
        int row,col,count,x,y;
        scanf("%d %d %d",&row,&col,&count);
        printf("%d %d %d\n",row,col,count);
        for(j=0;j<row;j++){
            scanf("%s",map[j]);
        }
        for(j=0;j<count;j++){
            scanf("%d %d",&y,&x);
            char temp = map[y][x];
            int number = 1;
            while(1){
                int starty = y - number;
                int startx = x - number;
                int nowy = starty;
                int nowx = startx;
                int find = 0;
                if( starty <0 || startx <0 )
                    find = 1;
                //printf("start:%d,%d\n",starty,startx);
                for(;nowx<=x+number;nowx++){
                    if(map[nowy][nowx] != temp){
                        find = 1;
                        break;
                    }
                }
                nowx--;
                for(;nowy<=y+number;nowy++){
                    if(map[nowy][nowx] != temp){
                        find = 1;
                        break;
                    }
                }
                nowy--;
                for(;nowx>=x-number;nowx--){
                    if(map[nowy][nowx] != temp){
                        find = 1;
                        break;
                    }
                }
                nowx++;
                for(;nowy>=y-number;nowy--){
                    if(map[nowy][nowx] != temp){
                        find = 1;
                        break;
                    }
                }
                nowy++;
                //printf("now:%d,%d\n",nowy,nowx);
                if(find == 1)
                    break;
                else
                    number++;
            }
            printf("%d\n",number*2-1);
        }
    }
    return 0;
}
