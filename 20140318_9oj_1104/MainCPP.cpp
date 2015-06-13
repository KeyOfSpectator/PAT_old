#include <stdio.h>

int prime[1001];
bool mark[1001];
int prime_id;

void init(){
	prime_id=0;
	for(int i=2;i<1001;i++){
		if(mark[i]==true)continue;
		prime[prime_id++]=i;
		mark[i]=true;
		for(int j=i*i;j<1001;j+=i){
			mark[j]=true;
		}
	}
}

int main(){	
	init();
	int n,a;
	int temp_n[1001];
	int temp_a[1001];
	while(scanf("%d%d",&n,&a)!=EOF){
		for(int k=0;k<prime_id;k++){
			temp_n[k]=0;
			temp_a[k]=0;
		}


		for(int l=0;l<prime_id;l++){
					int t=n;

			while(t!=0){

				temp_n[l]+=t/prime[l];
				t=t/prime[l];

			}
		}
		
		int min_k=1000000;
		for(int p_id=0;p_id<prime_id;p_id++){
			while(a!=1&&a%prime[p_id]==0){
				a/=prime[p_id];
				temp_a[p_id]++;
			}
			if(temp_a[p_id]==0)continue;
			int ans=temp_n[p_id]/temp_a[p_id];
			if(ans<min_k)min_k=ans;
			if(a==1)break;
		}
		printf("%d\n",min_k);
	}

	return 0;
}