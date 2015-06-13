#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//using namespace std;

char* execute(char*  n){
	if(strlen(n)<=1)return n;
	else{
		int ans=0;
		for(int i=0;i<strlen(n);i++){
			ans+=(n[i]-'0');
		}
		//char temp[100];
		int j=0;
		while(ans>0){
			n[j++]=ans%10+'0';
			ans/=10;
		}
		n[j]=0;
		return execute(n);
	}

}

int main(){
	char data[100];
	while(scanf("%s",data)!=EOF){
		if(data[0]=='0'&&strlen(data)==1)break;
		char *ans1;
		ans1= execute(data);
		printf("%d\n",ans1[0]-'0');
		
	}
	return 0;
}