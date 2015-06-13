#include <stdio.h>
#include <vector>
using namespace std;

struct Edge{
	int from;
	int next;
};

int Tree[1005];

int findroot(int x){
	if(Tree[x]==-1)return x;
	int tmp = findroot(Tree[x]);
	Tree[x]=tmp;
	return tmp;
}

//vector <Edge>EList;
Edge EList[500000];

int main(){
	int N,M,K;

	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );

	while(scanf("%d%d%d",&N,&M,&K)!=EOF){
		//EList.clear();
		int id=0;
		for(int i=0;i<M;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			Edge tmp;
			tmp.from=a;tmp.next=b;
			EList[id++]=tmp;
		}

		for(int j=0;j<K;j++){
			for(int k=1;k<=N;k++){Tree[k]=-1;}	//init	
			int node_id;
			scanf("%d",&node_id);
			Tree[node_id]=0;
			for(int x=0;x<id;x++){
				int f=EList[x].from,
					e=EList[x].next;
				if(f!=node_id&&e!=node_id){
					f=findroot(f);
					e=findroot(e);
					if(f!=e){
						Tree[f]=e;
						
					}
				}
			}
			int ans=0;
			for(int y=1;y<=N;y++){
				if(Tree[y]==-1){
					ans++;
				}
			}
			printf("%d\n",ans-1);
		}

	
	}
	return 0;
}