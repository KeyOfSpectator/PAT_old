#include <stdio.h>

int books[201];
int info[201];	//

int main(){
	int n,m,tmp;
	while(scanf("%d%d",&n,&m)!=EOF){

		for(int j=0;j<201;j++){
		books[j]=0;
		}
		for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		info[i]=tmp;
		books[tmp]++;
		}

		for(int k=0;k<n;k++){
			if(books[info[k]]>1)
				printf("%d\n",books[info[k]]-1);
			else
				printf("BeiJu\n");
		}
	}
	return 0;
}