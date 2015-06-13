#include <stdio.h>
#include <math.h>

bool mark[100001];
int prime[100001];
int prime_id;

void init(){
	prime_id=0;
	for(int i=2;i<100000;i++){
		if(mark[i]==true)continue;
		prime[prime_id++]=i;
	
		if(i>1000)continue;

		for(int j=i*i;j<100000;j+=i){//
			mark[j]=true;
		}
	
	}

}


int main(){
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
	
		int ans=0;
		for(int k=0;k<prime_id;k++){
			if(n==1)break;
			while(n%prime[k]==0){
				n/=prime[k];
				ans++;
			}
		
		}

		if(n!=1)printf("%d\n",ans+1);
		///accept
		else printf("%d\n",ans);
	}
	return 0;
}