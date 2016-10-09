#include <iostream>
#include "stonewt.h"

using namespace std;

/*
class Stonewt{
private:
	enum{Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);// char l
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;
	//conversion function
	operator int() const;
	operator double() const;
};
*/

int main()
{
	//test int_to stonewt double_to_ stonewt  implict conversion 
	Stonewt st_n;
	Stonewt st_d;
	
	st_n = (Stonewt)100;
	st_d = (Stonewt)3.1415;
	cout << "test implict conversion to stonewt"<< endl;
	st_n.show_lbs();
	cout << endl;
	st_d.show_stn();
	cout << endl;
	
	//test stonewt to int stonewt to double implict conversion
	double d = st_n;
	int n = st_d;
	cout << "test implict conversion to int and double"<< endl;
	cout << d << endl;
	cout << n << endl;
	
	
	return 0;
}