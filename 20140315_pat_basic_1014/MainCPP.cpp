#include <stdio.h>
#include <string.h>

char a1[60];
char a2[60];
char a3[60];
char a4[60];

char int_to_date[][7] = {
"MON","TUE","WED","THU","FRI","SAT","SUN"
};

int main(){
	//while(true){
		gets(a1);int len1=strlen(a1);
		gets(a2);int len2=strlen(a2);
		gets(a3);int len3=strlen(a3);
		gets(a4);int len4=strlen(a4);
		int len_first,len_second;
		a1>a2?len_first=len2:len_first=len1;
		a3>a4?len_second=len4:len_second=len3;
		bool flag=true;
		for(int i=0;i<len_first;i++){
			//if(((a1[i]>='A'&&a1[i]<='Z')||(a1[i]>='a'&&a1[i]<='z'))&&a1[i]==a2[i]&&flag==true){
			if(flag&&(a1[i]>='A'&&a1[i]<='G')&&a1[i]==a2[i]){
				flag=false;
				if(a1[i]>='A'&&a1[i]<='Z')
					printf("%s ",int_to_date[a1[i]-'A']);
				else if(a1[i]>='a'&&a1[i]<='z')
					printf("%s ",int_to_date[a1[i]-'a']);
			}																				//week
			//else if(((a1[i]>='0'&&a1[i]<='9')||(a1[i]>='A'&&a1[i]<='N')||(a1[i]>='a'&&a1[i]<='n'))&&a1[i]==a2[i]&&flag==false){
			else if(((a1[i]>='0'&&a1[i]<='9')||(a1[i]>='A'&&a1[i]<='N'))&&a1[i]==a2[i]&&flag==false){
				if(a1[i]>='0'&&a1[i]<='9')
					printf("%02d:",a1[i]-'0');
				else if(a1[i]>='A'&&a1[i]<='N')
					printf("%d:",a1[i]-'A'+10);
			//	else if(a1[i]>='a'&&a1[i]<='z')
			//		printf("%d:",a1[i]-'a'+10);
				break;
			}
		}
		for(int j=0;j<len_second;j++){
			if(((a3[j]>='A'&&a3[j]<='Z')||(a3[j]>='a'&&a3[j]<='z'))&&a3[j]==a4[j]){
				printf("%02d\n",j);
				break;
				
			}
		}

	//}
	return 0;
}