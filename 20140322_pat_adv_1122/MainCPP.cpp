#include <stdio.h>

int F[21];

void init(){
	F[0]=0;
	F[1]=1;
	F[2]=2;
	for(int i=3;i<20;i++){
		F[i]=F[i-1]+F[i-2];
	}

}

int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",F[n]);
	
	}

	return 0;
}