//#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct E{
string id;
string name;
int score;
};

bool cmp_id(const struct E a,const struct  E b){
	return a.id<b.id;
}//end cmp_id
bool cmp_name(const  struct E c,const  struct E d){
	if(c.name==d.name) return c.id<d.id;
	else return c.name<d.name;
}//end cmp_name
bool cmp_score(const  struct E e,const  struct E f){
	if(e.score==f.score)return e.id<f.id;
	else return e.score<f.score;
}//end cmp_score


int main(){
	int n,c;

	int count=0;
	while(cin>>n>>c){
		count++;
		struct E data[n];
		if(n==0&&c==0) break;
		
		for(int i=0;i<n;i++){
		cin>>data[i].id>>data[i].name>>data[i].score;
		}//end for
		switch(c)
		{
		case 1:
		sort(data,data+n,cmp_id);
		break;
		case 2:
		sort(data,data+n,cmp_name);
		break;
		case 3:
		sort(data,data+n,cmp_score);
		break;
		}
	//}//end while
		cout<<"Case "<<count<<":"<<endl;
		//printf("%d\n",count);
		for(int j=0;j<n;j++){
			cout<<data[j].id<<" "<<data[j].name<<" " <<data[j].score<<endl;
		//printf("%s %s %d\n",data[i].id,data[i].name,data[i].score);
		
		}//end for
	}//end while
		return 0;
}//end main
