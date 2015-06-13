#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a,char b){
	//int tmp = strcmp(a,b);
	//return tmp<0;
	return a<b;

}//end cmp

int main(){
char data[200];
int length;
while(cin>>data){

length = strlen(data);
sort(data,data+length,cmp);
for(int i=0;i<length;i++){
cout<<data[i];
}
cout<<endl;
}
return 0;
}//end main