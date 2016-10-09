#include <iostream>
#include "14-5.h"

using namespace std;

//class abstr_emp
abstr_emp::abstr_emp()
{
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, 
		const std::string & j)
{
	fname = fn;
	lname = ln;
	job = j;
}
abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const
{
	cout << "name: " << lname << ", " << fname << endl;
	cout << "job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Please enter the last name: ";
	cin >> lname;
	cout << "Please enter the first name: ";
	cin >> fname;
	while(cin.get() != '\n')
		continue;
	cout << "Please enter your job: ";
	getline(cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	os << e.lname << ", " << e.fname;
	return os;
}

// class emplyee

employee::employee()
{
	
}

employee::employee(const std::string &fn, const std::string &ln, const std::string &j) : abstr_emp(fn, ln, j)
{
	
}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::ShowAll();
}

/*
class manager: virtual public abstr_emp
*/
manager::manager() {}
manager::manager(const std::string &fn, const std::string &ln, const std::string &j, int ico) : abstr_emp(fn, ln, j)
{
	inchargeof = ico;
}


manager::manager(const abstr_emp & e, int ico) : abstr_emp(e)
{
	inchargeof = ico;
}

manager::manager(const manager & m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "inchargeof: " << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Please enter number of your inchargeof: ";
	cin >> inchargeof;
}
/*
class fink : virtual public abstr_emp
*/

fink::fink(){}
fink::fink(const std::string & fn, const std::string &ln, 
		 const std::string & j, const std::string &rpo) : abstr_emp(fn, ln, j)
{
 reportsto = rpo;
}

fink::fink(const abstr_emp & e, const std::string &rpo) : abstr_emp(e)
{
	reportsto = rpo;
}

fink::fink(const fink &e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "reports to: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "who do you want to report? ";
	cin >> reportsto;
}

/*
class highfink : public manger, public fink //manager fink
{
public:
	highfink();
	highfink(const std::string &fn, const std::string &ln, 
			 const std::string &j, const std::string &rpo, 
			 int ico);
	highfink(const abstr_emp &e, const std::string &rpo, int ico);
	highfink(const fink &f, int ico);
	highfink(const manager & m, const std::string &rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
};
*/

highfink::highfink() {}
highfink::highfink(const std::string &fn, const std::string &ln, 
		const std::string &j, const std::string &rpo, int ico)
		: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo){}
highfink::highfink(const fink &f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f) {}
highfink::highfink(const manager & m, const std::string &rpo)
	: abstr_emp(m), manager(m), fink(m, rpo){}
highfink::highfink(const highfink & h): abstr_emp(h), manager(h), fink(h){}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "inchargeof: " << manager::InChargeOf() << endl;
	cout << "reportsto: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "who do you want to report? ";
	cin >> fink::ReportsTo();
	cout << "Please enter number of your inchargeof: ";
	cin >> manager::InChargeOf();
}
