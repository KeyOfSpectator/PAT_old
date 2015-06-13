#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


struct Student{
	char id[6];
	int C;
	int M;
	int E;
	int A;
	

	int rank[4];//0A 1C 2M 3E
	
	void caculateA () {
		A = (C+M+E)/3;
	}
	

}list[2001];

int find_id(char str[],int n){
	for(int k=0;k<n;k++){
		if(strcmp(list[k].id,str)==0){
			return k;
		}
	}
	return -1;
}

int max(int * ranklist){
	if(ranklist[0]<=ranklist[1]&&ranklist[0]<=ranklist[2]&&ranklist[0]<=ranklist[3])return 0;
	if(ranklist[1]<ranklist[0]&&ranklist[1]<=ranklist[2]&&ranklist[1]<=ranklist[3])return 1;
	if(ranklist[2]<ranklist[0]&&ranklist[2]<ranklist[1]&&ranklist[2]<=ranklist[3])return 2;
	else return 3;
}

int main(){
	int n,m;
	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%d%d%d",&list[i].id,&list[i].C,&list[i].M,&list[i].E);
			list[i].caculateA();
		}
		for(int j=0;j<m;j++){
			char findStr[6];
			scanf("%s",findStr);
			int id = find_id(findStr,n);
			if(id==-1){printf("N/A\n");continue;}
			
			
				for(int f=0;f<n;f++){
					if(list[f].A>list[id].A)
						list[id].rank[0]++;
				}
				
				for(int f2=0;f2<n;f2++){
					if(list[f2].C>list[id].C)
						list[id].rank[1]++;
				}
				for(int f3=0;f3<n;f3++){
					if(list[f3].M>list[id].M)
						list[id].rank[2]++;
				}
				for(int f4=0;f4<n;f4++){
					if(list[f4].E>list[id].E)
						list[id].rank[3]++;
				}
			
			int Max_id = max(list[id].rank);
			char Max_sbj;
			switch(Max_id){
			case 0:Max_sbj='A';
				break;
			case 1:Max_sbj='C';
				break;
			case 2:Max_sbj='M';
				break;
			case 3:Max_sbj='E';
				break;
			}
			printf("%d %c\n",list[id].rank[Max_id]+1,Max_sbj);

		}
	
	}

	
	return 0;
}