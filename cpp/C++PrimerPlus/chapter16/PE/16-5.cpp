#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

template<class T>
int reduce(T ar[], int n)
{
	set<T> arset(ar, ar + n);
	copy(arset.begin(), arset.end(), ar);
	return arset.size();
}

int main()
{
	long arr[10] = {1, 3, 3, 5, 5, 7, 7, 7, 8, 9};
	string str[6] = {"array", "back_insert_iterator", "zippy", "dog", "cat", "ok"};
	
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 0; i < 6; i++)
		cout << str[i] << " ";
	cout << endl;
	
	cout << "process: \n";
	int len;
	len = reduce(arr, 10);
	for(int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << "len = " << len << endl;
	
	len = reduce(str, 6);
	for(int i = 0; i < len; i++)
		cout << str[i] << " ";
	cout << "len = " << len << endl;
	
	return 0;
}


