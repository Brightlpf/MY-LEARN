#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void show(int ival);
int main()
{
	vector<int> vi;
	for(int i = 0; i < 3; i++)
		vi.push_back(i);
	for_each(vi.begin(), vi.end(), show);
	cout << endl;
	
	vector<int> vi2(3);
	for(int i = 0; i < 3; i++)
		vi2[i] = -(i+1);
	cout << "insert one element at vi.begin()" << endl;
	vi.insert(vi.begin(), vi2.begin(), vi2.begin() + 1);
	for_each(vi.begin(), vi.end(), show);
	cout << endl;
	
	cout << "insert at vi.end()" << endl;
	vi.insert(vi.end(), vi2.begin(), vi2.end());
	for_each(vi.begin(), vi.end(), show);
	cout << endl;
	
	
	return 0;
}

void show(int ival)
{
	cout << ival << " ";
}
