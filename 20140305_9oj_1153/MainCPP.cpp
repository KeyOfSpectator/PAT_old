#include <stdio.h>
#include <stack>
using namespace std;


int main(){
	stack<int> s;
	char str[100];
	char output[100];
	while(scanf("%s",str)!=EOF){
		int i;
		for(i=0;str[i]!=0;i++){
			output[i]=' ';
			if(str[i]=='('){
				s.push(i);
			}
			if(str[i]==')'){
				if(s.empty()){
				
					output[i]='?';
				}
				else
					s.pop();
			}
		}
		output[i]=0;

		while(!s.empty()){
			output[s.top()]='$';
			s.pop();
		}
		puts(str);
		puts(output);
	//printf("\n");
	}
	return 0;
}	