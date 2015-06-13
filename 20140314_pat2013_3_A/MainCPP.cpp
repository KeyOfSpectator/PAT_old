#include <stdio.h>
#include <algorithm>
using namespace std;

struct Data{
	int data;
	int num;
	bool operator < (const Data &A) const{
		return num>A.num;
	}

}buf[480000];

//int hash[16777216];
int main(){
	int m,n,id=0;
	while(scanf("%d%d",&m,&n)!=EOF){
		//for(int j=0;j<480000;j++){buf[j].num=0;}
		for(int i=0;i<m;i++ ){
			for(int k=0;k<n;k++){
				int temp;
				scanf("%d",&temp);
				bool flag = true;
				for(int l=0;l<i*m+k;l++){
					if(buf[l].data==temp){
						buf[l].num++;
						flag = false;
						break;
					}
				}
				if(flag){
				buf[id].num=1;
				buf[id].data=temp;
				}
			}
		}
		sort(buf,buf+(m*n));
		printf("%d\n",buf[0].data);

	
	}
	return 0;
}