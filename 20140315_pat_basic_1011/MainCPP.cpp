#include <stdio.h>

int main(){
	int n,case_num;
	long a,b,c;
	while(scanf("%d",&n)!=EOF){
		case_num=0;
		while(n--){
			case_num++;
			scanf("%ld%ld%ld",&a,&b,&c);
			//(c<a||c<b)||
			if(b>(c-a))
				printf("Case #%d: true\n",case_num);
			else 
				printf("Case #%d: false\n",case_num);
		
		
		}
	
	
	}

}