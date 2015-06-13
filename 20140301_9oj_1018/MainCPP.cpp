#include <stdio.h>

int score[101];
int main(){
	int N,scoreTmp,scoreSearch;

	while(scanf("%d",&N)!=EOF){
		if(N==0) break;
		for(int j=0;j<101;j++){
		score[j]=0;
		}
		for(int i=0;i<N;i++){
			scanf("%d",&scoreTmp);
			score[scoreTmp]++;	
		}
		scanf("%d",&scoreSearch);
		printf("%d\n",score[scoreSearch]);
		
	}



return 0;
}