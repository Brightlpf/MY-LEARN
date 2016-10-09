#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
	string bstr("1000000010000100101110");
	bitset<32> bs1(bstr);
	bitset<32> bs2;
	
	bs2.set(1);
	bs2.set(2);
	bs2.set(3);
	bs2.set(5);
	bs2.set(8);
	bs2.set(13);
	bs2.set(21);

	cout << "bs1: " << bs1 << endl;
	cout << "bs2: " << bs2 << endl;
	
	return 0;
}
