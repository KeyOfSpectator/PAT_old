#include <stdio.h>

int prime[100001];
bool mark[100001];
int prime_id;

int cnt[100001];//质因数指数 

void init(){
	prime_id=0;
	cnt[0]=cnt[1]=0;
	for(int i=2;i<100001;i++){
		cnt[i]=0;
		if(mark[i]==true)continue;
		mark[i]=true;
		prime[prime_id++]=i;
		if(i>1000)break;
		for(int j=i*i;j<100001;j+=i){
			mark[j]=true;
		}
	}

}

int num;


int main(){
	init();
	int N;
	while(scanf("%d",&N)!=EOF){
		while(N--){
		
			for(int x=0;x<100001;x++){
			cnt[x]=0;
			}

			scanf("%d",&num);


				if(num==1){
				printf("1\n");
				continue;
			
			}

			int t=num;

			int ans=0;
			for(int k=0;k<prime_id;k++){
				if(t==1)break;
				
				while(t%prime[k]==0){
					t/=prime[k];
					cnt[k]++;
				}
				if(cnt[k]!=0&&ans!=0)ans*=cnt[k]+1;
				else if(cnt[k]!=0&&ans==0)ans=cnt[k]+1;
				
			
			}
			//int ans=0;
			if(t!=1&&ans!=0){
				printf("%d\n",ans*2);
			}
			else if(ans==0){
				printf("1\n");
			}
			else 
				printf("%d\n",ans);
		
		
		
		}


	
	}
	return 0;
}