#include <stdio.h>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	int r,c;
	r = (m-2*n)/2;
	c = n-r;
	if( r >= 0 &&  c>=0)
		printf("%d %d" , c , r);
	else
		printf("No answer");

	return 0;
}