#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int char_to_i(char c){
	if(c>='0'&&c<='9')return c-'0';
	else if(c>='a'&&c<='z')return c-'a'+10;
}

char i_to_char(long i){
	return i+'0';
}

char* changetoD(char* str,int r){
	int L = strlen(str);
	char  rec[30];
	int id=0;
	long t=0,carry=0;
	int m=1;
	for(int j=L-1;j>=0;j--){
		t += char_to_i(str[j])*m;
		//carry = t/10;
		//rec[id++]=t%10;
		m*=r;	
	}
	do{
		rec[id++]=i_to_char(t%10);
		t/=10;
	}while(t!=0);
	rec[id]=0;
	return rec;// ·´µÄ
}


	char d_a[30];
	char d_b[30];
int main(){
	char a[10];
	char b[10];
	int c;
	int d;

	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );


	while(scanf("%s%s%d%d",a,b,c,d)!=EOF){

	int flag = c;
	int radix =d;
	]

	if(flag == 1){
		
		strcpy(d_a , changetoD(a,radix));
		bool fg=false;
		for(int i=2;i<100;i++){
			strcpy(d_b,changetoD(b,i));
			if(strcmp(d_a,d_b)==0){
				printf("%d\n",i);
				fg = true;
				break;
			}

		}
		if(!fg)
		printf("Impossible\n");
	}


	else{
		strcpy(d_b , changetoD(b,radix));
		bool fg2=false;
		for(int k=2;k<100;k++){
			strcpy(d_a  , changetoD(a,k));
			if(strcmp(d_a,d_b)==0){
				printf("%d\n",k);
				fg2 = true;
				break;
			}

		}
		if(!fg2)
		printf("Impossible\n");
		
	}

	}

	return 0;
}