#include <stdio.h>
#include <string.h>

struct bigInterger{
	int digit[1000];
	int size;
	void init(){
		for(int i=0;i<1000;i++){
			digit[i]=0;
		
		}
		size=0;
	
	}
		

	void set(char str[]){
		init();
		int L=strlen(str);
		for(int j=L-1,k=0,l=0,m=1;j>=0;j--){
			l+=(str[j]-'0')*m;
			m*=10;
			k++;
			if(k==4||j==0){
				digit[size++]=l;

				k=0;
				l=0;
				m=1;
			}
		
		}
	}

	void output(){
		for(int x=size-1;x>=0;x--){
			if(x!=size-1)printf("%04d",digit[x]);
			else printf("%d",digit[x]);
		}

		printf("\n");
	
	}

	bigInterger operator + (const bigInterger &A)const{
		bigInterger rec;
		rec.init();
		int carry=0;
		for(int y=0;y<size||y<A.size;y++){
			int tmp=digit[y]+A.digit[y]+carry;
			carry = tmp/10000;
			tmp%=10000;
			rec.digit[rec.size++]=tmp;
		}
		if(carry!=0)
			rec.digit[rec.size++]=carry;
		return rec;

	}
}a,b,c;
char str1[1001],str2[1001];
int main(){
	freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%s%s",str1,str2)!=EOF){
		a.set(str1);b.set(str2);
		c=a+b;
		c.output();
	}
	return 0;
}
