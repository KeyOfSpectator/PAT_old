#include <stdio.h>

int main(){
	int n,lastLine,spaceNum,starNum;
	while(scanf("%d",&n)!=EOF){
		lastLine = (n+(n-1)*2);
		spaceNum=lastLine-n;
		starNum=n;
		for(int i=0;i<n;i++){
			for(int j=0;j<spaceNum;j++){
			printf(" ");
			}
			for(int k=0;k<starNum;k++){
			printf("*");
			}
			printf("\n");
			spaceNum=spaceNum-2;
			starNum = starNum+2;

		}
	
	
	}

	return 0;
}