#include <stdio.h>

int main()
{
	int a,b;
	int buf[100];
	int i=0;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
	//	scanf("%d",&b);
		buf[i]=a+b;
		i++;
	
	}//end while
	for(int j=0;j<i;j++){
	printf("%d ",buf[j]);
	
	}
		printf("\n");
		return 0;
}//end main