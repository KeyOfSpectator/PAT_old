#include <stdio.h>
#include <math.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n<=1){printf("no\n");continue;}
		//if(n==1){printf("yes\n");continue;}
		bool flag = true;
		for(int i=2;i<=sqrt(n);i++)
			if(n%i==0){flag = false;printf("no\n");break;}
		if(flag)printf("yes\n");
	
	}
	return 0;
}