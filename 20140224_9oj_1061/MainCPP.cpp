#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
struct E{
char name[101];
int age;
int score;

}buf[1000];

bool cmp(E a, E b){
	if(a.score!=b.score) return a.score<b.score;
	int tmp = strcmp(a.name,b.name);
	if(tmp!=0)	return tmp<0;
	else return a.age<b.age;
	
}//end cmp

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
		scanf("%s%d%d",&buf[i].name,&buf[i].age,&buf[i].score);
		}//end for
		sort(buf,buf+n,cmp);
		for(int j=0;j<n;j++){
		printf("%s %d %d\n",buf[j].name,buf[j].age,buf[j].score);		
		}//end for

	}//end while
	return 0;
}//end main