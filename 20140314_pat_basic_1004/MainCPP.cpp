#include <stdio.h>
#include <algorithm>
using namespace std;
struct Student{
	char name[11];
	char id[11];
	int score;
	bool operator <(const Student &A)const{
		return score<A.score;
	
	}
};

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		struct Student* buf= new Student[n];
		for(int i=0;i<n;i++){
			scanf("%s",buf[i].name);
			scanf("%s",buf[i].id);
			scanf("%d",&buf[i].score);
		
		}
		sort(buf,buf+n);

		printf("%s %s\n",buf[n-1].name,buf[n-1].id);
		printf("%s %s\n",buf[0].name,buf[0].id);
	}
	return 0;
}
