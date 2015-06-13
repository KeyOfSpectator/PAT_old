#include <stdio.h>


int power(int a,int b){
	int tmp=a;
	for(int j=1;j<b;j++){
		tmp*=a;
	}
	return tmp;
}
int main(){
	int n,level;
	int data[1000];
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&data[i]);
		}
		scanf("%d",&level);
		int left = power(2,(level-1));
		//printf("%d\n",left);
		int right = power(2,(level))-1;

		if(data[left]!=NULL&&right<=n){
			for(int k=left;k<right;k++){
				printf("%d ",data[k]);
			
			}
			printf("%d\n",data[right]);
		}else if(data[left]!=NULL&&right>n){
			for(int k=left;k<n;k++){
				printf("%d ",data[k]);
			
			}
			printf("%d\n",data[n]);
		}else
			printf("EMPTY\n");
	
	}
	return 0;
}