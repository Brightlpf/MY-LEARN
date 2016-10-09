#include <iostream>
#include <cstring>

using namespace std;
const int Arsize = 80;

char * left(const char * str, int n = 1);
int main()
{
	char temp[Arsize];
	
	cout << "Enter a string: ";
	cin.get(temp, Arsize);
	
	char *ps = left(temp, 3);
	cout << ps << endl;
	delete [] ps;
	
	ps = left(temp);
	cout << ps << endl;
	delete [] ps;
	return 0;
}

char * left(const char * str, int n)
{
	if (n < 0)
		n = 0;
	char * ps = new char[n + 1];
	strncpy(ps, str, n);
	ps[n] = '\0';
	return ps;
}
