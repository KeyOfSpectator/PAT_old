#include <stdio.h>
#include <algorithm>
using namespace std;

int list[101];
int d[101];
int d_left[101];
int d_right[101];

int max(int x,int y){
	return x>y? x: y;
}

int main(){
	int n;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );

	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&list[i]);
		}


	//	for(int j=0;j<n;j++){//
			for(int p=0;p<n;p++){
				d_left[p]=0;
				d_right[p]=0;
			}
			for(int k=n-1;k>=0;k--){
				int tmax=1;
				for(int l=n-1;l>k;l--){//
					if(list[l]<list[k]){
						tmax=max(tmax,d_right[l]+1);
						
					}
				
				}
				d_right[k]=tmax;
			}
			
			for(int q=0;q<n;q++){

				d_left[q]=0;
			}

			for(int x=0;x<n;x++){
				int tmax2=1;
				for(int m=0;m<x;m++){//
					if(list[m]<list[x]){
						tmax2=max(tmax2,d_left[m]+1);
					}
				
				}
				d_left[x]=tmax2;
			
			}
			//sort(d_left,d_left+n);
			//sort(d_right,d_right+n);


			for(int j=0;j<n;j++)
			d[j]=d_left[j]+d_right[j]-1;
			sort(d,d+n);
			printf("%d\n",d[n-1]);
			
		}

			
	
	//}
	return 0;
}