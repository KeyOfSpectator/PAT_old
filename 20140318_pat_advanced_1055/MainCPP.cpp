#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct P{
	string name;
	int age;
	int worth;
	bool operator < (const P &A) const{
		if(worth!=A.worth)return worth>A.worth;
		else if(age!=A.age)return age<A.age;
		else return name<A.name;
	
	}
}p[100001];

vector<P> v;

int main(){
	int N,Q;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );

	while(scanf("%d%d",&N,&Q)!=EOF){
		for(int i=0;i<N;i++){
			//scanf("%s%d%d",p[i].name,&p[i].age,&p[i].worth);
			cin>>p[i].name>>p[i].age>>p[i].worth;
		}
		v.clear();
		for(int j=0;j<Q;j++){
			v.clear();
			int M,a,b;
			scanf("%d%d%d",&M,&a,&b);
			for(int k=0;k<N;k++){
				if(p[k].age>=a&&p[k].age<=b){
					v.push_back(p[k]);
				}
				
			}
			sort(v.begin(),v.end());
			printf("Case #%d:\n",j+1);
			if(v.empty())
				printf("None\n");
			for(int l=0;l<M&&l<v.size();l++){
				cout<<v[l].name<<" "<<v[l].age<<" "<<v[l].worth<<endl;
				//printf("%s %d %d\n",v[l].name,v[l].age,v[l].worth);
				//v.pop_back();
			}
		
		}
	
	}
	return 0;
}