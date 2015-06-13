#include <stdio.h>
#include <algorithm>
using namespace std;

struct Data{
	int hash;
	int cnt;
	
	bool operator <(const Data &A)const{
		return cnt>A.cnt;
	}

}data[480000];

int hash[480000];
int cnt[480000];
int id;

int main(){
	int n,m;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&m)!=EOF){
		id=0;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int tmp;
				//scanf("%d",&tmp);
				scanf("%d",&tmp);
				//int i_tmp=M.find(tmp);
				bool flag=true;
				for(int k=0;k<id;k++){
					if(data[k].hash==tmp){
						data[k].cnt++;
						flag=false;
					}
				}
				if(flag){
					data[id].hash=tmp;
					data[id++].cnt=1;
				}

			}//
		}//
		sort(data,data+id);
		printf("%d\n",data[0].hash);
	
	
	}

}