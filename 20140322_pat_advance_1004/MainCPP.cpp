#include <stdio.h>
#include <vector>
using namespace std;

struct Node{
	//int next;
	int id;
};

vector <Node> E[101];
int num[101];
int level[101];
bool mark[101];

void DFS(int node,int l){
	if(mark[node]==true)return;
	if(num[node]==0){level[l]++;return;}
	else {
		for(int k=0;k<E[node].size();k++){
			mark[node]=true;
			DFS(E[node][k].id,l+1);
			mark[node]=false;
		}
	
	}
}

int main(){
	int n,m;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&m)!=EOF){

		for(int j=0;j<100;j++){
			num[j]=0;
			level[j]=0;
			E[j].clear();
			mark[j]=false;
		}//init

		for(int i=0;i<m;i++){
			int tmp_id_a,tmp_id_b;
			scanf("%d",&tmp_id_a);
			Node tmp_node;
			tmp_node.id=tmp_id_a;

			int n_child;
			scanf("%d",&n_child);

			num[tmp_id_a]=n_child;

			while(n_child--){
				scanf("%d",&tmp_id_b);
				tmp_node.id=tmp_id_b;
				E[tmp_id_a].push_back(tmp_node);
				tmp_node.id=tmp_id_a;
				E[tmp_id_b].push_back(tmp_node);
			}
			
		}

		//mark[1]=true;
		DFS(1,0);//level->0~N
		
		int len=0;
		for(int p=0;p<100;p++){
			if(level[p]!=0){
				len = p;
			}
		}
		for(int q=0;q<len;q++){
			printf("%d ",level[q]);
		}
			printf("%d",level[len]);
		printf("\n");
	}
	return 0;
}