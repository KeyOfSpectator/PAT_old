#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int data[1000];
	int a1[1000];int id_a1;
	int a2[1000];int id_a2;
	int a3[1000];int id_a3;
	int a4[1000];int id_a4;
	int a5[1000];int id_a5;
	while(scanf("%d",&n)!=EOF){
		id_a1=0;id_a2=0;id_a3=0;id_a4=0;id_a5=0;
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);
			if(data[i]%5==0&&data[i]%2==0)
				a1[id_a1++]=data[i];
			if(data[i]%5==1)a2[id_a2++]=data[i];
			if(data[i]%5==2)a3[id_a3++]=data[i];
			if(data[i]%5==3)a4[id_a4++]=data[i];
			if(data[i]%5==4)a5[id_a5++]=data[i];
		}
		int ans1=0;
		for(int j=0;j<id_a1;j++){
			ans1+=a1[j];
		}
		ans1==0?printf("N "):printf("%d ",ans1);
		int ans2=0;
		for(int k=0;k<id_a2;k++){
			k%2==0?ans2+=a2[k]:ans2-=a2[k];
		}
		id_a2==0?printf("N "):printf("%d ",ans2);
		int ans3=id_a3;
		ans3==0?printf("N "):printf("%d ",ans3);
		float ans4=0.0;
		for(int l=0;l<id_a4;l++){
			ans4+=(float)a4[l];
		}
		ans4=ans4/(float)id_a4;
		id_a4==0?printf("N "):printf("%.1f ",ans4);
		sort(a5,a5+id_a5);
		int ans5=a5[id_a5-1];
		ans5==0?printf("N\n"):printf("%d\n",ans5);
		//printf("%d %d %d %.1f %d\n",ans1,ans2,ans3,ans4,ans5);
			
	}
	return 0;
}