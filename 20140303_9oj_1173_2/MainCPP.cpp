#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	int data[101];
	int find[101];
	bool ans[101];

	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);
			ans[i]=false;
		}
		sort(data,data+n);
		scanf("%d",&m);
		for(int j=0;j<m;j++){
		scanf("%d",&find[j]);
		}
		
		for(int k=0;k<m;k++){
			int left=0,right=n,mid;
			while(left<=right){
				mid=(left+right)/2;
				if(data[mid]==find[k]){
					ans[k]=true;
					break;
				}else if(data[mid]<find[k]){
					left=mid+1;
				}else if(data[mid]>find[k]){
					right=mid-1;
				}
			}//end while
		}//end for

		for(int l=0;l<m;l++){
			if(ans[l]==true)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}