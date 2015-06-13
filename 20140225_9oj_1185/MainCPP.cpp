#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int buf[1000];
	while(scanf("%d",&n)!=EOF){
	
		
			for(int i=0;i<n;i++){
				scanf("%d",&buf[i]);
			}//end for
			sort(buf,buf+n);
		if(n==1)
		{
			printf("%d\n",buf[0]);
			printf("-1\n");
		}//end if
		else{
			printf("%d\n",buf[n-1]);
			for(int j=0;j<n-2;j++){
				printf("%d ",buf[j]);
			}//end for
			printf("%d\n",buf[n-2]);
		}//end else
	}//end while
	return 0;
}//end main