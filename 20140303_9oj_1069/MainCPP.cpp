#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Student{
	char id[100];
	char name[100];
	char sex[10];
	int age;
	bool operator < (const Student &A) const{
		return strcmp(id,A.id)<0;
	}
}buf[1000];

char find_id[100];

int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%s%s%d",&buf[i].id,&buf[i].name,&buf[i].sex,&buf[i].age);
		}
		scanf("%d",&m);

		sort(buf,buf +n);

		for(int j=0;j<m;j++){
			scanf("%s",&find_id);
			
			int left=0,right=n;
			int ans = -1;

			while(left<=right){
				int mid = (left+right)/2;
				if(strcmp(buf[mid].id,find_id)==0){
					ans=mid;
					break;
				}
				else if(strcmp(buf[mid].id,find_id)>0){
					right = mid-1;
				}else if(strcmp(buf[mid].id,find_id)<0){
					left = mid+1;
				}

			}//end while
			if(ans!=-1)
				printf("%s %s %s %d\n",buf[ans].id,buf[ans].name,buf[ans].sex,buf[ans].age);
			else
				printf("No Answer!\n");

		}//end for
	
	}//end while

	return 0;
}