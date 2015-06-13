#include <stdio.h>

//using namespace std;

#define MAX 10000001

int Tree[MAX];

int findroot(int x){
	if(Tree[x]==-1)return x;
	else{
		int tmp=findroot(Tree[x]);
		 Tree[x]=tmp;
		return tmp;
	
	}

}
	int sum[MAX];
int main(){
	int N;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt", "r", stdin );
	while(scanf("%d",&N)!=EOF){
		//int* sum = new int[N];
	
		for(int i=1;i<MAX;i++){
			
			Tree[i]=-1;
			sum[i]=1;
		}
		
		while(N--){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b){
				Tree[a]=b;
				sum[b]+=sum[a];//根记录数量
			}


		}
		int ans=1;
		for(int j=1;j<=MAX;j++){
			if(Tree[j]==-1&&sum[j]>ans)ans=sum[j];
		}
		printf("%d\n",ans);

	
	}

	return 0;
}