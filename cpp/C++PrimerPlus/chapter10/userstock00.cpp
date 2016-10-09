#include <iostream>
#include "stock00.h"

/*
class Stock{
	private:
		string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val;};
	public:
		void acquire(const char * co, int n, double pr);
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
}
*/

int main()
{
	Stock fluffy_the_cat;
	fluffy_the_cat.acquire("konka", 100, 23);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(20, 24.5);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(30, 22.5);
	fluffy_the_cat.show();
	fluffy_the_cat.update(25.3);
	fluffy_the_cat.show();
	return 0;
	
}