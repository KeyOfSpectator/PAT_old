#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
struct E{
	int next;
	long long c;

};

long long Pow(int n)
{
        if(n==1)
                return 2;
        else if(n==0)
                return 1;
        if((n&1)==1)
                return 2*Pow(n-1)%100000;
        else
        {
                long long t=Pow(n>>1)%100000;
                return t*t%100000;
        }
}

int mark[101];
long long dist[101];
vector <E> e[101];
int main(){
	int n,m;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int p=0;p<n;p++)e[p].clear();
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			E tmp;
			tmp.next=b;
			tmp.c=Pow(i);//
			e[a].push_back(tmp);
			tmp.next=a;
			e[b].push_back(tmp);

		}
		for(int j=0;j<n;j++){
			mark[j]=false;
			dist[j]=-1;
		
		}
		mark[0]=true;
		int new_p=0;
		dist[new_p]=0;
		for(int k=0;k<n-1;k++){//n-1
			for(int edg=0;edg<e[new_p].size();edg++){
				int t=e[new_p][edg].next;
				long long c=e[new_p][edg].c;
				if(mark[t]==true)continue;
				if(dist[t]==-1||dist[t]>dist[new_p]+c){
					dist[t]=dist[new_p]+c;

				
				}
			
			}
			int min=10000000;
			for(int l=0;l<n;l++){
				if(mark[l]==true)continue;
				if(dist[l]==-1)continue;
				if(dist[l]<min){
					min=dist[l];
					new_p=l;
				
				}
			
			}
			mark[new_p]=true;
		}
	
		for(int x=1;x<n;x++){
			//if(dist[x])
			printf("%lld\n",dist[x]);
		}
		//printf("%d");
	}

	return 0;
}