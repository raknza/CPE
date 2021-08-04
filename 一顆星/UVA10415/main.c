#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int key[14];
    int finger[11];
    int i,j,k,n;
    char temp[200];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<14;j++){
            key[j] = 0;
            if(j<11)
                finger[j] = 0;
        }
        scanf("%s",&temp);
        for(j=0;temp[j]!='\0';j++){
            if(temp[j] >='c' &&temp[j]<='g')
                key[temp[j]-'c']++;
            else if(temp[j] <='b' && temp[j]>='a')
                key[temp[j]-'a'+5]++;
            else if(temp[j] <='G' && temp[j]>='C')
                key[temp[j]-'C']++;
            else if(temp[j] <='B' && temp[j]>='A')
                key[temp[j]-'A'+12]++;
        }
        for(j=0;j<14;j++){
            if(j==0){
                for(k=2;k<=4;k++)
                    finger[k] = finger[k] + key[j];
                for(k=7;k<=10;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==1){
                for(k=2;k<=4;k++)
                    finger[k] = finger[k] + key[j];
                for(k=7;k<=9;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==2){
                for(k=2;k<=4;k++)
                    finger[k] = finger[k] + key[j];
                for(k=7;k<=8;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==3){
                for(k=2;k<=4;k++)
                    finger[k] = finger[k] + key[j];
                for(k=7;k<=7;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==4){
                for(k=2;k<=4;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==5){
                for(k=2;k<=3;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==6){
                for(k=2;k<=2;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==7){
                for(k=3;k<=3;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==8){
                for(k=1;k<=4;k++)
                    finger[k] = finger[k] + key[j];
                for(k=7;k<=9;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==9){
                for(k=1;k<=4;k++)
                    finger[k] = finger[k] + key[j];
                for(k=7;k<=8;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==10){
                for(k=1;k<=4;k++)
                    finger[k] = finger[k] + key[j];
                for(k=7;k<=7;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==11){
                for(k=1;k<=4;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==12){
                for(k=1;k<=3;k++)
                    finger[k] = finger[k] + key[j];
            }
            if(j==13){
                for(k=1;k<=2;k++)
                    finger[k] = finger[k] + key[j];
            }
        }
        for(j=1;j<=10;j++)
            printf("%d ",finger[j]);

    }
    return 0;
}
