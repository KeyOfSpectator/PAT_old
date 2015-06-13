#include <stdio.h>


int main(){
	int a[10],b[10];
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i=0,j=0;
		while(n>=1){
			a[i++]=n%10;
			n/=10;
		}
		while(m>=1){
			b[j++]=m%10;
			m/=10;
		}
		int ans=0;
		for(int k=0;k<i;k++)
			for(int l=0;l<j;l++)
				ans+=a[k]*b[l];
		printf("%d\n",ans);
	}

	return 0;
}
