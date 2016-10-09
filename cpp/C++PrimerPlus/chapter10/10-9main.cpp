#include <iostream>
#include "10-9Bank.h"

/*

	Bankaccount(string name = "test", string actnum = "123456789012345678", saving = 100000000);
	void show() const;
	bool save(const double money);
	bool get(const double money);

*/

int main()
{
	using namespace std;
	double dm;
	//test initialization
	Bankaccount b1;
	Bankaccount b2("张三", "21423412341", 1000000.00);
	Bankaccount b3 = Bankaccount("李四", "23472385023", 500000.00);
	
	b1.show();
	b2.show();
	b3.show();
	
	cout << "张三 get money: " ;
	cin >> dm;
	b2.get(dm);
	b2.show();
	cout << "李四 save money: ";
	cin >> dm;
	b3.save(dm);
	b3.show();
	
	return 0;
}