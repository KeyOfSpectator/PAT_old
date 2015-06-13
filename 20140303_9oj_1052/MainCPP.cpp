#include <stdio.h>

int main(){
	int n,m,j;
	int data[201];

	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);

	scanf("%d",&m);
	j=0;
	while(j<n&&data[j]!=m){
		j++;
	}

	if(j==n)
		printf("-1\n");
	else
		printf("%d\n",j);

	}
	return 0;
}