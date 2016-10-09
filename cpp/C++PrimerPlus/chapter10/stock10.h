#ifndef __STOCK00_H_
#define __STOCK00_H_

#include <string>

class Stock{
	private:
		std::string m_company;
		long m_shares;
		double m_share_val;
		double m_total_val;
		void set_tot(){m_total_val = m_shares * m_share_val;};
	public:
		Stock();  //default constructor
		Stock(const std::string & co, long n = 0, double pr = 0.0);
		//void acquire(const char * co, long n, double pr);
		~Stock();
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
};

#endif