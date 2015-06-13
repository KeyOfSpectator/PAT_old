#include <stdio.h>
#include <stack>
#include <string.h>
#include <stdlib.h>
using namespace std;


	double a,b;

double import_next_num(int &i,char* str){
		char tmp_str[100];
		int j,k=0;
		for(j=i;str[j]>='0'&&str[j]<='9';j++,k++){
			tmp_str[k] = str[j];

		}
		i=j-1;
		return strtod(tmp_str,NULL);
	}
int main(){
		char str[100];
	while(scanf("%s",str)!=EOF){
		//if(str[0]=='0'&&strlen(str)==1)break;

		stack<double> stack_num;
		stack<char> stack_oprt;
	
		
		while(!stack_num.empty())stack_num.pop();
		
		for(int i=0;i<strlen(str);i++){
			if(str[i]==' ')break;
			if(str[i]=='*'){
				i++;
				stack_num.push(import_next_num(i,str));

				a = stack_num.top();
				stack_num.pop();
				b = stack_num.top();
				stack_num.pop();

				stack_num.push(a*b);

			}else if(str[i]=='/'){
					i++;
				stack_num.push(import_next_num(i,str));

				a = stack_num.top();
				stack_num.pop();
				b = stack_num.top();
				stack_num.pop();

				stack_num.push(b/a);
			}else if(str[i]=='+'||str[i]=='-'){
				stack_oprt.push(str[i]);
			}else if(str[i]!=' '&&str[i]!=0){
				stack_num.push(import_next_num(i,str));
			}
		
		}
		while(!stack_oprt.empty()){
			char tmp_oprt = stack_oprt.top();
			double tmp_num=stack_num.top();
			stack_oprt.pop();
			stack_num.pop();
			if(!stack_oprt.empty()&&tmp_oprt=='+'&&stack_oprt.top()=='-'){
				stack_oprt.pop();
				a = stack_num.top();
				stack_num.pop();
				b = stack_num.top();
				stack_num.pop();

				stack_num.push(b-a+tmp_num);
			}else if(tmp_oprt=='-'){
				//stack_oprt.pop();
				a = stack_num.top();
				stack_num.pop();
				

				stack_num.push(a-tmp_num);
			}else if(tmp_oprt=='+'){
				//stack_oprt.pop();
				a = stack_num.top();
				stack_num.pop();
				

				stack_num.push(a+tmp_num);
			
			}
		}//end while
		printf("%.0lf\n",stack_num.top());
	}//end while

	return 0;
}