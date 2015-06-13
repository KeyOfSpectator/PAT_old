#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> l;

int main(){
	int n,m;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );

	while(scanf("%d",&n)!=EOF){
		l.clear();
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			l.push_back(tmp);
		}
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int tmp2;
			scanf("%d",&tmp2);
			l.push_back(tmp2);
		
		}
		sort(l.begin(),l.end());
		printf("%d\n",l[(n+m-1)/2+1]);
	
	}

	return 0;

}