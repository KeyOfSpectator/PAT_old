#include <stdio.h>
#include <stack>

int main(){	
	int n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			char data[100];
			bool flag_P = false;
			bool flag_A = false;
			bool flag_T = false;
			int id_P,id_A,id_T;
			scanf("%s",data);
			for(int i=0;data[i]!=0;i++){
				if(data[i]=='P'){id_P=i;flag_P=true;}
				if(data[i]=='A'){id_P=i;flag_A=true;}
			
			}
		
		}
	
	}

	return 0;
}