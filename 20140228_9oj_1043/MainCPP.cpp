#include <stdio.h>
#include <string.h>

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

char monthName[13][20] = {
"",
"January",
"February",
"March",
"April",
"May",
"June",
"July",
"August",
"September",
"October",
"November",
"December",
};

char weekName[7][20] = {
"Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday",
"Saturday",
"Sunday",
};

int IsLeapYear(int year){
	int tmp;
	((year%4==0&&year%100!=0)||year%400==0) ? tmp= 1: tmp= 0;
	return tmp;

}

int abs(int a){
	int b;
	a<0?b=-a:b=a;
	return b;
}


struct Date{
int year;
int month;
int day;
void Nextday(){
day++;
if(day>DayOfMonth[month][IsLeapYear(year)]){
day = 1;month++;
}
if(month>12){
month = 1;
year++;
}
}
};

int buf[3001][13][32];

int main(){
	Date date;
	date.day=1;date.month=1;date.year=0;
	int count=0;
	while(date.year<3001){
	buf[date.year][date.month][date.day]=count;
	count++;
	date.Nextday();
	}
	
	//printf("%d",buf[2014][2][28]);
	
	int d,m,y;
	char mchar[20];

	while(scanf("%d%s%d",&d,mchar,&y)!=EOF){
		for(int i=0;i<13;i++){
		if(strcmp(mchar,monthName[i])==0)
			m=i;
		}
		int sum = buf[y][m][d]- buf[2014][2][28];

		//printf("%d",buf[date.year][date.month][date.day]);
		printf("%s\n",weekName[((sum+4)%7+7)%7]);
	}
	


	return 0;
}


