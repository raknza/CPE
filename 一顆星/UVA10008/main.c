#include <stdio.h>
#include <stdlib.h>
/*

CPE一顆星考題 - UVA10008 20170930

*/

void safe_flush(FILE *fp)
{
	int ch;
	while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}

int main(){
	int n,i,j,alphabet[26];
	for(i=0;i<26;i++)
		alphabet[i] = 0;
	while(scanf("%d",&n)!=EOF){
		char sentence[n][100];
		for(i=0;i<n;i++)
            for(j=0;j<100;j++)
                sentence[i][j] = '0';
        safe_flush(stdin);
		for(i=0;i<n;i++){
            fgets(sentence[i], sizeof(sentence), stdin);
		}
		for(i=0;i<n;i++){
			for(j=0;j<100;j++){
				if(sentence[i][j]>='a' && sentence[i][j]<='z')
					sentence[i][j]-=32;
				if(sentence[i][j]>='A' && sentence[i][j]<='Z')
					alphabet[sentence[i][j]-'A']++;
			}
		}
		int max=0,max_alphabet,bool_alphabet[26];
		for(i=0;i<26;i++)
			bool_alphabet[i] = 0;
		for(i=0;i<26;i++){
			for(j=0;j<26;j++){
				if(alphabet[j]>max&& bool_alphabet[j]==0){
					max = alphabet[j];
					max_alphabet = j;
				}
			}
			if(max>0)
				printf("%c %d\n",max_alphabet+'A',max);
            bool_alphabet[max_alphabet] = 1;
			max = 0;
			max_alphabet = 0;
		}

	}
	return 0;
}
