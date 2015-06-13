#include <stdio.h>
#include <string.h>
int main(){
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	char data[81];
	while(scanf("%s",data)!=EOF){
		int N=strlen(data);
		int n1=0,temp=0;
		for(int i=3;i<=N;i++){
			int total = (N+2)-i;
			if(total%2==0&&(total/2)<=i){
				temp=total/2;
				if(temp>n1)
					n1=temp;
			}
		
		}
		int n3=n1;
		int n2=N-n1-n3+2;
		char* ans = new char[n1*n2];
		for(int m=0;m<n1*n2;m++){
			ans[m]=' ';
		}
		for(int j=0;j<n1;j++){
			ans[j*n2]=data[j];
		}
		for(int k=0;k<n2-2;k++){
			ans[(n1-1)*n2+k+1]=data[k+n1];
		}
		for(int l=n3,y=0;l>0;l--,y++){
			ans[l*n2-1]=data[y+n1+n2-2];
		}

		for(int x=0;x<(n1*n2);x++){
			printf("%c",ans[x]);
			if((x+1)%n2==0&&x>0)
				printf("\n");
		}
	
	
	}

	return 0;
}