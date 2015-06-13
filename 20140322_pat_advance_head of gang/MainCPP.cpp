#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int Tree[1001];
char name[1001][4];
int sum[1001];
int weight[1001];

struct Gang{
	int boss_id;
	int total_weight;
	int root_id;
	int member_sum;
	int Max_weight;
	bool operator < (const Gang &A)const{
		for(int u=0;u<4;u++){
			if(name[boss_id][u] < name[A.boss_id][u])
				return 1;
			else if(name[boss_id][u] > name[A.boss_id][u])
				return 0;
		}
		return strlen(name[boss_id])>strlen(name[A.boss_id]);
	}
}gang[1001];

int findroot(int x){
	if(Tree[x]==-1)return x;
	else {
		int tmp = findroot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

int get_id(char* name_char, int &id){
	bool flag =false;
	for(int j=0;j<id;j++){
		if(strcmp(name_char,name[j])==0){return j;flag = true;break;}
		
	}
	if(!flag){
		strcpy(name[id],name_char);
		name[id][3]='\0';
		id++;
	}
	return id-1;

}

int main(){
	int n,k_weight;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&k_weight)!=EOF){
		for(int i=0;i<=1000;i++){
			Tree[i]=-1;
			sum[i]=1;
			weight[i]=0;		
		}
		int id=0;
		while(n--){
			char a_name[3],b_name[3];
			int w;
			scanf("%s%s%d",a_name,b_name,&w);
			int a,b;
			a=get_id(a_name,id);
			b=get_id(b_name,id);

			weight[a]+=w;
			weight[b]+=w;

			a=findroot(a);
			b=findroot(b);

			if(a!=b){
				Tree[a]=b;
				sum[b]+=sum[a];
			
			}
				//weight[b]+=w;
				//if(a!=b)
				//weight[b]+=weight[a];
		}
		int gang_id=0;
		for(int k=0;k<id;k++){
			if(Tree[k]==-1){
				gang[gang_id].member_sum=sum[k];
				gang[gang_id].Max_weight=weight[k];
				gang[gang_id].boss_id=k;
				gang[gang_id].total_weight=0;
				gang[gang_id++].root_id=k;
				
			}
		}
		for(int l=0;l<id;l++){
			int temp_root=findroot(l);
			for(int x=0;x<gang_id;x++){
				if(temp_root==gang[x].root_id){
					gang[x].total_weight+=weight[l];
					if(gang[x].Max_weight<weight[l]){
						gang[x].boss_id=l;
						gang[x].Max_weight=weight[l];
					}
				}
			
			}
		}
		int gang_num=0;
		for(int v=0;v<gang_id;v++){
			if(gang[v].member_sum>2&&(gang[v].total_weight/2)>k_weight){
				gang_num++;
			}
		}

		sort(gang,gang+gang_id);
		printf("%d\n",gang_num);

		

		for(int y=0;y<gang_id;y++){
			if(gang[y].member_sum>2&&(gang[y].total_weight/2)>k_weight)
			printf("%s %d\n",name[gang[y].boss_id],gang[y].member_sum);
			
		
		}


	}


	return 0;
}