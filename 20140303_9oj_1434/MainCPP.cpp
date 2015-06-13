#include <stdio.h>
#include <algorithm>

using namespace std;
struct Data{
	int start;
	int end;
	int length;
	bool operator < (const Data &A)const{
		return end<A.end;
	}

}buf[100];

int main(){
	int n;
	bool flag_array[100];
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		int count =0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&buf[i].start,&buf[i].end);
			buf[i].length=buf[i].end-buf[i].start;
		
		}
		for(int x=0;x<100;x++){
			flag_array[x]=false;
		}
		sort(buf,buf+n);

		/*for(int j=0;j<n;j++){
			bool flag=true;
			for(int k=buf[j].start;k<=buf[j].end;k++){
				if(flag_array[k]==true) flag=false;
			}//end for
			if(flag==true){
				count++;
				for(int l=buf[j].start;l<=buf[j].end;l++){
					flag_array[l]=true;
				}

			}
		}//end for
		*/
		
		int current_time=0;
		for(int j=0;j<n;j++){
			if(current_time<=buf[j].start){
			current_time=buf[j].end;
			count++;
			}
		}

		printf("%d\n",count);
	}//end while
	return 0;
}