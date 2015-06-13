#include <stdio.h>
int main_1 (){
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
	
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}

//converse!

//for(int j=n-1;j>=0;j--){
		for(int j=0;j<n;j++){
//for(int k=n-1;k>=0+j+1;k--){
			for(int k=0;k<n-j-1;k++){	//
//for(int k=n-j-1;k>0;k--){
				if(buf[n-k-2]>buf[n-k-1]){
					int tmp;
					tmp = buf[n-k-2];
					buf[n-k-2] = buf[n-k-1];
					buf[n-k-1] = tmp;
				}

			}
		}

		for(int m = 0;m<n;m++){
			printf("%d ",buf[m]);
		}
		printf("\n");
	}

	return 0;
}