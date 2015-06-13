#include <stdio.h>
	int n,m;

	void caculate(int m,int &ans){
		if(2*m<=n){//×óº¢×Ó
			ans++;
			caculate( 2*m,ans);
		}
		if(2*m+1<=n){//ÓÒº¢×Ó
			ans++;
			caculate((2*m+1),ans);
		}
		else return;
	}

int main(){

	while(scanf("%d%d",&m,&n)!=EOF){
		if(n==0&&m==0)break;
		int ans = 1;

		int left,right;

		left = m*2;
		right = m*2+1;

		while(right<=n){
			ans+=(right-left+1);
			left=left*2;
			right = right*2+1;
		}
		if(left<=n){
			ans+=n-left+1;
		}

		//caculate(m,ans);
		printf("%d\n",ans);
	
	
	}
	
	return 0;
}