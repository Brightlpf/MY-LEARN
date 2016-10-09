#include "customer.h"
#include <cstdlib>
/*
class Customer{
private:
	long arrivetime; 
	long processtime;
public:
	Customer(){arrivetime = 0; processtime = 0;}
	void set(long when);
	long when() const { return arrivetime;}
	int ptime() const {return processtime;}
};
*/

void Customer::set(long when)
{
	arrivetime = when;
	processtime = std::rand() % 3 + 1;  //minute
}
