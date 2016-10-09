#include <iostream>
#include "stackp1.h"


//template <typename T> class 是参数类型， Thing 是参数(也是一个模板)
template <template <typename T> class Thing>
class Crab{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {}
	bool push(int i, double d);
	bool pop(int & i, double & d);
};

template <template <typename T> class Thing>
bool Crab<Thing>::push(int i, double d)
{
	if(!s1.push(i) || !s2.push(d))
		return false;
	return true;
}

template <template <typename T> class Thing>
bool Crab<Thing>::pop(int & i, double & d)
{
	if(!s1.pop(i) || !s2.pop(d))
		return false;
	return true;
}

int main()
{
	using namespace std;
	Crab<Stack> st;
	cout << "Enter int double pairs: 0 0 to quit ";
	int ni;
	double nd;
	while(cin >> ni >> nd && ni >0 && nd > 0)
	{
		if(!st.push(ni, nd))
			break;
		cout << "next: ";
	}
	while(st.pop(ni, nd))
		cout << ni << ", " << nd << endl;
	cout << "Done.\n";
	
	return 0;
}