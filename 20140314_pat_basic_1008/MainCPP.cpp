/*#include <stdio.h>

int main(){
	int n,m;
	int data[200];
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&data[i+m]);
		
		}
		for(int j=0;j<m;j++){
			data[j]=data[j+n];
		}
		for(int k=0;k<n-1;k++)
			printf("%d ",data[k]);
		printf("%d\n",data[n-1]);
	
	}
	return 0;
}
*/

#include <stdio.h>

int main(){
	int n,m;
	int data[101];
	while(scanf("%d%d",&n,&m)!=EOF){
		m=(m+n)%n;
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);
		}
		int count=1;
		for(int j=n-m;j<n;j++){
			if(count<n)
			printf("%d ",data[j]);
			else
			printf("%d\n",data[j]);
			count++;

		}
		for(int k=0;k<n-m;k++){
			if(count<n)
			printf("%d ",data[k]);
			else
			printf("%d\n",data[k]);
			count++;

		}
	
	}
	return 0;
}