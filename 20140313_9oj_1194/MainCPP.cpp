#include <stdio.h>

int main(){
	int n,m=0;
	while(scanf("%d",&n)!=EOF){
		char temp[30];int id=0;
		do{
			temp[id++]=n%8+'0';
			n/=8;
		}while(n);
		for(int i=id-1;i>=0;i--){
			printf("%c",temp[i]);
		}
		printf("\n");
	}
	return 0;
}