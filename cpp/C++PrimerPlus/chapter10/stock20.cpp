#include <iostream>
#include "stock20.h"
#include <cstdlib>

using namespace std;

/*
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
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
};
*/

Stock::Stock()
{
	cout << "default constructor called" << endl;
	m_company = "no name";
	m_shares = 0.0;
	m_share_val = 0.0;
	m_total_val = 0.0;//why don't call set_tot() ?
}

Stock::Stock(const std::string &co, long n, double pr)
{
	cout << "constructor using " << co << " called" << endl;
	m_company = co;
	if(n < 0)
	{
		cout << "construct stock err.\n";
		exit(1);
	}
	m_shares = n;
	m_share_val = pr;
	set_tot();
}
//destructor
Stock::~Stock()
{
	cout << "Bye, " << m_company << endl;
}

void Stock::buy(long num, double price)
{
	m_shares += num;
	m_share_val = price;
	set_tot();
}

void Stock::sell(long num, double price)
{
	m_shares -= num;
	m_share_val = price;
	set_tot();
}

void Stock::update(double price)
{
	m_share_val = price; 
	set_tot();
}

void Stock::show() const
{
	std::streamsize prec = cout.precision(3);
	std::ios_base::fmtflags flag = cout.setf(std::ios_base::fixed);
	cout << "company: " << m_company << endl;
	cout << "num: " << m_shares << endl;
	cout << "value: " << m_share_val << endl;
	cout << "total value: " << m_total_val << endl;
	cout.precision(prec);
	cout.setf(flag, std::ios_base::floatfield);
}

const Stock & Stock::topval(const Stock & s) const
{
	if(m_total_val > s.m_total_val)
		return *this;
	else
		return s;
}
