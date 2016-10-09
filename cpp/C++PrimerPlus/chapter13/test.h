#include <iostream>
#include <cstring>

using namespace std;
class Test{
private:
	char str[20];
public:
	Test(const char * p = "Hello World") {strncpy(str, p, 19); str[19] = '\0';}
	virtual void show() const {cout << "str :" << str << endl;}
};

class Testplus : public Test{
private:
	char strp[20];
public:
	Testplus(const char * p = "Hello World", const char * p2 = "thanks") :Test(p)
	{
		strncpy(strp, p2, 19);
		strp[19] = '\0';
	}
	virtual void show() const {Test::show(); cout << "str2: " << strp << endl;}
};