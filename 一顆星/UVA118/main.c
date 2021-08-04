#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,row,col;
    int wallx[50]={};
    int wally[50]={};
    int num = 0;
    scanf("%d %d",&col,&row);
    int x,y;
    char dir;
    int t = 0;
    while(~scanf("%d %d %c",&x,&y,&dir)){
        char command[51];
        scanf("%s",&command);
        for(i=0;command[i]!='\0';i++){
            int tmpx = x;
            int tmpy = y;
            char tmpdir = dir;
            if(command[i] == 'L'){ // ¥ªÂà
                if(dir == 'N')
                    dir = 'W';
                else if(dir == 'S')
                    dir = 'E';
                else if(dir == 'E')
                    dir = 'N';
                else if(dir == 'W')
                    dir = 'S';
            }
            else if(command[i] == 'R'){ // ¥kÂà
                if(dir == 'N')
                    dir = 'E';
                else if(dir == 'E')
                    dir = 'S';
                else if(dir == 'S')
                    dir = 'W';
                else if(dir == 'W')
                    dir = 'N';
            }
            else if(command[i] == 'F'){
                if(dir == 'N')
                    y++;
                else if(dir == 'S')
                    y--;
                else if(dir == 'E')
                    x++;
                else if(dir == 'W')
                    x--;
            }
            t = 0;
            for(j=0;j<num;j++){
                if(x == wallx[j] && y == wally[j]){
                    x = tmpx;
                    y = tmpy;
                    break;
                }
            }
            if(x < 0 || x>col || y<0 || y>row){
                wallx[num] = x;
                wally[num++] = y;
                x = tmpx;
                y = tmpy;
                dir = tmpdir;
                t = 1;
                break;
            }
            if(t==1)
                break;
        }

        if(t==1){
            printf("%d %d %c ",x,y,dir);
            printf("LOST");
        }
        else
            printf("%d %d %c ",x,y,dir);
        printf("\n");
    }
    return 0;
}
