#include <stdio.h>

int Day_of_Month[13][2]={
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

int isLeapYear(int year){
	int tmp;
	year%4==0&&year%100!=0||year%400==0 ? tmp=1:tmp=0;
	return tmp;

}

struct date{
int year;
int month;
int day;
void Nextday(){
day++;
if(day>Day_of_Month[month][isLeapYear(year)]){
day=1;month++;
}
if(month>12){
month=1;year++;
}
}
};

int buf[5001][13][32];

int abs(int a){
	int b;
	a<0? b=-a:b=a;
	return b;
}

int main(){
int year1,year2;
int month1,month2;
int day1,day2;

int count = 0;
date Date;
Date.year=0;Date.month=1;Date.day=1;

while(Date.year<5001){
buf[Date.year][Date.month][Date.day]=count;
count++;
Date.Nextday();

}
//printf("%d",buf[2014][2][28]);

while(scanf("%4d%2d%2d",&year1,&month1,&day1)!=EOF){
scanf("%4d%2d%2d",&year2,&month2,&day2);
int sum = abs(buf[year1][month1][day1]-buf[year2][month2][day2]);
printf("%d\n",sum+1);

}

return 0;
}