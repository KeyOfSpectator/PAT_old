#include <stdio.h>
#include <string.h>

char* buf;
char* temp;
char* temp_Min;
int n;

int pow_int(int n,int m){
	int tmp=n;
	for(int k=0;k<m;k++)
		tmp*=n;
	return tmp;
}

void draw(char* buf,int LeftTopX,int LeftTopY,int scale){//buf[X][Y]
	for(int r=0;r<n;r++)
		for(int s=0;s<n;s++)
			*(buf+(r+LeftTopX)*scale+s+LeftTopY)=*(temp_Min+r*n+s);
	return;
}

void repeat(char* buf, char* temp,int n,int m,int scale){
	//int scale = pow_int(n,m);
	if(m<=1) return;
	m--;
	scale = scale*n;
	strncpy(temp,buf,scale/n*scale/n);
	
	for(int l=0;l<scale;l++)
		for(int o=0;o<scale;o++)
			*(buf+l*scale+o)=' ';

	for(int p=0;p<scale/n;p++)
		for(int q=0;q<scale/n;q++){
			if(*(temp+p*scale/n+q)!=' ')
				draw(buf,p*n,q*n,scale);
		}


	repeat(buf,temp,n,m,scale);

	return;
}

int main(){
	int m;

	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		buf = new char[3000*3000];
		temp = new char[1000*1000];
		temp_Min = new char[5*5];

		while(getchar()!='\n') continue;
		for(int i=0;i<n;i++)
			gets(buf+i*n); //buf[i][j]	
				
		for(int x=0;x<n;x++)
			for(int y=0;y<n;y++){
				char temp=*(buf+x*n+y);
				if(temp==0)
					*(buf+x*n+y)=' ';
				*(temp_Min+x*n+y)=*(buf+x*n+y);
			}
				
		scanf("%d",&m);
		
		//for(int test=0;test<10;test++)
		//	printf("%c\n",*(buf+test));

		//printf("%c_0\n",*(buf+0));
		//printf("%c_1\n",*(buf+1));
		//printf("%c_2\n",*(buf+2));

		repeat(buf,temp,n,m,n);
	
		int Max_scale=pow_int(n,m-1);
		for(int t=0;t<Max_scale;t++)
			for(int u=0;u<Max_scale;u++){
				printf("%c",*(buf+t*Max_scale+u)); //buf[i][j]
				if(u==Max_scale-1)
					printf("\n");
			}
	}

return 0;
}