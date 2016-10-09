#include <iostream>
#include "14-1.h"

using namespace std;
/*
class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	string label;
	int years;
	PairArray pairar;  //
public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBoottles();
	const string & Label() const;
	int Sum() const;
};
*/

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
	:label(l), years(y), pairar((valarray<int>)y, (valarray<int>)y)
{
	for(int i = 0; i < years; i++)
	{
		pairar.first()[i] = yr[i];
		pairar.second()[i] = bot[i];
	}
}

Wine::Wine(const char *l, int y)
	:label(l), years(y), pairar((valarray<int>)y, (valarray<int>)y)
{
	
}

void Wine::GetBottles()
{
	cout << "Enter " << label << "data for " << years << " year(s): " << endl;
	for(int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> (pairar.first())[i];
		cout << "Enter boottles for that years: ";
		cin >> (pairar.second())[i];
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
	return pairar.second().sum();
}

void Wine::Show() const
{
	cout << "Wine: " << label << endl;
	cout << "\tYear \tBottles" << endl;
	for(int i = 0; i < years; i++)
		cout << "\t" << (pairar.first())[i] << " \t" << (pairar.second())[i] << endl;
}
