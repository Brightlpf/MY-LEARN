#include "mytime0.h"
#include <iostream>
using std::cout;
using std::endl;
/*
class Time{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time Sum(const Time &t) const;
	void Show() const;
	friend Time opterator*(double d, const Time &t) const;
};
*/

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	if(minutes > 59)
	{
		minutes %= 60;
		hours = hours++ % 24;
	}
}

void Time::AddHr(int h)
{
	hours += h;
	hours %= 24;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::Sum(const Time &t) const
{
	Time rt;
	
	rt.minutes = minutes + t.minutes;
	if(rt.minutes > 59)
	{
		rt.minutes %= 60;
		rt.hours++;
	}
	rt.hours =hours + t.hours;
	rt.hours %= 24;
	
	return rt;
}

Time Time::operator+(const Time &t) const
{
	Time rt;
	
	rt.minutes = minutes + t.minutes;
	rt.hours = hours + t.hours + rt.minutes/60;
	rt.minutes %= 60;
	return rt;
}

Time Time::operator*(double d) const
{
	Time rt;
	int m;
	
	m = d * (minutes + hours * 60);
	rt.hours = m / 60;
	rt.minutes = m % 60; 
	return rt;
}

void Time::Show() const
{
	cout << hours << " hours "<< minutes << " minutes " << endl;
}

Time operator*(double d, const Time &t)
{
	Time rt;	
	int m;
	
	m = d * (t.minutes + t.hours * 60);
	rt.hours = m / 60;
	rt.minutes = m % 60; 
	return rt;
}

ostream & operator<<(ostream & os, const Time &t)
{
	os << t.hours << " hours "<< t.minutes <<" minutes"<< endl;
	return os;
}