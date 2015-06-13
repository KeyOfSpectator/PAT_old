#include <stdio.h>

int main(){
	int a,b;

	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				a=i*100+j*10+k;
				b=j*100+k*10+k;
				if((a+b)==532){
					printf("%d %d %d\n",i,j,k);
				
				
				}
			}
		}
	}
	return 0;
}