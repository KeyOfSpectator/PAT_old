#include <stdio.h>

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		//if(a==0&&b==0)break;
		while(a!=0&&b!=0){
			if(a>b){
				a=a%b;
			}
			else b=b%a;
		}
		if(a==0)printf("%d\n",b);
		else if(b==0)printf("%d\n",a);
		else printf("0\n");
	}
	return 0;
}