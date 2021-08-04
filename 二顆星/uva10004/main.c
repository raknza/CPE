#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int max = 0;

 int dfs();

int main()
{
    int count,n,i,j;
    flag:
    scanf("%d",&n);
    if(n == 0)
        return 1;
    max = n-1;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            graph[i][j] = 999;
            if(i == j)
                graph[i][j] = 0;
        }
    }
    int edges;
    scanf("%d",&edges);
    int node1,node2;
    for(i=0;i<edges;i++){
        scanf("%d %d",&node1,&node2);
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }
    if(dfs())
        printf("BICOLORABLE.\n");
    else
        printf("NOT BICOLORABLE.\n");
    goto flag;
    return 0;
}

int dfs(){
    int visited[100]={};
    int i,j;
    visited[0] = 1;
    int stack[100];
    int top = -1;
    stack[++top] = 0;
    while(top > -1){
        for(i=0;i<=max;i++){
            if(visited[i] == 0 && graph[stack[top]][i] == 1){
                if(visited[stack[top]] == 1)
                    visited[i] = 2;
                else
                    visited[i] = 1;
                stack[++top] = i;
            }
            else if( graph[stack[top]][i] == 1  && visited[i] == visited[stack[top]]){
                return 0;
            }
            else if( i == max )
                top--;
        }
    }
    return 1;
}
