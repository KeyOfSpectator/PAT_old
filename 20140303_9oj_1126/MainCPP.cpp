#include <stdio.h>
#include <string.h>

int num[1000];
int data[1000][80];
int print[1000];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		for(int j=0;j<num[i];j++){
			scanf("%d",&data[i][j]);	
		}//end for
		}//end for
		
	
		for(int k=0;k<n;k++){
			int count = 0;
			for(int x =0;x<num[k];x++){
				if((x==0&&data[k][x]!=data[k][x+1])||(x==num[k]-1&&data[k][x]!=data[k][x-1])||(data[k][x]>data[k][x+1]&&data[k][x]>data[k][x-1])||(data[k][x]<data[k][x+1]&&data[k][x]<data[k][x-1])){
				print[count++]=x;
				}
				
			}//end for
			for(int l=0;l<count;l++){
				printf("%d",print[l]);
				if(l!=count-1)printf(" ");
				else printf("\n");
			}
			
	}

		}//end for
	
	return 0;
}