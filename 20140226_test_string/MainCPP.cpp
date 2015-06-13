#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
	char s2[10]="string2";
string s1("this is a test string");
int cmp;

cmp = s1<s2;
//cmp = strcmp(s2,s1);
cout<<cmp<<endl;
//cin>>s1;
cin.get(s2,5);
cout<<s2<<endl;
cout<<s1<<endl;
//printf("%s",s1);
return 0;
}
