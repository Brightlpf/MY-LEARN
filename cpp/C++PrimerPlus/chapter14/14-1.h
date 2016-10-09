#ifndef _14_1_H_
#define _14_1_H_

#include <string>
#include <valarray>
#include "Pair.h"

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	std::string label;
	int years;
	PairArray pairar;  //
public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBottles();
	const std::string & Label() const;
	int Sum() const;
	void Show() const;
};


#endif
