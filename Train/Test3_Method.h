#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
private:
	int h, m, s;
public:
	Time(int hour=0, int min=0, int sec=0) :h(hour), m(min), s(sec) {};
	void GetHour() const;
	void GetSec() const;
	void GetMin() const;
	void ShowTime() const;
	void SetTime();
	Time operator+(Time& time);
};
