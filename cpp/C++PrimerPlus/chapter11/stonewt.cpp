#include "stonewt.h"
#include <iostream>
using std::cout;
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
	Stonewt operator*(const Stonewt & stw) const;
	//overload <<
	friend Stonewt & operator<<(ofstream &os, const Stonewt & stw);
	
};
*/

Stonewt::Stonewt(double lbs)
{
	stone = lbs / Lbs_per_stn;
	pds_left = lbs - stone * Lbs_per_stn;
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	stone = 0;
	pds_left = pounds = 0.0;
}

Stonewt::~Stonewt()
{
	
}

void Stonewt::show_lbs() const
{
	cout << pounds << " pounds";
}

void Stonewt::show_stn() const
{
	cout << stone << " stone "<< pds_left << " pounds";
}


Stonewt::operator int() const
{
	return (int)(pounds + 0.5);
}


Stonewt::operator double() const
{
	return pounds;
}

//overload + - *
Stonewt Stonewt::operator+(const Stonewt & stw) const
{
	Stonewt sum;
	
	sum.pds_left = int(stw.pds_left + pds_left) % Lbs_per_stn  + stw.pds_left + pds_left - int(stw.pds_left + pds_left);
	sum.stone = stone + stw.stone + int((stw.pds_left + pds_left)/ Lbs_per_stn);
	sum.pounds = pounds + stw.pounds;
	
	return sum;
}

Stonewt Stonewt::operator-(const Stonewt & stw) const
{
	Stonewt sum;
	
	if(pds_left < stw.pds_left)
	{
		sum.pds_left = pds_left + Lbs_per_stn - pds_left;
		sum.stone = stone - stw.stone -1;
		sum.pounds = pounds - stw.pounds;
	}
	else
	{
		sum.pds_left = pds_left - pds_left;
		sum.stone = stone - stw.stone;
		sum.pounds = pounds - stw.pounds;
	}
	return sum;
}

Stonewt Stonewt::operator*(const Stonewt & stw) const
{
	Stonewt sum;
	
	sum.pds_left = int(stw.pds_left * pds_left) % Lbs_per_stn + stw.pds_left * pds_left - int(stw.pds_left * pds_left);
	sum.stone = stone * stw.stone + int((stw.pds_left + pds_left)/ Lbs_per_stn);
	sum.pounds = pounds * stw.pounds;
	
	return sum;
}
//overload <<
ostream & operator<<(ostream &os, const Stonewt & stw)
{
	switch(stw.mode)
	{
		case Stonewt::STONE  :
			os << stw.stone << " stone" << stw.pds_left << " pounds";
			break;
		case Stonewt::PDS_INT:
			os << (int)(stw.pounds + 0.5) << " pounds";
			break;
		case Stonewt::PDS_DB :
			os << stw.pounds << " pounds";
			break;
			default:
			cout << "unkonw mode\n";
	}
	return os;
}
