#include "10-6.h"
#include <iostream>
using namespace std;

/*
class Move{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove() const;
	Move add(const Move &m) const;
	void reset(double a = 0, double b = 0);
};
*/

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	cout << "("<< x << ", "<< y << ")" << endl;
}

Move Move::add(const Move &m) const
{
	Move p;
	
	p.reset(m.x +x, m.y +y);
	return p; 
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
