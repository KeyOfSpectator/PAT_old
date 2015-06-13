#include <stdio.h>
#include <string.h>

char * Divide(char* num){
	for(int j=0;j<strlen(num);j++){
		if(num[j]%2==0)num[j]=(num[j]-'0')/2+'0';
		else{
			num[j]=(num[j]-'0')/2+'0';
			if(num[j+1]!=0)
				num[j+1]=(num[j+1]-'0')+10+'0';
		}
	}
	int i=0;
	while(num[i]=='0')i++;
	for(int k=i;num[k]!=0;k++){
		num[k-i]=num[k];
	}
	num[k-i]=0;
	return num;
}

bool IsNotEmpty(char* num){
	if(num[0]=='0'&&strlen(num)==1)
		return false;
	else return true;

}

int main(){
	char num[30];
//	char temp[30];
	char binary[110];
	while(scanf("%s",num)!=EOF){
		int i=0;
		do{
		binary[i++]=num[strlen(num)-1]%2;
		*num = Divide(num);
		}while(IsNotEmpty(num));

	
		for(int l=i-1;l>=0;l--){
			printf("%c",binary[l]);
			}
		printf("\n");
	}

	return 0;
}