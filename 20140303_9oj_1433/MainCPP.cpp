#include <stdio.h>
#include <algorithm>

using namespace std;

struct Data{
double J;
double F;
double rateJF;
void caculate_rate(){
	rateJF=J/F;
}
bool operator <(const Data &A) const{
	return rateJF>A.rateJF;
}

}buf[1000];
int main(){
	int n;
	double m,get_mount;
	while(scanf("%lf%d",&m,&n)!=EOF){
		get_mount=0.0;
		if(m==-1&&n==-1)break;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&buf[i].J,&buf[i].F);
			//buf[i].caculate_rate();
			buf[i].rateJF=buf[i].J/buf[i].F;
		}
		sort(buf,buf+n);
		int j=0;
		while(m>0&&j<n){
			if(m>buf[j].F){
				get_mount+=buf[j].J;
				m-=buf[j].F;
				j++;
			}else if(j<n){
				get_mount+=(m*buf[j].rateJF);
				break;
			}
		}//end while
		printf("%.3lf\n",get_mount);
	}//end while
	return 0;
}