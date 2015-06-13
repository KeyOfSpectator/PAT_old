#include <stdio.h>
#include <algorithm>
using namespace std;

int Tree[101];

struct Edge{
	int a;
	int b;
	int cost;
	bool operator <(const Edge &A)const{
	
		return cost<A.cost;
	}
}e[6000];

int findroot(int x){
	if(Tree[x]==-1)return x;
	else{
		int tmp = findroot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

int main(){
	int n,x;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&x)!=EOF&&n!=0){
		//int m=n*(n-1)/2;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].cost);
		}
		sort(e,e+n);

		for(int k=0;k<101;k++){
			Tree[k]=-1;
		}
		int ans=0;
		for(int j=0;j<n;j++){
			int a=findroot(e[j].a);
			int b=findroot(e[j].b);
			if(a!=b){
				Tree[a]=b;
					ans+=e[j].cost;
			}

		}
		int	root_count = findroot(e[0].a);
		bool flag=true;
		for(int y=1;y<=x;y++){
			if(findroot(y)!=root_count)flag=false;
		}
		if(flag)
		printf("%d\n",ans);
		else
			printf("?\n");
	
	}
	return 0;
}