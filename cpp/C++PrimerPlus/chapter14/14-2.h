#ifndef _14_2_H_
#define _14_2_H_

#include <string>
#include <valarray>
#include "Pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

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


#endif