#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

static int DayOfMonth[12];
inline void init(){
	DayOfMonth[1] = DayOfMonth[3] = DayOfMonth[5] = 
	DayOfMonth[7] = DayOfMonth[8] = DayOfMonth[10] = 
	DayOfMonth[12] = 31;
	DayOfMonth[4] = DayOfMonth[6] = DayOfMonth[9] = 
	DayOfMonth[11] = 30;
}
inline bool is_special_year(int x){
	return ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
}
inline int day_of_month(int year, int month){
	if(month == 2){
		if(is_special_year(year))
			return 29;
		else return 28;
	}
	else return DayOfMonth[month];
}
struct Date{
	int year, month, day;
	inline void print(){
		cout << year << ' ' << month << ' ' << day << endl; 
	}
};
inline bool operator != (const Date& x, const Date& y){
	return (x.day != y.day || x.month != y.month || x.year != y.year);
}
inline Date NewDate(int _,int __,int ___){
		Date Temp;
		Temp.year = _, Temp.month = __, Temp.day = ___;
		return Temp;
	}
inline Date NextDate(Date& x){
	int day = x.day, month = x.month, year = x.year;
	day ++;
	if(day > day_of_month(year, month)){
		day = 1; month ++;
		if(month > 12) month = 1, year ++;
	}
	Date tmp = NewDate(year, month, day);
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	init();
	Date Start = NewDate(1901, 1, 1), end = NewDate(2000, 12, 31);
	int Day = 0, ans = 1;
	while(Start != end){
		if(Start.day == 1 && Day == 6) ans ++;
		Start = NextDate(Start); Day = (Day + 1) % 7;
	}
	cout << ans << endl;
	return 0;
}
