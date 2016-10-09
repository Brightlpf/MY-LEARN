#include <iostream>
#include <string>
#include <utility>

using namespace std;
class Cpmv{
public:
	struct Info{ std::string qcode; std::string zcode;};
private:
	Info *pi;
public:
	Cpmv();
	Cpmv(std::string q, std::string s);
	Cpmv(const Cpmv & cp);
	Cpmv(Cpmv && mv);
	~Cpmv();
	Cpmv & operator=(const Cpmv & cp);
	Cpmv & operator=(Cpmv && mv);
	Cpmv operator+(const Cpmv & obj)const;
	void Display() const;
};

//implement
Cpmv::Cpmv()
{
	cout << "default construct called!" << endl;
	pi = new Info;
	pi->qcode = "default";
	pi->zcode = "default";
}

Cpmv::Cpmv(string q, string z)
{
	cout << "string string construct called!" << endl;
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp)
{
	cout << "copy constructer called!\n";
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv)
{
	cout << "move constructor called!\n";
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
	cout << "destroy constructer~~~~~~~~\n";
	delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
	cout << "copy operator=  called.\n";
	if(&cp == this)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
	cout << "move operator= called.\n";
	if(&mv == this)
		return *this;
	delete pi;
	pi = mv.pi;
	mv.pi = nullptr;
	
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj)const
{
	cout << "Enter into operator+" << endl;
	Cpmv temp;
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;
	cout << "Leave operator+" << endl;
	
	return temp;
}

void Cpmv::Display() const
{
	if(pi != nullptr)
	{
		cout << "qcode = " << pi->qcode << endl;
		cout << "zcode = " << pi->zcode << endl;
	}
	else
	{
		cout << "empty object!\n";
	}
}


int main()
{
	string s1("hello");
	string s2("world");
	Cpmv one;
	cout << "one: " << endl;
	one.Display();
	Cpmv two(s1, s2);
	cout << "two: " << endl;
	two.Display();
	Cpmv three(two);
	cout << "three: " << endl;
	three.Display();
	Cpmv four(one + two);
	cout << "four: " << endl;
	four.Display();
	
	one = two;
	cout << "one: " << endl;
	one.Display();
	
	one = two + three;
	cout << "one: " << endl;
	one.Display();
	
	cout << "std::move :" << endl;
	Cpmv five(move(one));
	cout << "five: " << endl;
	five.Display();
	
	return 0;
}










