#include "11-6.h"
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
	void setmode(const int m);
	//conversion function
	operator int() const;
	operator double() const;
	//overload + - *
	Stonewt operator+(const Stonewt & stw) const;
	Stonewt operator-(const Stonewt & stw) const;
	Stonewt operator*(const double d) const;
	bool operator>(const Stonewt & stw)const;
	bool operator<(const Stonewt & stw)const;
	bool operator==(const Stonewt & stw)const;
	bool operator>=(const Stonewt & stw)const;
	bool operator<=(const Stonewt & stw)const;
	bool operator!=(const Stonewt & stw)const;
	
	//overload <<
	friend ostream & operator<<(ostream &os, const Stonewt & stw);
	friend Stonewt operator*(const double d, const Stonewt & stw); 
	
};
*/
int main()
{
	double temp;
	//Stonewt stw[6] = {Stonewt(159.88), Stonewt(153.9), Stonewt(189.4)};
	Stonewt stw[6] = {159.88, 153.9, 189.4};
	cout << "Enter pounds: ";
	for(int i = 0; i < 3; i++)
	{
		if(i != 0)
			cout << "next: ";
		cin >> temp;
		stw[i+3] = temp;
	}
	
	Stonewt stw11(11, 0.0);
	Stonewt min;
	Stonewt max;
	
	min = max = stw[0];
	for(int i = 1; i < 6; i++)
	{
		if(min > stw[i])
		{
			min = stw[i];
		}
		if(max < stw[i])
		{
			max = stw[i];
		}
		if(stw[i] >= stw11)
		{
			cout << "index " << i << ": " << stw[i] <<endl;
		}
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	return 0;
}
