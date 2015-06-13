#include <stdio.h>

int main(){
	int data;
	while(scanf("%d",&data)!=EOF){
		int wei[3]={0,0,0};//0个位1十位2百位
		for(int i=0;data!=0;i++){
			wei[i]=data%10;
			data/=10;
		}
		for(int j=0;j<wei[2];j++){
			printf("B");
		}
		
		for(int k=0;k<wei[1];k++){
			printf("S");
		}
		
		for(int l=0;l<wei[0];l++){
			printf("%d",l+1);
		}
		printf("\n");
	}
	return 0;
}