#include <stdio.h>
#include <vector>
using namespace std;

struct Node{
	int next;
	int c;

};

vector <Node> E[501];
int num[501];
int dist[501];
bool mark[501];
int max_r;
int ans1;
int ans2;
int s,e;

void DFS(int x,int num_sum,int dist_sum){
	for(int l=0;l<E[x].size();l++){
		int t=E[x][l].next;
		int co=E[x][l].c;


		if(t==e){
			if(max_r>dist_sum+co){
				ans1=1;
				ans2=(num_sum+num[t]);//
				max_r=dist_sum+co;
				
			}else if(max_r==dist_sum+co){
				ans1++;
				ans2=ans2<(num_sum+num[t])?(num_sum+num[t]):ans2;//
			}
			continue ;
		}

		if(mark[t]==true){
				continue;
		}


		mark[x]=true;
		if((dist_sum+co)<max_r)
		DFS(t,num_sum+num[t],dist_sum+co);
		mark[x]=false;
		
	}
	return;
}

int main(){
	int n,m;
//	freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d%d%d",&n,&m,&s,&e)!=EOF){
		ans1=ans2=0;
		max_r=10000000;
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
									//Ë«Ïò
			tmp.next=t_c1;
			E[t_c2].push_back(tmp);
		
		}	
			
		for(int l=0;l<n;l++){
			dist[l]=-1;
			mark[l]=false;
		}
			dist[s]=0;
			mark[s]=true;
			DFS(s,num[s],0);

			printf("%d %d\n",ans1,ans2);
	
	}

	return 0;
}