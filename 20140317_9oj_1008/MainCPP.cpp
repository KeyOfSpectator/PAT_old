#include <stdio.h>
#include <vector>
using namespace std;
struct E{
	int next;
	int c;
	int cost;
};
vector<E> e[1001];
int mark[1001];
int dist[1001];
int cost[1001];


int main(){
	int n,m;
	int S,T;
//	freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)break;
		for(int i=0;i<=n;i++)e[i].clear();
		while(m--){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			E tmp;
			tmp.next=b;
			tmp.c=c;
			tmp.cost=d;
			e[a].push_back(tmp);
			tmp.next=a;
			e[b].push_back(tmp);

		}
		scanf("%d%d",&S,&T);
		for(int j=0;j<=n;j++){
			mark[j]=false;
			dist[j]=-1;
			//cost[j]=-1;
		}
		mark[S]=true;
		dist[S]=0;

		int new_p=S;//start point

		for(int k=1;k<=n;k++){
			for(int eg=0;eg<e[new_p].size();eg++){
				int t=e[new_p][eg].next;
				int c=e[new_p][eg].c;
				int co=e[new_p][eg].cost;
				if(mark[t]==true)continue;
				if(dist[t]==-1||dist[t]>dist[new_p]+c||(dist[t]==dist[new_p]+c&&cost[t]>cost[new_p]+co)){
					dist[t]=dist[new_p]+c;
					cost[t]=cost[new_p]+co;
				}
				
			}
			int min=10000000;
			for(int l=1;l<=n;l++){
				if(mark[l]==true)continue;
				if(dist[l]==-1)continue;
				if(dist[l]<min){
					min=dist[l];
					new_p=l;
				}
			}
			mark[new_p]=true;
		}

	printf("%d %d\n",dist[T],cost[T]);
	
	}
	return 0;
}