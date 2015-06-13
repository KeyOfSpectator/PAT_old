#include <stdio.h>
#include <algorithm>
using namespace std;

int Tree[101];

struct Edge{
	int a;
	int b;
	int cost;
	int flag;
	bool operator <(const Edge &A)const{
		if(flag!=A.flag)return flag>A.flag;
		else return cost<A.cost;
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
	int n;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d",&n)!=EOF&&n!=0){
		int m=n*(n-1)/2;
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&e[i].a,&e[i].b,&e[i].cost,&e[i].flag);
		}
		sort(e,e+m);

		for(int k=0;k<101;k++){
			Tree[k]=-1;
		}
		int ans=0;
		for(int j=0;j<m;j++){
			int a=findroot(e[j].a);
			int b=findroot(e[j].b);
			if(a!=b){
				Tree[a]=b;
				
				if(e[j].flag==1){
					
				}
				else{
					ans+=e[j].cost;
				}
			}

		}
		printf("%d\n",ans);
	
	}
	return 0;
}