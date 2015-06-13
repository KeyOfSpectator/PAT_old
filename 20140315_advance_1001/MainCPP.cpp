#include <stdio.h>

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		bool flag;
		int c=a+b;
		if(c>0)
			{flag=true;}
		else if(c<0){flag=false;c=-c;}
		else {
			c=0;
			printf("0\n");
			continue;
		}
		int temp=c;
		char data[20];int id=0,mount=0;
		bool flag1=false;
		while(temp!=0){
			if(mount!=0&&mount%3==0&&flag1){
				data[id]=',';
				flag1=false;
			}
			else{
			data[id]=temp%10+'0';
			temp/=10;
			flag1=true;
			mount++;
			}
			id++;
		
		}
		if(flag==false)
		data[id++]='-';
		for(int i=id-1;i>0;i--){
			printf("%c",data[i]);
		}
		printf("%c\n",data[0]);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
 
	
	}
	return 0;
}