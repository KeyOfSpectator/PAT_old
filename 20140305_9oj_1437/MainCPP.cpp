#include <stdio.h>
#include <algorithm>
using namespace std;

struct Data{
	float price;
	float distance;
	bool operator < (const Data &A) const{
		return distance>A.distance;
	}
}buf[500];

int main(){
	int N;
	float Cmax,D,Davg;
	while(scanf("%f%f%f%d",&Cmax,&D,&Davg,&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%f%f",&buf[i].price,&buf[i].distance);

		sort(buf, buf+N);

		float current_MaxDistance=0.0;
		float current_price = 0.0;
		float current_minPrice = buf[0].price+1.0;
		float current_startDistance = 0.0;
		for(int j=0;j<N;j++){
			if(buf[j].distance<=current_MaxDistance){
				if(buf[j].price<=current_minPrice){
					current_price = current_price+(double)(buf[j].distance - current_startDistance)*current_minPrice;						
					current_minPrice = buf[j].price;

				
					current_startDistance = buf[j].distance;
					current_MaxDistance =  buf[j].distance+Cmax*Davg;

				
				}//end if
				
			
			}//end if
		
		}//end for
		if(current_MaxDistance<D)
			printf("The maximum travel distance = %.2f\n",current_MaxDistance);
		else{
			current_price = current_price+(double)(D - current_startDistance)*current_minPrice;
			printf("%.2f\n",current_price);
		}
			
	}
	return 0;
}