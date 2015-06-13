#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;



	stack<double> num;
	stack<char> oprt;
	double temp_double;


int import_num(int i,char str[]){
		int j,k;
		char temp_char[220];
		for(j=i,k=0;str[j]!=' '&&j<strlen(str);j++,k++){
					temp_char[k]=str[j];
					
				}// end for
					temp_double = strtod(temp_char,NULL);
					num.push(temp_double);
	return j;
}



int main(){
	
		char str[220];
	//while(scanf("%s",str)!=EOF){
	while(gets(str)){
		if(str[0]=='0'&&strlen(str)==1 )break;

		int i=0;
		
		double a,b;
		for(;i<strlen(str);i++)	{
			
			if(str[i]==' ')continue;
			else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
				if(str[i]=='+'||str[i]=='-'){
				oprt.push(str[i]);
				}else if(str[i]=='*'){
						i=import_num(i+2,str);
					
						a = num.top();
						num.pop();
						b=num.top();
						num.pop();
						num.push(a*b);

				}// "*"
				else if(str[i]=='/'){
						i=import_num(i+2,str);
					
						a = num.top();
						num.pop();
						b=num.top();
						num.pop();
						num.push(b/a);
				}// "/"
			}
			else{
				i=import_num(i,str);
			}//end else
		
		}//end for
		while(!oprt.empty()){
			if(oprt.top()=='+'){
				
				oprt.pop();

				if(!oprt.empty()&&oprt.top()=='-'){
				double tmp = num.top();
				num.pop();

				oprt.pop();
				a = num.top();
				num.pop();
				b=num.top();
				num.pop();
				num.push(b-a);

				oprt.push('+');
				num.push(tmp);
				}// - +
				
				else{
				a = num.top();
				num.pop();
				b=num.top();
				num.pop();
				num.push(a+b);
				}
			}// +
			else if(oprt.top()=='-'){
				oprt.pop();
				a = num.top();
				num.pop();
				b=num.top();
				num.pop();
				num.push(b-a);
			}// -
		
		}// end while
			
			printf("%.2lf\n",num.top());
			while(!num.empty())num.pop();
		//	&str = new char [];
	}//end while


return 0;}