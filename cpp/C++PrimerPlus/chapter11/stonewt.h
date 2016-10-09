#ifndef __STONEWT_H_
#define __STONEWT_H_
#include <iostream>

using std::ostream;

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
	Stonewt operator*(const Stonewt & stw) const;
	//overload <<
	friend ostream & operator<<(ostream &os, const Stonewt & stw);
	
};
#endif
