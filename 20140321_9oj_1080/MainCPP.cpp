#include <stdio.h>
#include <string.h>

struct BigInterger{
	int digit[1000];
	int size;

	void init(){
		for(int i=0;i<1000;i++){
			digit[i]=0;
		}
		size=0;
	}

	void set(char str[],int a_x){
		init();
		int L=strlen(str);
		for(int j=L-1,l=0,k=0,m=1;j>=0;j--){
			if(str[j]>='0'&&str[j]<='9')l+=(str[j]-'0')*m;
			else if(str[j]>='A'&&str[j]<='Z')l+=(str[j]-'A'+10)*m;

			k++;
			m*=a_x;

			if(k==4||j==0){
				digit[size++]=l;
				k=0;m=1;l=0;
			}
		}
	}

	void output(){
		for(int n=size-1;n>=0;n--){
			if(n!=size-1)printf("%04d",digit[n]);
			else printf("%d",digit[n]);
		}
		printf("\n");
	}

	BigInterger operator * (const int &A)const{
		BigInterger rec;
		rec.init();
		int carry = 0;

		for(int mu=0;mu<size;mu++){
			int tmp_mu=digit[mu]*A+carry;
			carry = tmp_mu/10000;
			tmp_mu%=10000;
			rec.digit[rec.size++]=tmp_mu;
		}
		if(carry!=0){
			rec.digit[rec.size++]=carry;
		}
		return rec;
	}

	BigInterger operator / (const int &A)const{
		BigInterger rec_d;
		rec_d.init();
		int remainder=0;
		for(int di=size-1;di>=0;di--){
			int t_d=(remainder*10000+digit[di])/A;
			int r_d=(remainder*10000+digit[di])%A;
			remainder = r_d;
			rec_d.digit[rec_d.size++]=t_d;
		}
		rec_d.size=0;
		for(int si=0;si<1000;si++){
			if(rec_d.digit[si]!=0)
			rec_d.size=si+1;
		}
		/*if(rec_d.digit[0]==0&&rec_d.size==0)
			rec_d.size=0;
		else
		rec_d.size++;
		*/
		//if(rec_d.digit[0]==0&&rec_d.size==0)

		return rec_d;
		
	
	}

	int operator % (const int &A)const{
		
		int remainder_r=0;
		for(int re=size-1;re>=0;re--){
			int t_re = (remainder_r+digit[re])/A;
			int r_re = (remainder_r+digit[re])%A;
			remainder_r= r_re;
		}
		return remainder_r;
	
	}
}big;

char str[10001];
int ans[10001];
char ans_char[10001];
int id;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		scanf("%s",str);
		big.set(str,a);
		id=0;
		do{
			int rem = big%b;
			if(rem>=0&&rem<=9){
				ans_char[id++]=rem+'0';
			}else if(rem>=10&&rem<=36)
				ans_char[id]=rem-10+'a';
			//ans_char[id++]=rem;
			big = big/b;
		
		}while(big.size!=0);
		for(int an=id-1;an>=0;an--){
			printf("%c",ans_char[an]);
		
		}
		printf("\n");
	}

	return 0;
}