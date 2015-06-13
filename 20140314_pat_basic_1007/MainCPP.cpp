#include <stdio.h>
#include <math.h>

bool IsPrime(int i){
	bool flag=true;
	for(int j=2;j<=sqrt(i);j++){
		if(i%j==0){flag=false;break;}
	}
	return flag;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		for(int i=2;i<=n-2;i++){
			if(IsPrime(i)&&IsPrime(i+2))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;

}