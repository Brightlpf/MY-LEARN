#include <iostream>
#include <string>
#include "10-9Bank.h"

using namespace std;

/*
class Bankaccount{
	private:
		string m_name;
		string m_actnum;
		double m_saving;
	public:
		Bankaccount(string name = "test", string actnum = "123456789012345678", saving = 0.0);
		void show() const;
		bool save(const double money);
		bool get(const double money);
};
*/

Bankaccount::Bankaccount(string name, string actnum, double saving)
{
	m_name = name;
	m_actnum = actnum;
	m_saving = saving;
	cout << "***********construct object success*************\n";
}

void Bankaccount::show() const
{
	streamsize prec = cout.precision(4);
	ios_base::fmtflags flag = cout.setf(ios_base::fixed,ios_base::floatfield);
	cout << "name: " << m_name;
	cout << "\taccount number: " << m_actnum << endl;
	cout << "saving: $" << m_saving <<  endl;
	cout.precision(prec);
	cout.precision(flag);
}

bool Bankaccount::save(const double money)
{
	if(money < 0)
		return false;
	m_saving += money;
	return true;
}

bool Bankaccount::get(const double money)
{
	if(m_saving < money)
		return false;
	m_saving -= money;
	return true;
}


