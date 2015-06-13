#include <stdio.h>

int Tree[1001];

int findroot(int x){
	if(Tree[x]==-1)return x;
	else{
		int tmp=findroot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
		
	}

}
int main(){
	int n,m,c;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d",&c)!=EOF){
	while(scanf("%d%d",&n,&m)!=EOF&&c--){
		for(int i=1;i<=n;i++){
			Tree[i]=-1;
		}

		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b){
				Tree[a]=b;
			}

		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(Tree[j]==-1)ans++;		
		}
		printf("%d\n",ans);
		
	}
	}
	return 0;
}