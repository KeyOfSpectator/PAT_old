#include <stdio.h>
#include <algorithm>
using namespace std;


struct Data{
	int n;
	int V;
	int W;
	double density[100];
}buf[100];


int main(){
	int c;
	while(scanf("%d",&c)!=EOF){
		for(int i=0;i<c;i++){
			scanf("%d%d%d",&buf[i].n,&buf[i].V,&buf[i].W);
		for(int j=0;j<buf[i].n;j++){
			scanf("%lf",&buf[i].density[j]);
		}
		
		sort(buf[i].density,buf[i].density+(buf[i].n));

		int V_all=0;
		double current_density=0.0;

		if(buf[i].density[0]>buf[i].W){
		printf("0 0.00\n");
		continue;
		}else{
			for(int k=0;k<buf[i].n;k++){
				double temp_density = (buf[i].density[k]*(double)buf[i].V+current_density*(double)V_all)/(double)(V_all+buf[i].V);
			if(buf[i].density[k]!=NULL&&temp_density<=buf[i].W){
					V_all=V_all+buf[i].V;
					current_density=temp_density;
			
			}//end if
			else break;
					
		
		}//end for

			printf("%d %.2lf\n",V_all,current_density/100.0);
		}//end else

		
		
		}//end for
	}//end while

return 0;}