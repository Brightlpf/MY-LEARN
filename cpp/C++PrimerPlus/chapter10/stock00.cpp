#include "stock00.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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

void Stock::acquire(const char *co, long n, double pr)
{
	company = co;
	shares = n;
	share_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	shares += num;
	share_val = price;
	set_tot();
}

void Stock::sell(long num, double price)
{
	shares -= num;
	share_val = price;
	set_tot();
}

void Stock::update(double price)
{
	share_val = price; 
	set_tot();
}

void Stock::show()
{
	std::streamsize prec = cout.precision(3);
	std::ios_base::fmtflags flag = cout.setf(std::ios_base::fixed);
	cout << "company: " << company << endl;
	cout << "num: " << shares << endl;
	cout << "value: " << share_val << endl;
	cout << "total value: " << total_val << endl;
	cout.precision(prec);
	cout.setf(flag, std::ios_base::floatfield);
}
