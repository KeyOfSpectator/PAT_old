#include <stdio.h>


int road[10001];

int main(){

	int l,m,a1,a2;


	while(scanf("%d%d",&l,&m)!=EOF){

		
	for(int j=0;j<10001;j++){
		road[j]=1;
	}

			int count=0;

		for(int i=0;i<m;i++){
			scanf("%d%d",&a1,&a2);
			for(;a1<=a2;a1++){
			road[a1]--;
			}
		}
		for(int k=0;k<=l;k++){
		
			if(road[k]==1){
			count++;
			}
		}
		printf("%d\n",count);
	}	
	return 0;
}