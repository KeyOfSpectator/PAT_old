#include<stdio.h>
int main(){
	int m,n;
	int a[100][100];
	int b[100][100];
	int i,j;
	while(scanf("%d%d",&m,&n)!=EOF){
	
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
			scanf("%d",a[i][j]);
		}

		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
			scanf("%d",b[i][j]);
		}

		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
			printf("%d ",&a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}