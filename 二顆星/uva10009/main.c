#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char cities[30][100];
int graph[30][30];
int side,path_num,city_num=0;

void dfs(int ,int);

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        city_num = 0;
        scanf("%d %d",&side,&path_num);
        for(j=0;j<30;j++){
            for(k=0;k<100;k++)
                cities[j][k] = '\0';
            for(k=0;k<30;k++)
                graph[j][j] = 99;
        }
        //printf("input sides\n");
        char from[100],to[100];
        for(j=0;j<side;j++){
            int city1=0,city2=0;
            scanf("%s %s",from,to);
            for(k=0;k<city_num;k++){
                if( !strcmp(cities[k],from)){
                    city1 = k;
                    break;
                }
                if( k==city_num-1 ){
                    city1 = city_num;
                    strcpy(cities[city_num++],from);
                }
            }
            for(k=0;k<city_num;k++){
                if( !strcmp(cities[k],to)){
                    city2 = k;
                    break;
                }
                if( k==city_num-1 ){
                    city2 = city_num;
                    strcpy(cities[city_num++],to);
                }
            }
            if(city_num == 0){
                city1 = 0;
                city2 = 1;
                strcpy(cities[city_num++],from);
                strcpy(cities[city_num++],to);
            }
            graph[city1][city2] = 1;
            graph[city2][city1] = 1;
        }
        /*printf("graph:\n");
        for(k=0;k<city_num;k++)
            printf("%s\n",cities[k]);*/
        char source[100],goal[100];
        int m;
        for(j=0;j<path_num;j++){
            scanf("%s %s",source,goal);
            for(k=0;i<city_num;k++){
                if(!strcmp(cities[k],source))
                    break;
            }
            for(m=0;i<city_num;m++){
                if(!strcmp(cities[m],goal))
                    break;
            }
            dfs(k,m);
        }


    }
    return 0;
}

void dfs(int source,int goal){
    //printf("source:%d goal:%d\n",source,goal);
    int i,j;
    int dis[30];
    int visited[30] = {};
    int top = -1;
    visited[source] = 1;
    dis[++top] = source;
    while(top > -1){
        for(i=0;i<30;i++){
            if(dis[top] == goal){
                for(i=0;i<=top;i++){
                    printf("%c",cities[dis[i]][0]);
                }
                top = -1;
                printf("\n");
                break;
            }
            else if(visited[i] ==0 && graph[dis[top]][i] == 1){
                visited[i] = 1;
                dis[++top] = i;
                break;
            }
            else if(i == 29){
                --top;
            }
        }
    }

}


