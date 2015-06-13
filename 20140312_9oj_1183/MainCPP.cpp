#include <stdio.h>


int power(int a,int k){
	int temp=a;
	while(k--){
		temp*=a;

	}
	return temp;
}
int main(){
	int n,m,i;
	while(scanf("%d",&n)!=EOF){
		m=n*n;
		i=0;
		int temp = n;
		while(temp/10>1){i++;temp/=10;}
		if(m%power(10,i)==n)printf("Yes!\n");
		else printf("No!\n");
	
	}

	return 0;
}