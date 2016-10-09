#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	int size;
	
	cout << "Enter the size of array: ";
	cin >> size;
	int *parr = new int [size];
	//cout << "NEW: strlen(parr) = " << strlen(parr) << endl;
	delete [] parr;
	
	cout << "Enter the size of array another: ";
	cin >> size;
	vector<int> pvec(size);
	//cout << "VECTOR: strlen(parr) = " << strlen(parr) << endl;
	return 0;
}
