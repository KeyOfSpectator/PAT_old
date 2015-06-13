#include <stdio.h>

int main(){
	//char a[10];
	int a;
	int b;
	int ans[30];
	int id;
	while(scanf("%d%d",&a,&b)!=EOF){
		id=0;
		int tmp = a;
		do{
			ans[id++]=tmp%b;
			tmp/=b;

		}while(tmp!=0);
		
		bool mark=true;
		for(int i=0;i<id/2;i++){
			if(ans[i]!=ans[id-i-1]){
				mark=false;
				break;
			}
		}
		if(mark)printf("Yes\n");
		else printf("No\n");

		for(int j=id-1;j>0;j--){
			printf("%d ",ans[j]);
		}
			printf("%d\n",ans[0]);
	}
	return 0;
}