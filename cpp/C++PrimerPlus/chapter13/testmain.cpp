#include "test.h"
#include <iostream>

using std::cout;
using std::endl;
int main()
{
	Test t;
	Testplus tp;
	
	Test & tr = tp;
	tr.show();
	
	return 0;
}