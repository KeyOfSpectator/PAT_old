#include <stdio.h>

struct Data{
	int address;
	int num;
	int Next_address;
};

void reversal(Data* data,int k,int n){
	int round=n/k;
	int l_id,r_id;
	Data temp;
	for(int l=0;l<round;l++){
		l_id=l*k;
		r_id=(l+1)*k-1;
		int temp_l_id=l_id;
		while(temp_l_id<l_id+k/2){
			temp=data[temp_l_id];
			data[temp_l_id]=data[r_id];
			data[r_id]=temp;
			temp_l_id++;r_id--;
		}

	
	}
}

int main(){
	int N,K,start_id;
	freopen("C:\\Users\\fsc\\Desktop\\input_test.txt", "r", stdin );
	while(scanf("%d%d%d",&start_id,&N,&K)!=EOF){
		 Data *data = new Data[N];
		 Data *buf = new Data[N];
		for(int i=0;i<N;i++){
			scanf("%d%d%d",&buf[i].address,&buf[i].num,&buf[i].Next_address);
			if(buf[i].address==start_id)
				data[0]=buf[i];
		}
//	bool flag=true;//¶ÏÁ´
		int mount=1;
		for(int j=0;j<N;j++){
			//flag=false;
			for(int k=0;k<N;k++){
				if(data[j].Next_address==buf[k].address){
						data[j+1]=buf[k];
						mount++;
						break;
				}else if(data[j].Next_address==-1){
					//mount++;
					break;				
				}
			}
			
		}
		reversal(data,K,mount);
		for(int x=0;x<mount-1;x++){
			printf("%05d %d %05d\n",data[x].address,data[x].num,data[x+1].address);
		
		}
			printf("%05d %d -1\n",data[mount-1].address,data[mount-1].num);
	}
	return 0;
}