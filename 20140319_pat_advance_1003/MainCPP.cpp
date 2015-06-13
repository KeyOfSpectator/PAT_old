#include <stdio.h>
#include <vector>
using namespace std;

struct Node{
	int next;
	int c;

};

vector<Node> E[501];

bool mark[501];
int dist[501];
int num[501];
int last_id[501];
int d_num[501];


int main(){
	int n,m,c,d;

	freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );

	while(scanf("%d%d%d%d",&n,&m,&c,&d)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		for(int j=0;j<m;j++){
			int t_c1,t_c2,cost;
			scanf("%d%d%d",&t_c1,&t_c2,&cost);
			Node tmp;
			tmp.next=t_c2;
			tmp.c=cost;
			E[t_c1].push_back(tmp);
		
		}
		for(int k=0;k<n;k++){
			mark[k]=false;
			dist[k]=-1;
			last_id[k]=-1;
		}
		int round=n-1;

		mark[c]=true;
		dist[c]=0;
		d_num[c]=num[c];
		int new_p=c;
		int ans1=1;

		while(round--){
			for(int l=0;l<E[new_p].size();l++){
				int t=E[new_p][l].next;
				int co=E[new_p][l].c;
				if(mark[t]==true){//
					if(t==d&&dist[t]==dist[new_p]+co){
						ans1++;
					}

					if(d_num[t]<d_num[new_p]+num[t]){//
						d_num[t]=d_num[new_p]+num[t];//
					}
					continue;
				}
				if(dist[t]==-1||(dist[t]>dist[new_p]+co)){
					dist[t]=dist[new_p]+co;
				}
			}
			int min = 10000000;
			int temp_last_p=new_p;
			for(int x=0;x<n;x++){
				if(mark[x]==true)continue;
				if(dist[x]==-1)continue;
				if(min>dist[x]){
					min=dist[x];
					new_p=x;
				}
			}

			mark[new_p]=true;
		}
		
		printf("%d %d\n",ans1,d_num[d]);

	
	}
	
	return 0;
}