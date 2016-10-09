#include <iostream>
#include <cstdio>
#include <iomanip>

int main()
{
	using namespace std;
	
	int val = 0x01020304;
	unsigned char ch;
	
	cout << hex << showbase;
	cout << "val address: " << &val << "  val = "  << val << endl;
	for(int i = 0; i < sizeof(int); i++)
	{
		ch = *((char *)&val + i);
		cout << (void *)((char *)&val + i) << ": " << (int)ch << endl;
	}
	
	return 0;
}
