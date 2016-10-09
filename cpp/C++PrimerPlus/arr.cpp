#include <iostream>

int main()
{
	using namespace std;
	
	short arri[2][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {11, 22, 33, 44, 55, 66, 77, 88, 99, 100}};
	double arrd[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
	short *p1 = arri[2];
	short (*p2)[10] = arri;
	
	cout << "p2 = " << p2 <<endl;
	cout << "p2 + 1 = " << p2 + 1 << endl;
	
	cout << "&arri[0][0] = " << &arri[0][0] << endl;
	cout << "&arri[0][0] + 1 = " << &arri[0][0] + 1 << endl;
	cout << "&arri[0] = " << &arri[0] << endl;
	cout << "&arri[0] +1 = " << &arri[0] + 1<< endl;
	cout << "arri = " << arri <<endl;
	cout << "arri + 1 = " << arri + 1 << endl;
	cout << "&arri = " << &arri <<endl;
	cout << "&arri + 1 = " << &arri + 1 << endl;
	return 0;
}
