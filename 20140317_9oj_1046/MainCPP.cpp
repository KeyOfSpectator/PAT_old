#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int , vector<int>, less<int> > q;
int main(){
	int a;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d",&a)!=EOF){
		while(!q.empty())q.pop();
		q.push(a);
		int c=9;
		while(c--){
		scanf("%d",&a);
		q.push(a);
		}
		printf("max=%d\n",q.top());
	
	}
	return 0;
}