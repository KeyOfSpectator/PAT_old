#include <stdio.h>


void change(char* a){
	
	return ;
}

char change1(char * b){
	printf("%c\n",*(b+2));
	return *(b+2);
}

char *c;

int main(){
	char a[1001][1001];
	change(&a[0][0]);

	char * b = new char[1001*1001];
	b[2]='c';
	change1(b);

	c=new char[10*10];
	c[2]='x';
	change1(c);

	return 0;
}