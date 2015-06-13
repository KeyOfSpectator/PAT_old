#include <stdio.h>

struct Data{
	int first;
	int second;
	int third;
	int forth;

	void Next(){
		first++;
		if(first>=10){
			first=0;
			second++;
		}
		if(second>=10){
			second=0;
			third++;
		}
		if(third>=10){
			third=0;
			forth++;
		}
	}

	void judge(){
		int tmp=forth*1000+third*100+second*10+first;
		int anti_tmp = first*1000+second*100+third*10+forth;
		if(tmp*9/10000==0&&tmp*9%10000==anti_tmp)printf("%d\n",tmp);
	}

};
int main(){
	Data data;
	data.second=data.third=data.forth=0;
	data.first=1;
	for(int i=0;i<10000;i++){
		data.judge();
		data.Next();
	}



	return 0;
}