#include <stdio.h>


char patten[81][81];

int main(){
	bool firstCase=true;

	int n,spaceNum;
	char a,b,tmp;
	int topLeft_line,topLeft_row;

	while(scanf("%d %c %c",&n,&a,&b)!=EOF){
		if(firstCase==true) firstCase=false;
		else printf("\n");
		if(n%2!=1)	break;

	//
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
		patten[x][y]=' ';
	}}

	
	topLeft_line=n/2;topLeft_row=n/2;//center

	for(int i=0;i<=(n/2);i++){
		(i%2==1)?tmp=b:tmp=a;
		for(int j=0;j<(i+1)*2-1;j++){
			patten[topLeft_line][topLeft_row+j] = tmp;
			patten[topLeft_line +j][topLeft_row] = tmp;
			patten[topLeft_line +(i*2)][topLeft_row +j] = tmp;
			patten[topLeft_line+j][topLeft_row+(i*2)] = tmp;

		
		}
			topLeft_line--;topLeft_row--;
	}
	if(n!=1){
		patten[n-1][0] = ' ';
		patten[0][n-1] = ' ';
		patten[0][0] = ' ';
		patten[n-1][n-1] = ' ';
	}
	
		for(int k=0;k<n;k++){
		for(int l=0;l<n;l++){
		printf("%c",patten[k][l]);
		if(l==(n-1)) 
			printf("\n");
		
		}
	}

	}
	return 0;
}
