#include <iostream>
#include <vector>
#include <array>

int main()
{
	using namespace std;
	//C ORIGINAL C++
	double a1[4] = {1.2, 2.4, 3.6, 4.8};
	//c++ 98 STL
	vector<double> a2(4);
	a2[0] = 1.0/3.0;
	a2[1] = 1.0/5.0;
	a2[2] = 1.0/7.0;
	a2[3] = 1.0/9.0;
	//C++ 11
	array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
	array<double, 4> a4;
	a4 = a3;
	
}