#include "11-5.h"
#include <iostream>

using namespace std;
/*
class Stonewt{
private:
	enum{Lbs_per_stn = 14};
	enum Mode{STONE, PDS_INT, PDS_DB} mode;//英石模式， int 磅模式， double 磅模式
	int stone;
	double pds_left;
	double pounds;
public:
	explicit Stonewt(double lbs);// char l
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;
	//conversion function
	operator int() const;
	operator double() const;
	//overload + - *
	Stonewt operator+(const Stonewt & stw) const;
	Stonewt operator-(const Stonewt & stw) const;
	Stonewt operator*(const double d) const;
	//overload <<
	friend ostream & operator<<(ostream &os, const Stonewt & stw);
	friend Stonewt operator*(const double d, const Stonewt & stw); 
	
};
*/
void display(Stonewt & stw);

int main()
{
	Stonewt s1(25.6);
	Stonewt s2(12.5);
	Stonewt sum;
	int i;
	
	sum = s1 + s2;
	cout << "s1 + s2 = "<< endl;
	display(sum);
	sum = s1 - s2;
	cout << "s1 - s2 = " << endl;
	display(sum);
	sum = s1 * 2.0;
	cout << "s1 * 2 = " << endl;
	display(sum);
	sum = 3.0 * s1;
	cout << "3 * s1 = " << endl;
	display(sum);
	
	return 0;
	
}

void display(Stonewt &stw)
{
	//STONE, PDS_INT, PDS_DB
	stw.setmode(0);
	cout << "STONE mode: " << stw << endl;
	stw.setmode(1);
	cout << "PDS_INT mode: " << stw << endl;
	stw.setmode(2);
	cout << "PDS_DB mode: " << stw << endl;
	
}