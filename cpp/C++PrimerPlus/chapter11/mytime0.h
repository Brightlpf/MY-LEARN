#ifndef __MYTIME0_H_
#define __MYTIME0_H_
#include <iostream>
using std::ostream;

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
	Time operator+(const Time &t) const;
	Time operator*(double d) const;
	void Show() const;
	friend Time operator*(double d, const Time &t);
	friend ostream & operator<<(ostream & os, const Time &t);
};
#endif 