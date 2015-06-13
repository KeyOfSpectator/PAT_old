#include <stdio.h>
#include <algorithm>
#include <vector>
//#include <fstream>
//#include <iostream>
using namespace std;



bool compare(const char a[],const char b[]){
	bool flag = false;
	for(int k=0;k<8;k++){
		if(a[k]<b[k]){
			flag= true;
			return true;
		}
		else if(a[k]>b[k]){
			return false;
		}
	}
	if(flag==false)return false;
}

struct Student{
	 //char id[9];
		int id;
	 int d_score;
	 int c_score;
	 int mount_score;
	 void caculate_score(){
		mount_score=d_score+c_score;
	 }
	 bool operator < (const Student &A)const{
		if(mount_score!=A.mount_score)return mount_score>A.mount_score;
		else if(d_score!=A.d_score)return d_score>A.d_score;
		//else return compare(id,A.id);
		else return id<A.id;
	 
	 }

};

int main(){
	int N,L,H;
	freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt", "r", stdin );
	//ifstream cin("C:\\Users\\fsc\\Desktop\\input_test.txt");
	while(scanf("%d%d%d",&N,&L,&H)!=EOF){
		Student data;
		vector<Student> class1;
		vector<Student> class2;
		vector<Student> class3;
		vector<Student> class4;
		int mount=0;
		for(int i=0;i<N;i++){
			scanf("%d%d%d",&data.id,&data.d_score,&data.c_score);
			//data.id[8]=0;
			data.caculate_score();
			if(data.c_score>=L&&data.d_score>=L){
				mount++;
				if(data.c_score>=H&&data.d_score>=H)class1.push_back(data);
				else if(data.c_score<H&&data.d_score>=H)class2.push_back(data);
				else if(data.c_score<H&&data.d_score<H&&data.d_score>data.c_score)class3.push_back(data);
				else class4.push_back(data);
			}
		}
		sort(class1.begin(),class1.end());
		sort(class2.begin(),class2.end());
		sort(class3.begin(),class3.end());
		sort(class4.begin(),class4.end());

		printf("%d\n",mount);
		for(int j=0;j<class1.size();j++){
			printf("%08d %d %d\n",class1[j].id,class1[j].d_score,class1[j].c_score);
		}
		for(int l=0;l<class2.size();l++){
			printf("%08d %d %d\n",class2[l].id,class2[l].d_score,class2[l].c_score);
		}
		for(int x=0;x<class3.size();x++){
			printf("%08d %d %d\n",class3[x].id,class3[x].d_score,class3[x].c_score);
		}
		for(int y=0;y<class4.size();y++){
			printf("%08d %d %d\n",class4[y].id,class4[y].d_score,class4[y].c_score);
		}
	}
	return 0;
}