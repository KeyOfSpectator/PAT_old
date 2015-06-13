#include <stdio.h>

int main(){
	int N,Z;
	bool flag=false;
	while(scanf("%d%d",&N,&Z)!=EOF){
		//scanf("%d%d",&N,&Z);
		if(N*Z!=0){
			if(flag)
				printf(" ");
			else flag=true;
			printf("%d %d",N*Z,Z-1);
		}
		else if(!flag)
			printf("0 0");
		
	}

	return 0;
}