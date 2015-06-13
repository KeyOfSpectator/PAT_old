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

int IsLeapYear(int year){
int tmp;
((year%4==0&&year%100!=0)||year%400==0)?tmp=1:tmp=0;
return tmp;

}

struct Date{
int year;
int month;
int day;
void NextDay(){
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
	int year ,month , day;
	Date date;

	while(scanf("%d%d%d",&year,&month,&day)!=EOF){
			int count=1;
		date.year=year;date.month=1;date.day=1;
		while(date.month!=month||date.day!=day){
		date.NextDay();
		count++;
		}
	printf("%d\n",count);
	}
	return 0;
}