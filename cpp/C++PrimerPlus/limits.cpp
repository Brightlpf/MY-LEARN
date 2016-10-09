#include <iostream>
#include <climits>

int main(void)
{
	using namespace std;
	
	short n_short = SHRT_MAX;
	int n_int = INT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;
	
	cout << "short is "<<sizeof(short)<< " Byte"<<endl;
	cout << "int is "<< sizeof(int)<< " Byte"<<endl;
	cout << "long is "<< sizeof(long)<<" Byte"<<endl;
	cout << "long long is "<<sizeof(long long)<< " Byte"<<endl;
	cout << endl;
	
	cout << "Max value: \n";
	cout << "short: "<<n_short<<endl;
	cout << "int: "<<n_int<<endl;
	cout << "long: "<<n_long<<endl;
	cout << "long long: "<< n_llong<<endl;
	
	return 0;
}