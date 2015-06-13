#include <stdio.h>

#define OFFSET 500000
int buf[1000001];

int main(){
	int n,m,tmp,k=1000000;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int j=0;j<1000001;j++){
			buf[j]=0;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			buf[tmp+OFFSET]++;
		}
		for(int k=1000000;k>=0;k--){
			if(buf[k]>0&&m>1){
				buf[k]--;
				m--;
				printf("%d ",k-OFFSET);
			}
			else if(buf[k]>0&&m==1){
				buf[k]--;
				m--;
				printf("%d",k-OFFSET);
			}
		}
		printf("\n");
	}

	return 0;
}