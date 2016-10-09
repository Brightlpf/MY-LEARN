#include <iostream>
#include "studenti.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

std::ostream & Student::arr_out(std::ostream & os) const
{
	int lim = ArrayDb::size();
	if(lim > 0)
	{
		for(int i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if(i % 5 == 4)
				os << endl;
		}
		if(lim != 5)
			os << endl;
	}
	else
	{
		os << "empty array.\n";
	}
	return os;
}

double Student::Average() const
{
	if(ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

const std::string & Student::Name() const
{
	return (const string &) *this;
}

double & Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}

const double & Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

std::istream & operator>> (std::istream & is, Student & stu)
{
	is >> (string &)stu;
	return is;
}

istream & getline(std::istream & is, Student & stu)
{
	getline(is, (string &)stu);
	return is;
}

std::ostream & operator<< (std::ostream & os, const Student &stu)
{
	os << (const string &)stu << endl;
	stu.arr_out(os);
	return os;
}















