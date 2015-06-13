#include <stdio.h>
#include <vector>
using namespace std;


struct E{
	int next;
	int c;
	int co;

};

vector<E> e[1001];
bool mark[1001];
int sum[1001];
int dist[1001];

int main(){
	int n,m;

	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );

	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)break;

		for(int ic=0;ic<1000;ic++){e[ic].clear();}

		for(int im=0;im<m;im++){
			int a,b,d,p;
			scanf("%d%d%d%d",&a,&b,&d,&p);
			E tmp;
			tmp.c = d;
			tmp.co = p;
			tmp.next = b;
			e[a].push_back(tmp);
			tmp.next = a;
			e[b].push_back(tmp);
		}
		
		for(int in =1;in<=1000;in++){
			mark[in]=false;
			sum[in]=0;
			dist[in]=-1;
		}
		int s,end;
		scanf("%d%d",&s,&end);
		
		mark[s]=true;
		dist[s]=0;
		int new_p = s;

		for(int i = 1;i<n;i++){//n-1
		for(int ie=0;ie<e[new_p].size();ie++){
			int ne = e[new_p][ie].next;
			int ec = e[new_p][ie].c;
			int eco = e[new_p][ie].co;

			if(mark[ne]==true)continue;
			if(dist[ne]==-1||dist[ne]>dist[new_p]+ec ||dist[ne]==dist[new_p]+ec&&sum[ne]>sum[new_p]+eco){//
				dist[ne]=dist[new_p]+ec;
				sum[ne]=sum[new_p]+eco;

			}

		}
		int max_t = 10000000;
		for(int id = 1;id<=n;id++){
			//int max_t = 1000000;
			if(mark[id]==true)continue;
			if(dist[id]==-1)continue;
			if(max_t>dist[id]){
					max_t=dist[id];
					new_p = id;
			}
			
		}
		mark[new_p]=true;
		}

		printf("%d %d\n",dist[end],sum[end]);

	}
	

	return 0;
}