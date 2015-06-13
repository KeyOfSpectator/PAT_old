#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;



struct Time{
	int hour;
	int min;
	int sec;
	bool operator <(const Time &A) const{
		if(hour!=A.hour)return hour<A.hour;
		else if(min!=A.min)return min<A.min;
		else return sec<A.sec;
	}

};

struct P{
	char id[15];
	struct Time t_come;
	struct Time t_go;

};

bool cmp_come(P a,P b){
	return a.t_come<b.t_come;
}

bool cmp_go(P a,P b){
	return a.t_go<b.t_go;
}

vector <P> list;

int main(){
	int m;
//	freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d",&m)!=EOF){
		list.clear();
		for(int j=0;j<m;j++){
			//char tmp_name[15];

			P tmp_p;
			

			int H,M,S;
			scanf("%s",tmp_p.id);
			scanf("%d:%d:%d",&H,&M,&S);
			
			Time tmp_t;
			tmp_t.hour=H;
			tmp_t.min=M;
			tmp_t.sec=S;
			
			tmp_p.t_come=tmp_t;

			scanf("%d:%d:%d",&H,&M,&S);
			
			//Time tmp_t;
			tmp_t.hour=H;
			tmp_t.min=M;
			tmp_t.sec=S;
			
			tmp_p.t_go=tmp_t;

			list.push_back(tmp_p);

		}
		sort(list.begin(),list.end(),cmp_come);
		printf("%s ",list[0].id);
		sort(list.begin(),list.end(),cmp_go);
		printf("%s\n",list[m-1].id);

	}
	return 0;
}