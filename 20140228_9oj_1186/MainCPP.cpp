#include <stdio.h>

int DayOfMonth[13][2]={
0,0,
31,31,
28,29,
31,31,
30,30,
31,31,
30,30,
31,31,
31,31,
30,30,
31,31,
30,30,
31,31
};

int IsLeapYear( int year){
int tmp;
((year%4==0&&year%100!=0)||year%400==0)? tmp=1:tmp=0;
return tmp;
}

struct Date{
int year;
int month;
int day;
void Nextday(){
day++;
if(day>DayOfMonth[month][IsLeapYear(year)]){
day=1;month++;
}
if(month>12){
month=1;year++;
}
}
};

int buf[3001][13][32];

int main(){
	int year,count;
	while(scanf("%d%d",&year,&count)!=EOF){
	Date date;date.year=year;date.month=1;date.day=1;
	for(int i=1;i<count;i++){
	date.Nextday();
	}
	printf("%04d-%02d-%02d\n",date.year,date.month,date.day);
	}
	return 0;
}