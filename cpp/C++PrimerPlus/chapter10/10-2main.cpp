#include "10-2.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.show();
	cout << endl;
	one.FormalShow();
	
	two.show();
	cout << endl;
	two.FormalShow();
	three.show();
	cout << endl;
	three.FormalShow();
	
	return 0;
}