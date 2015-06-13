#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int ex(char a){
	if (a >= '0'&&a <= '9') return a - '0';
	else{
		return a - 'a'+10;
	}
}
int main(){
	char a[10];
	char b[10];
	int c;
	int ans=0;
	int d;
	bool flag = false;
	
	cin >> a >> b >> c >> d;
	if (c == 1){
		int td = d;
		int ta = 0;
		for (int i = 0; i< strlen(a); i++){
			ta *= d;
			ta += ex(a[i]);
		}
		for (int i = 2; i < 35; i++){
			int tb=0;
			int l = 0;
			for (int j = 0; j < strlen(b); j++){
				tb *= i;
				tb += ex(b[j]);
			}
			if (tb == ta){
				flag = true;
				ans = i;
				break;
			}
		}
	}
	else{
		int td = d;
		int tb = 0;
		for (int i = 0; i< strlen(b); i++){
			tb *= d;
			tb += ex(b[i]);
		}
		for (int i = 2; i < 35; i++){
			int ta = 0;
			int l = 0;
			for (int j = 0; j < strlen(a); j++){
				ta *= i;
				ta += ex(a[j]);
			}
			if (tb == ta){
				flag = true;
				ans = i;
				break;
			}
		}
	}

	if (ans == 0){
		cout << "Impossible" << endl;
	}
	else{
		cout << ans << endl;
	}
	
}