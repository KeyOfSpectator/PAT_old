#include <stdio.h>
#include <string.h>


long change2d(char* str,int r){
	int L=strlen(str);
	long k=0;
	int m=1;
	for(int i=L-1;i>=0;i--){
		if(str[i]>='0'&&str[i]<='9'){
			k+=(str[i]-'0')*m;
		}
		else{
			k+=(str[i]-'a'+10)*m;
		}
		m*=r;
	}	
	return k;

}

int main(){
	char a[10];
	char b[10];
	int flag,radix;
	int ans;

	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%s%s%d%d",a,b,&flag,&radix)!=EOF){
		ans=0;
		if(flag==1){
			long a2d = change2d(a,radix);
			long b2d;
			for(int x=2;x<100;x++){
				b2d=change2d(b,x);
				if(a2d==b2d){
					ans=x;
					break;
				}
			}
			if(ans==0)printf("Impossible\n");
			else printf("%d\n",ans);

		}else{
		
			long a2d2 = change2d(b,radix);
			long b2d2;
			for(int x=2;x<100;x++){
				b2d2=change2d(a,x);
				if(a2d2==b2d2){
					ans=x;
					break;
				}
			}
			if(ans==0)printf("Impossible\n");
			else printf("%d\n",ans);
		
		}
	
	}


	return 0;
}