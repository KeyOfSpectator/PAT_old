#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Data{
	int exp;
	double num;
	bool operator < (const Data &A)const{
		return exp>A.exp;
	}
};


int main(){
	int len_1,len_2;
	vector <Data> ans_data;
	
	freopen("C:\\Users\\fsc\\Desktop\\input_test.txt","r",stdin);

	scanf("%d",&len_1);
	struct Data* data1 = new Data[len_1];
	for(int i=0;i<len_1;i++){
		scanf("%d%lf",&data1[i].exp,&data1[i].num);	
		ans_data.push_back(data1[i]);
	}
	scanf("%d",&len_2);
	struct Data* data2 = new Data[len_2];
	for(int j=0;j<len_2;j++){
		scanf("%d%lf",&data2[j].exp,&data2[j].num);	
		bool flag=false;
		for(int k=0;k<ans_data.size();k++){
			if(data2[j].exp==ans_data[k].exp){
				flag=true;
				ans_data[k].num+=data2[j].num;

				break;
			}
		}
		if(!flag){
			ans_data.push_back(data2[j]);
		}
	}
	sort(ans_data.begin(),ans_data.end());
	int size = ans_data.size();
	printf("%d ",size);
	for(int l=0;l<size-1;l++){
		if(ans_data[l].num!=0.0)
		printf("%d %.1lf ",ans_data[l].exp,ans_data[l].num);
	}
	printf("%d %.1lf\n",ans_data[size-1].exp,ans_data[size-1].num);
	

	return 0;
}