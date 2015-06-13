#include <stdio.h>
#include <vector>
using namespace std;

struct E{
	int next;
	int c;
};
bool mark[101];
int dist[101];
vector<E> e[10001];

int main(){
	int n,m;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)break;
		
		for(int i=1;i<n;i++){
			e[i].clear();
		}
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.next=b;
			tmp.c=c;
			e[a].push_back(tmp);
			tmp.next=a;
			e[b].push_back(tmp);
			

		
		}
		for(int j=1;j<=n;j++){
			mark[j]=false;
			dist[j]=-1;
		}
		dist[1]=0;
		mark[1]=true;
		int new_p=1;

		for(int k=1;k<n;k++){
			for(int edg=0;edg<e[new_p].size();edg++){
				int t=e[new_p][edg].next;
				int c=e[new_p][edg].c;
				if(mark[t]==true)continue;
				if(dist[t]==-1||dist[t]>dist[new_p]+c){
					dist[t]=dist[new_p]+c;
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
		printf("%d\n",dist[n]);
	
	
	}
	return 0;
}