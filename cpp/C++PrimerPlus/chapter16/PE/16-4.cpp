#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int reduce(long ar[], int n);
int main()
{
	long arr[10] = {1, 3, 3, 5, 5, 7, 7, 7, 8, 9};
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "process: \n";
	int len;
	len = reduce(arr, 10);
	for(int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << "len = " << len << endl;
	
	return 0;
}

#if 0
//version 1 : use sort() 、unique()
int reduce(long ar[], int n)
{
	long * p = ar;
	int len;
	
	sort(p, p + n);
	len = unique(p, p + n) - ar;
	
	return len;
}
#else
//version 2: use set
int reduce(long ar[], int n)
{
	set<long> arset(ar, ar + n);
	copy(arset.begin(), arset.end(), ar);
	return arset.size();
}
#endif
