#include <iostream>

//no parameter
long double sum_value()
{
	
}

//one parameter
template <typename T>
long double sum_value(const T & val) { return val;}

//two or more parameter
template <typename T, typename ... Args>
long double sum_value(const T & val, Args... args);

int main()
{
	using std::cout;
	using std::endl;
	cout << "int : " << sum_value(10) << endl;
	cout << "int double : " << sum_value(10, 20.5) << endl;
	cout << "int double int: " << sum_value(10, 20.5, 30) << endl;
	cout << "int double char int: " << sum_value(10, 20.5, 'A', 10) << endl;

	return 0;
}

template <typename T, typename ... Args>
long double sum_value(const T & val, Args... args)
{
	return val + sum_value(args...);
}
