#include <stdio.h>

int main(){
	int n,a,b,c,ans_i,ans_j,ans_total,max_total=0;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d%d%d",&n,&a,&b,&c)!=EOF){
		//scanf("%d%d%d",&a,&b,&c);
		if(n<1&&n>99){
			printf("0\n");
			continue;

		}
		ans_total=-1;
		bool flag=false;
		for(int i=9;i>=1;i--){
			for(int j=9;j>=0;j--){
				int total = i*10000+a*1000+b*100+c*10+j;
				if(total%n==0){
					//max_total=total/n;
					ans_total=total;
					ans_i=i;
					ans_j=j;
					flag=true;
					break;
				}
			}
			if(flag)break;
		}
		if(ans_total==-1){
			printf("0\n");
		}
		else{
			printf("%d %d %d\n",ans_i,ans_j,ans_total/n);
		}
	
	}
	return 0;
}