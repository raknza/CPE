#include <stdio.h>
#include <stdlib.h>


void dfs(int ,int ,int);

int max_row,max_col,i,j;
char map[100][100]={};
int visited[100][100]={};

int main()
{

    while(1){
        scanf("%d%d",&max_row,&max_col);
        if(max_row == 0 && max_col == 0)
            break;
        getchar();
        //printf("input map:\n");
        for(i=0;i<max_row;i++){
        	scanf("%s",&map[i]);
            getchar();
        }
        for(i=0;i<max_row;i++){
      		for(j=0;j<max_col;j++){
      			visited[i][j] = 0;
      		}
      	}
        int count = 0;
        for(i=0;i<max_row;i++){
            for(j=0;j<max_col;j++){
                if(!visited[i][j] && map[i][j] == '@')
                    dfs(i,j,++count);
            }

        }
        printf("%d\n",count);
    }
    return 0;
}

void dfs(int row,int col,int mark){
    if(row< 0 || col < 0 || row >=max_row || col >= max_col || visited[row][col]!=0 || map[row][col] == '*')
        return ;
    //printf("%d %d\n",row,col);
    visited[row][col] = mark;
    dfs(row-1,col,mark);
    dfs(row-1,col+1,mark);
    dfs(row,col+1,mark);
    dfs(row+1,col+1,mark);
    dfs(row+1,col,mark);
    dfs(row+1,col-1,mark);
    dfs(row,col-1,mark);
    dfs(row-1,col-1,mark);
}

