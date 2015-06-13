#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;
//using namespace std;

struct BigInterger{
	int digit[1000];
	int size;
	void init(){
		for(int i=0;i<1000;i++){
			digit[i]=0;
		}
		size=0;
	}

	void set(char str[]){
		int L=strlen(str);
		init();
		for(int j=L-1,k=0,l=0,m=1;j>=0;j--){
			l+=(str[j]-'0')*m;
			k++;
			m*=10;
			if(k==4||j==0){
				k=0;
				
				m=1;
				digit[size++]=l;
				l=0;
			}
		}
	}

	void output(){
		for(int x=size-1;x>=0;x--){
			if(x!=size-1)
				printf("%04d",digit[x]);
			else
				printf("%d",digit[x]);
		}
		printf("\n");
	}

	BigInterger operator * (const int &A) const{
		BigInterger rec;
		rec.init();
		int carry=0;
		for(int y=0;y<size;y++){
			int t=digit[y]*A+carry;
			carry = t/10000;
			t%=10000;
			rec.digit[rec.size++]=t;
		
		}
		if(carry!=0)
			rec.digit[rec.size++]=carry;
		return rec;
	}

}a;

char str[1001];
int main(){
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%s",str)!=EOF){
	//	a.set(str);
	//	a.output();
		int n;
		n=atoi(str);
		a.set(str);
		for(int u=1;u<=n-1;u++){
			a=a*u;
		
		}
		a.output();

	}

	return 0;
}