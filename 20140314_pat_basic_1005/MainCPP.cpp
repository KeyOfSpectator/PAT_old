#include <stdio.h>
#include <algorithm>
using namespace std;

int data[101];
int n;

int* caculate(int data,int* hash){
	while(data!=1){
		if(data%2==0){data=data/2;}
		else{data = (3*data+1)/2;}
		if(data<=100)
		hash[data]++;
	}
	return hash;
}

bool judge(int* hash){
	bool flag = true;
	for(int l=0;l<n;l++){
		if(hash[data[l]]!=1){
			flag = false;
			break;
		}
	
	}
	return flag;
	
}

int main(){



	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);
		//
		}
		int buf[101],id=0;
		int hash[101];

		for(int v=0;v<101;v++)	hash[v]=0;
		for(int j=0;j<n;j++){
			
			caculate(data[j],hash);
		}
		for(int m=0;m<n;m++){
			if(hash[data[m]]==0)buf[id++]=data[m];
		}
		sort(buf,buf+id);
		for(int k=id-1;k>=1;k--){
			printf("%d ",buf[k]);
		}
		printf("%d\n",buf[0]);
	}
	return 0;
}