#include <stdio.h>


void output(char s){
	switch(s-'0'){
	case 0:printf("ling");break;
	case 1:printf("yi");break;
	case 2:printf("er");break;
	case 3:printf("san");break;
	case 4:printf("si");break;
	case 5:printf("wu");break;
	case 6:printf("liu");break;
	case 7:printf("qi");break;
	case 8:printf("ba");break;
	case 9:printf("jiu");break;
	
	}

}

int main(){
	char data[100];
	int ans=0;


	while(scanf("%s",data)!=EOF){
		for(int i=0;data[i]!=0;i++){
			ans+=data[i]-'0';
		}
		char ans_char[10];
		int id=0;
		while(ans!=0){
			ans_char[id++]=ans%10+'0';
			ans/=10;
		}
		for(int j=id-1;j>0;j--){
			output(ans_char[j]);
			printf(" ");
		}
		output(ans_char[0]);
			printf("\n");
	}
	return 0;
}