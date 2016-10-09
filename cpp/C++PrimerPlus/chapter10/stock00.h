#ifndef __STOCK00_H_
#define __STOCK00_H_

#include <string>

class Stock{
	private:
		std::string company;
		int shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val;};
	public:
		void acquire(const char * co, long n, double pr);
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
};

#endif