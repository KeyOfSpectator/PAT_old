#include <stdio.h>
#include <math.h>
#define MAX 100000

bool IsPrime(int n){
	bool flag= true;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){flag=false;break;}
	}
	return flag;
}

int main(){
	int k;
	while(scanf("%d",&k)!=EOF){
		//int num[MAX];
		int buf[10001];
		int id=1,i=2;

		while(id<=k){
			//num[i]=0;
			if(IsPrime(i)){
				//num[i]=1;
				buf[id++]=i;
			}
		/*	int temp=i*i;
			while(temp<MAX){
				num[temp]=1;
				temp+=i;
			}
				*/
			i++;

	
		}
		printf("%d\n",buf[k]);
	
	}
	return 0;
}