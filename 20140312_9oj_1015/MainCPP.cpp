#include <stdio.h>


int power(int a,int k){
	int temp = a;
	while(k--){
		temp*=a;
	}
	return temp;

}
int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		if(n==0&&m==0)break;
		int tmp_n,tmp_m;
		tmp_n=n%power(10,k-1);
		tmp_m=m%power(10,k-1);

		if(tmp_n==tmp_m)printf("-1\n");
		else printf("%d\n",n+m);
	
	}

	return 0;
}