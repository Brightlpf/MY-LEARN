#include <iostream>
#include "brass.h"
#include <string>
#include <cstdlib>
using namespace std;

/*
class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string &s = "Nullbody", long an = -1,
		double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance()const;
	virtual void ViewAcct()const;
	virtual ~Brass(){}
};

//Brass Plus Account Class
class BrassPlus :public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string &s = "Nullbody", long an = -1, 
		double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct()const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) {maxLoan = m;}
	void ResetRate (double r){rate = r;}
	void ResetOwes() {owesBank = 0;}
};
*/
int main()
{
	const int CLIENTS = 4;
	string name;
	long tempacct;
	double bal;
	double advance;
	double loanrate;
	Brass * pbrass[CLIENTS];
	int acctkind;
	
	for(int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter your name: ";
		getline(cin, name);
		cout << "Enter your bankacct: ";
		cin >> tempacct;
		cout << "Enter your balance: ";
		cin >> bal;
		cout << "choose 1 for Brass account, 2 for BrassPlus account: ";
		
		while(!(cin >> acctkind) || (acctkind != 1 && acctkind != 2))
		{
			if(!cin)
			{
				cin.clear();
				while(cin.get() != '\n')
					continue;
			}
				
			cout << "Please enter either 1 or 2.\n";
		}	
		
		if (acctkind == 1)
		{
			pbrass[i] = new Brass(name, tempacct, bal);
		}
		else 
		{
			cout << "enter the max limit: ";
			cin >> advance;
			cout << "enter the loan rate: ";
			cin >> loanrate;
			pbrass[i] = new BrassPlus(name, tempacct, bal, advance, loanrate);
		}
		while(cin.get() != '\n')
				continue;
	}
	cout << endl;
	for(int i = 0; i < CLIENTS; i++)
	{
		pbrass[i]->ViewAcct();
		cout << endl;
	}
		
	for(int i = 0; i < CLIENTS; i++)
		delete pbrass[i];
	cout << "Done.\n";
	
	return 0;
}
