#include <stdio.h>
#include <algorithm>
using namespace std;

int Tree[101];

struct Edge{
	int a,b;
	int cost;
	bool operator < (const Edge &A)const{
		return cost<A.cost;
	}
}e[6000];

int findroot(int x){
	if(Tree[x]==-1)return x;
	else{
		int tmp=findroot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}

}

int main(){
	int N,edge_id;
	freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d",&N)!=EOF&&N!=0){
		edge_id=0;
		int m=N*(N-1)/2;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&e[edge_id].a,&e[edge_id].b,&e[edge_id].cost);
			edge_id++;
		}
		sort(e,e+edge_id);
		for(int k=0;k<101;k++){
			Tree[k]=-1;
		}

		int ans=0;
		for(int j=0;j<m;j++){
			int a,b;
			a=findroot(e[j].a);
			b=findroot(e[j].b);
			if(a!=b){
				Tree[a]=b;
				ans+=e[j].cost;
			}
		
		}
		printf("%d\n",ans);
	
	}
	return 0;
}