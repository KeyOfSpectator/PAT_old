#include <stdio.h>

int main(){
	for(int i=0;i<256;i++){
		int tmp1 = i*i;
		int tmp2 = i*i;
		int m=0;
		while(tmp1){
			m=m*10+tmp1%10;
			tmp1/=10;
		}
		if(m==tmp2)printf("%d\n",i);

	}
	return 0;
}