#include <stdio.h>


char buf[3000][3000];
char temp[3000][3000];
char Template[6][6];
int n,m;

void point(int TopLeft_X,int TopLeft_Y){
	for(int p=0;p<n;p++)
		for(int q=0;q<n;q++){
			buf[p+TopLeft_X][q+TopLeft_Y]=Template[p][q];
		}
	return;
}

void draw(int scale){
	for(int l=0;l<scale;l++)
		for(int o=0;o<scale;o++){
		temp[l][o]=buf[l][o];
		buf[l][o]=' ';
		}
	for(int x=0;x<scale/n;x++)
		for(int y=0;y<scale/n;y++){
		if(temp[x][y]!=' ')
			point(x*n,y*n);
		}
	return;
}


int main(){
	while(scanf("%d",&n)!=EOF){
		int scale;

		if(n==0) break;

		while(getchar()!='\n') continue;
		for(int i=0;i<n;i++)
			gets(buf[i]);

		scanf("%d",&m);

		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++){
				if(buf[j][k]==NULL) buf[j][k]=' ';
				Template[j][k]=buf[j][k];
			}

		scale=n;
		for(int time=1;time<m;time++){
			scale*=n;
			draw(scale);
		}
		
		for(int u=0;u<scale;u++)
			for(int v=0;v<scale;v++){
				printf("%c",buf[u][v]);
				if(v==scale-1)
					printf("\n");
			}
			
	
	}


	return 0;
}