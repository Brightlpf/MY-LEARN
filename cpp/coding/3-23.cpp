#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
	bitset<64> bitvec(32);
	bitset<32> bv(1010101);
	string bstr;
	
	cin >> bstr;
	bitset<8> bvs(bstr);


	cout << "bitvec: " << bitvec << endl;
	cout << "bitvec: " << bitvec.to_ulong() << endl;
	cout << "bv: " << bv << endl;
	cout << "bstr: " << bstr << endl;
	return 0;
}
