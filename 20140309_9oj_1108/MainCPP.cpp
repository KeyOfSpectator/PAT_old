#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	stack<int>	num;
	int n,elem_num;
	char tmp[10];
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		while(!num.empty())num.pop();
		for(int i=0;i<n;i++){
			//getchar();
			scanf("%s",tmp);
			//if(tmp==' '){
			//i--;
			//continue;
			//}
			if(tmp[0]=='A'){
				if(num.empty()){
					printf("E\n");
				}else{
				printf("%d\n",num.top());
				}
			}else if(tmp[0]=='P'){
				scanf("%d",&elem_num);
				num.push(elem_num);
			}else if(tmp[0] =='O' ){
				if(!num.empty())
				num.pop();
			}
		
		
		}
		printf("\n");
	}
return 0;
}