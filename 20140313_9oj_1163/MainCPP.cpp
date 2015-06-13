#include <stdio.h>
#include <math.h>
bool judge(int n){
	bool flag=true;
	for(int k=2;k<=sqrt(n);k++){
		if(n%k==0)flag=false;
	}
	return flag;
}

int main(){
	int n;
	int num[10001];
	int buf[1000];
	while(scanf("%d",&n)!=EOF){
		int id=0;
		for(int i=2;i<n;i++){
			num[i]=0;
			if(num[i]==1||judge(i)&&i%10==1){buf[id++]=i;num[i]=1;}
			int temp=2*i;
			while(temp<=n){
				num[temp]=1;
				temp+=i;
			}//end while
			
			
		}//end for
		if(id==0)printf("-1\n");
		else{
			for(int j=0;j<id-1;j++){
				printf("%d ",buf[j]);
			}
			printf("%d\n",buf[id-1]);
		}
	}//end while
	return 0;	
}