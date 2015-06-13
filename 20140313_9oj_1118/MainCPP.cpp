#include <stdio.h>

long change(char* data,int a){
	long ans=0;
	for(int j=0;data[j]!=0;j++)
	{
		if(data[j]>='0'&&data[j]<='9')
			ans = ans*a+(data[j]-'0');
		else if(data[j]>='a'&&data[j]<='z'){
			ans = ans*a+(data[j]-'a'+10);
		}else{
			ans = ans*a+(data[j]-'A'+10);
		}
		
	}
	return ans;
}

int pow_int(int a,int k){
	int temp=a;
	while(k--){
		temp*=a;
	}
	return temp;
}

int main(){
	int a,b;
	char num[30];
	while(scanf("%d%s%d",&a,num,&b)!=EOF){
		long ans = change(num,a);

		char ans2[30];
		int id=0;
		do{
				if(ans%b>=0&&ans%b<=9)
					ans2[id++]=ans%b+'0';
				else if(ans%b>=10&&ans%b<=16)
					ans2[id++]=ans%b-10+'A';
			ans/=b;
		}while(ans);
			
		for(int i=id-1;i>=0;i--){
		
			printf("%c",ans2[i]);

		}
		
		printf("\n");
	}

	return 0;
}