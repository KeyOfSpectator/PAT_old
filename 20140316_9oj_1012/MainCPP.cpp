#include <stdio.h>

int Tree[1000];

int findroot(int x){
	if(Tree[x]==-1){
		return x;
	}else{
		int tmp=findroot(Tree[x]);
		Tree[x]=tmp;
		return tmp;

	}

}

int main(){
	int N,M;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt", "r", stdin );
	while(scanf("%d%d",&N,&M)!=EOF&&N!=0){
		for(int i=1;i<=N;i++){
			Tree[i]=-1;
		}
		while(M--){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b){Tree[a]=b;}
			
			

		}
		int ans=0;
		for(int j=1;j<=N;j++){
			if(Tree[j]==-1)ans++;
		
		}
		printf("%d\n",ans-1);
	
	}
	
	return 0;
}