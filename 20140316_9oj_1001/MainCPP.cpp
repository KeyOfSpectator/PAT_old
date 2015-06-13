#include <stdio.h>

int main(){
	int n,m;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		int a[11][11];
		int b[11][11];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);	
			}
		}
		for(int k=0;k<n;k++){
			for(int l=0;l<m;l++){
				scanf("%d",&b[k][l]);	
				b[k][l]+=a[k][l];
			}
		}
		int ans=0;
		for(int u=0;u<n;u++){
			bool flag = true;
			for(int v=0;v<m;v++){
				if(b[u][v]!=0)
					flag = false;
			}
			if(flag)ans++;
		}
		
		for(int y=0;y<m;y++){
			
			bool flag = true;
				for(int x=0;x<n;x++){
				if(b[x][y]!=0)flag = false;
			}
			if(flag)
				ans++;
		}
		printf("%d\n",ans);
		
	}
	
	
	return 0;

}