#include <stdio.h>

int main(){
	int n,m;
	int data[101];
	int find[101];
	bool ans[101];

	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);
			ans[i]=false;
		}
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&find[j]);
		}
		
		for(int l=0;l<m;l++)
		for(int k=0;k<n;k++){
			if(data[k]==find[l]) ans[l]=true;
		}
		
		for(int o=0;o<m;o++){
			if(ans[o]==true)
				printf("YES\n");
			else
				printf("NO\n");
		}
	
	}
	return 0;
}