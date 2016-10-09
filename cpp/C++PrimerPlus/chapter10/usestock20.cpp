#include <iostream>
#include "stock20.h"
using namespace std;

int main()
{
	cout << "Using constructors to create new objects" << endl;
	Stock stock1("NanSmart", 12, 20.0);
	stock1.show();
	Stock stock2 = Stock("Boffo Objects", 2, 2.0);
	stock2.show();
	
	cout << "Return the bigger: \n";
	stock1.topval(stock2).show();
	
	return 0;
}
