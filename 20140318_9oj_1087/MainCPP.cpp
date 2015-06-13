#include <stdio.h>

int prime[100001];
bool mark[100001];
int prime_id;
void init(){
	prime_id=0;
	for(int i=2;i<100001;i++){
		if(mark[i]==true)continue;
		mark[i]=true;
		prime[prime_id]=i;
		if(i>1000)break;
		for(int j=i*i;j<100001;j+=i){
			mark[j]=true;
		}
	}

}

int num;
int cnt[100001];//质因数指数 

int main(){
	init();
	int N;
	while(scanf("%d",&N)!=EOF){
		while(N--){
			scanf("%d",&num);
			int t=num;

			int ans=0;
			for(int k=0;k<prime_id;k++){
				if(t==1)break;
				
				while(t%prime[k]==0){
					t/=prime[k];
					cnt[k]++;
				}
				if(cnt[k]!=0&&ans!=0)ans*=cnt[k];
				else if(cnt[k]!=0&&ans==0)ans=cnt[k];
				
			
			}
			//int ans=0;
			if(t!=1){
				printf("%d\n",ans+2);
			}
			else 
				printf("%d\n",ans+1);
		
		
		
		}


	
	}
	return 0;
}