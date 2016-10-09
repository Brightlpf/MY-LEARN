#include <iostream>
using std::cout;
#include "Stringbad.h"

void callme1(Stringbad &);
void callme2(Stringbad);

int main()
{
	using std::endl;
	cout << "Stringing an inner block.\n";
	Stringbad headline1("Celery Stalks at Midnight");
	Stringbad headline2("Lettuce Prey");
	Stringbad sports("Spinach Leaves Bowl for Dollars");
	
	cout << "headline1: " << headline1 << endl;
	cout << "headline2: " << headline2 << endl;
	cout << "sports: " << sports << endl;
	callme1(headline1);
	cout << "headline1: " << headline1 << endl;
	cout << "may occur problem...."<< endl<< endl;
	callme2(headline2);//when retrun , delete headline2
	cout << "headline2: " << headline2 << endl;
	cout << "Initialize one object to another: \n";
	Stringbad knot;
	knot = headline1;
	cout << "knot: " << knot << endl;
	cout << "Exiting the block.\n";
	
	cout << "End of main()\n";
	return 0;
	//delete knot --->delete headline1
	//delete sports
	//delete headline2  crash
	//delete headline1  crash
}

void callme1(Stringbad & rsb)
{
	cout << "String passed by reference: \n";
	cout << "	\""<< rsb << "\"\n";
}

void callme2(Stringbad sb)
{
	cout << "String passed by value: \n";
	cout << "	\t\"" << sb << "\"\n";
}
