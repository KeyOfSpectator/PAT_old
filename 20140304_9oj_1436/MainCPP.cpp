#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

//#define (long long) _int64
//#define lld l64d

int  data[600];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int N;
	int   L;
	while(scanf("%d%d",&L,&N)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%d",&data[i]);
		}			
		sort(data,data+N,cmp);

		int current_left_length=L;
		int count = 0;
		for(int j=0;j<N;j++){
			if(current_left_length>=data[j]){
				count++;
				current_left_length-=data[j];
			}
		}
		if(current_left_length!=0)
			printf("impossible\n");
		else 
			printf("%d\n",count);
	}

return 0;}