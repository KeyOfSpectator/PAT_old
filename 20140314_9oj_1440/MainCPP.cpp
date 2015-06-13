#include <stdio.h>
#include <math.h>
bool IsPrime(int n){
	bool flag = true;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			flag = false;
			break;
		}
	
	}
	return flag;
}

int main(){
	int k;
	//int num[32769];
	while(scanf("%d",&k)!=EOF){
		if(k==0)break;
		int ans =0;
		for(int i=2;i<=k/2;i++){
			if(IsPrime(i)&&IsPrime(k-i))
				ans++;
		}
		printf("%d\n",ans);
	
	}
	
	
	
	return 0;


}