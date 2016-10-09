#include <iostream>
#include "mytime0.h"

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
	Time operator+(const Time &t) const;
	Time operator*(double d) const;
	void Show() const;
	friend Time operator*(double d, const Time &t);
};
*/

using std::cout;
using std::endl;

int main()
{
	Time coding(2, 30);
	Time fixing(5, 55);
	
	cout << "coding: ";
	coding.Show();
	cout << "fixing: ";
	fixing.Show();
	
	Time total;
	cout << "coding * 2: ";
	total = coding * 2;
	total.Show();
	cout << "3 * fixing: ";
	total =  3 * fixing;
	total.Show();
	cout << "operator<<: "<< total;
	
	cout << "continue: "<< total << "no problem.\n";
	return 0;
}