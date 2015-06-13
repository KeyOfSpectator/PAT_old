#include <stdio.h>
#include <algorithm>
using namespace std;
int main_2(){
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		sort(buf,buf+n);
		for(int j=0;j<n;j++){
			printf("%d ",buf[j]);
		}
		printf("\n");


	}
	return 0;
}