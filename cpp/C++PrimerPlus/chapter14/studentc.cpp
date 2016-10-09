#include <iostream>
#include "studentc.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

/*
class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;
	ArrayDb scores;
	std::ostream & arr_out(std::ostream & os) const;
public:
	Student(): name("Null student"), scores() {}
	explicit Student(const std::string & s) : name(s), scores(){}
	explicit Student(int n): name("Nully"), scores(n){}
	Student(const std::string & s, int n) : name(s), scores() {}
	Student(const char * s, const double * pd, int n) : name(s), scores(pd, n) {}
	Student(const std::string & s, const ArrayDb & a) : name(s), scores(a){}
	~Student() {}
	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);
	double & operator[](int i) const;
	friend std::istream & operator>> (std::istream & is, Student & stu);
	friend Student & getline(std::istream & is, Student & stu);
	friend std::ostream & operator<< (std::ostream & os, const Student &std);
};
*/

std::ostream & Student::arr_out(std::ostream & os) const
{
	int lim = scores.size();
	if(lim > 0)
	{
		for(int i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
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
	if(scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}

const std::string & Student::Name() const
{
	return name;
}

double & Student::operator[](int i)
{
	return scores[i];
}

const double & Student::operator[](int i) const
{
	return scores[i];
}

std::istream & operator>> (std::istream & is, Student & stu)
{
	is >> stu.name;
	return is;
}

istream & getline(std::istream & is, Student & stu)
{
	getline(is, stu.name);
	return is;
}
std::ostream & operator<< (std::ostream & os, const Student &stu)
{
	os << stu.name << endl;
	stu.arr_out(os);
	return os;
}















