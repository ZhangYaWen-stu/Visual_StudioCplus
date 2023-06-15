#include"Test3_Method.h"
void Time::GetHour() const
{
	cout<<h<<endl;
}
void Time::GetSec() const
{
	cout<<s<<endl;
}
void Time::GetMin() const
{
	cout<<m<<endl;
}

void Time::ShowTime() const
{
	cout << h << ':' << m << ':' << s << endl;
}

void Time::SetTime()
{
	cout << "请输入时间(请不要输入：）" << endl;
	cin >> h >> m >> s;
}
Time Time::operator+(Time& time)
{
	Time temp;
	temp.s = (s + time.s) % 60;
	temp.m = (m + time.m + (s + time.s) / 60) % 60;
	temp.h = (h + time.h + (m + time.m) / 60) % 24;
	return temp;
}
