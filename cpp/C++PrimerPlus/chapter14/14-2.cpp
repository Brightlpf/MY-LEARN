#include <iostream>
#include "14-2.h"

using namespace std;
/*
class Wine : private PairArray
{
private:
	std::string label;
	int years;
public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBottles();
	const std::string & Label() const;
	int Sum() const;
	void Show() const;
};
*/

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
	:label(l), years(y), PairArray((valarray<int>)y, (valarray<int>)y)
{
	for(int i = 0; i < years; i++)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}
}

Wine::Wine(const char *l, int y)
	:label(l), years(y), PairArray((valarray<int>)y, (valarray<int>)y)
{
	
}

void Wine::GetBottles()
{
	cout << "Enter " << label << "data for " << years << " year(s): " << endl;
	for(int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> (PairArray::first())[i];
		cout << "Enter boottles for that years: ";
		cin >> (PairArray::second())[i];
	}
	while(cin.get() != '\n')
		continue;
}

const string & Wine::Label() const
{
	return label;
}

int Wine::Sum() const
{
	return PairArray::second().sum();
}

void Wine::Show() const
{
	cout << "Wine: " << label << endl;
	cout << "\tYear \tBottles" << endl;
	for(int i = 0; i < years; i++)
		cout << "\t" << (PairArray::first())[i] << " \t" << (PairArray::second())[i] << endl;
}
