#include <stdio.h>
#include <string.h>
	char words[40][80];
int main(){
	
	char data[80];

	//int mount=0;
	//while(true){
		gets(data);
		int mount=0;
		int data_id=0;
		int words_id=0;
		int len=strlen(data);
		while(data_id<len){
			if(data[data_id]!=' '){
				words[mount][words_id++]=data[data_id++];
			}else{
				//words[mount][words_id]=0;
				mount++;words_id=0;data_id++;
			}
		
		}
		//words[mount][words_id]=0;
		for(int i=mount;i>0;i--){
			printf("%s ",words[i]);
		}
		printf("%s\n",words[0]);
	//}

	
	return 0;
}