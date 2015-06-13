#include <stdio.h>

int main(){
	int a,b,c;

	while(scanf("%d%d",&a,&b)!=EOF){
			c=a*b;
		while(a!=0&&b!=0){
			a>b?a=a%b:b=b%a;
		}
		if(a==0&&b==0)c=0;
		else
		a==0?c/=b:c/=a;
	printf("%d\n",c);
	}
	

	return 0;
}