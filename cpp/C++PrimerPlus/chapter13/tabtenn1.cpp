#include "tabtenn1.h"
#include <iostream>

using std::cout;
using std::endl;
TableTennisPlayer::TableTennisPlayer(const string &fn,
 const string &ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
 {
	 std::cout << "TableTennisPlayer(base) construct" << endl;
 }
 
 void TableTennisPlayer::Name() const
 {
	 std::cout << lastname << ", "<< firstname;
 }
 
 //RatedPlayer methods
 
 RatedPlayer::RatedPlayer(unsigned int r, const string &fn, 
 const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht)
 {
	 rating = r;
	 cout << "RatedPlayer(derive) construct"<< endl;
 }
 
 RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
	: TableTennisPlayer(tp), rating(r)
	{
		cout << "RatedPlayer(derive) construct"<< endl;
	}
	