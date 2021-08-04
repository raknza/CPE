#include <stdio.h>
#include <stdlib.h>

void dfs(int map[5000][100],int i,int j,int row,int col){
    int k;
    const int moverow[8]={-1,-1,0,1,1,1,0,-1};
    const int movecol[8]={0,1,1,1,0,-1,-1,-1};
    for(k=0;k<8;k++){
        int newrow = i+moverow[k];
        int newcol = j+movecol[k];
        if( newrow >=0 && newrow<row && newcol>=0 && newcol<col && map[newrow][newcol] >=0 ){
            map[newrow][newcol]++;
        }
    }
}

int main()
{
    int i,j,row,col;
    int Field = 1;
    int map[5000][100]={};
    while(1){
        for(i=0;i<5000;i++){
            for(j=0;j<100;j++)
                map[i][j] = 0;
        }
        scanf("%d %d",&row,&col);
        if(row==0 && col==0)
            break;
        for(i=0;i<row;i++){
            getchar();
            for(j=0;j<col;j++){
                char temp = getchar();
                if(temp == '*')
                    map[i][j] = -1;
                else
                    map[i][j] = 0;
            }
        }
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(map[i][j] == -1){
                    dfs(map,i,j,row,col);
                }
            }
        }
        if(Field > 1)
            printf("\n");
        printf("Field #%d:\n",Field++);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(map[i][j] != -1)
                    printf("%d",map[i][j]);
                else
                    printf("*");
            }
            printf("\n");
        }

    }
    return 0;
}
