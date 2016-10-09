#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//1. copy array to vector(not empty)
	int array[10];
	for(int i = 0; i < 10; i++)
		array[i] = i;
	cout << "copy array to vector: " << endl;
	vector<int> vi(10);
	copy(array, array + 10, vi.begin());
	//2. display vector
	cout << "display vector by output iterator: \n";
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(vi.begin(), vi.end(), out_iter);
	/*
	//3. input to vector 
	cout << "Input to vector by input iterator: \n";
	//istream_iterator<int, char> in_iter(cin);  //called cin , so need input
	copy(istream_iterator<int , char> (cin), istream_iterator<int, char>(), vi.begin());
	copy(vi.begin(), vi.end(), out_iter);
	
	//4. copy array to vector(empty)
	cout << "back insert input to vector: " << endl;
	copy(istream_iterator<int , char> (cin), istream_iterator<int, char>(), back_insert_iterator<vector<int> >(vi));
	copy(vi.begin(), vi.end(), out_iter);
	*/
	//5. copy input to vectory(empty) by insert
	cout << "insert input to vector: " << endl;
	copy(istream_iterator<int , char> (cin), istream_iterator<int, char>(), insert_iterator<vector<int> >(vi, vi.end()));
	copy(vi.begin(), vi.end(), out_iter);
	
	return 0;
}