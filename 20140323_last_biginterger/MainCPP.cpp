#include <stdio.h>

struct BigInterger{
	int digit[100];
	int size;

	void init(){
		size=0;
		for(int i=0;i<100;i++){
			digit[i]=0;
		}
	}

	void set(char str[]){
		init();
		int L = strlen(str);
		int k=0,l=0,m=1;
		for(int i2=0;i2<L;i2++){
			k+=(str[i2]-'0')*m;
			l++;
			m*=10;
			
			if(l==4||i2==0){
				digit[size++]=k;
				k=0;
				l=0;
				m=1;
			}
		
		}
	}

	BigInterger operator +(const BigInterger &A)const{
		BigInterger rec;
		rec.init();
		int carry = 0;
		for(int i1=0;i1<size||i1<A.size;i1++){
			int tmp = digit[i1]+A.digit[i1]+carry;
			carry = tmp/10000;
			tmp %= tmp/10000;
			rec.digit[rec.size++]=tmp;
		}
		if(carry!=0){
			rec.digit[rec.size++]=carry;
		}
		return rec;
	}
	

	void output(){
		for(int i3=size-1;i3>=0;i3--){
			if(i3==size-1){
				printf("%d",digit[i3]);
			}else
			printf("%04d",digit[i3]);
		}
		printf("\n");
	}

	BigInterger operator * (const int &A)const{
		BigInterger rec2;
		rec2.init();
		int carry2=0;
		
		for(int i4=0;i4<size;i4++){
			int tmp2=digit[i4]*A+carry2;
			carry2 = tmp2/10000;
			tmp2%=10000;
			
			rec2.digit[rec2.size++]=tmp2;
		
		}
		if(carry !=0){
			rec2.digit[rec2.size++]=carry;
		}
		return rec2;
		
	}
	BigInterger operator / (const int &A)const{
		BigInterger rec3;
		rec3.init();
		int remainder=0;
		for(int i5=size-1;i5>=0;i5--){
			int tmp3 = (digit[i5]+remainder)/A;
			int r = (digit[i5]+remainder)%A;
			remainder = r*10000;
			rec3.digit[i5]=tmp3;
		}

		rec3.size=0;
		for(int i6=0;i6<100;i6++){
			if(rec3.digit[i6]!=0)
				rec3.size=i6;
		
		}
		rec3.size++;
		return rec3;


		
	}
	int operator % (const int &A)const{
		int remainder = 0;
		for(int i7=size-1;i7>=0;i7--){
			int tmp3 = digit[i7]/A;
			int r3 = digit[i7]%A;
			remainder = r3;

		}
		return remainder;
		
	}
}a,b,c;

int main(){

	return 0;
}