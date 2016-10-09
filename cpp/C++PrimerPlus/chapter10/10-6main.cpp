#include <iostream>
#include "10-6.h"
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

int main()
{
	Move m1(1, 1);
	cout << "m1: ";
	m1.showmove();
	cout << "m2: ";
	Move m2(2, 5);
	m2.showmove();
	cout << "m3: ";
	Move m3;
	m3 = m1.add(m2);
	m3.showmove();
	return 0;
}
