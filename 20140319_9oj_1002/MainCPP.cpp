#include <stdio.h>

int abs(int x){
	return x>0?x:-x;
}

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int P,T,G1,G2,G3,GJ;
	while(scanf("%d%d%d%d%d%d",&P,&T,&G1,&G2,&G3,&GJ)!=EOF){
		float ans;
		if((G1>G2?G1-G2:G2-G1)<=T){
			ans=(float)(G1+G2)/2;
		}else if(((G3>G2?G3-G2:G2-G3)<=T)&&((G3>G1?G3-G1:G1-G3)>T)||((G3>G1?G3-G1:G1-G3)<=T)&&((G3>G2?G3-G2:G2-G3)>T)){
			int a=abs(G1-G3);
			int b=abs(G2-G3);
			ans=(float)((a<b?G1:G2)+G3)/2;
		}else if(((G3>G2?G3-G2:G2-G3)<=T)&&((G3>G1?G3-G1:G1-G3)<=T)){
			ans=(float)max(G1,max(G2,G3));
		}else{
			ans=(float)GJ;
		}
		printf("%.1f\n",ans);
	
	}
	return 0;
}