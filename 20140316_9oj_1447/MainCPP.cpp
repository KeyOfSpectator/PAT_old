#include <stdio.h>
int ans[101][101];
int main(){
	int n,m;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)break;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i][j]=-1;
			}
			ans[i][i]=0;
		}
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans[a][b]=ans[b][a]=c;
		
		}

		for(int k=1;k<=n;k++){//¾­¹ýkµã
			for(int x=1;x<=n;x++){
				for(int y=1;y<=n;y++){
					if(ans[x][k]==-1||ans[k][y]==-1){
						continue;
						
					}
					if(ans[x][y]==-1||(ans[x][k]+ans[k][y])<ans[x][y]){
						ans[x][y]==ans[x][k]+ans[k][y];
					}
				}
			
			}
		}
		printf("%d\n",ans[1][n]);
	}

	return 0;
}