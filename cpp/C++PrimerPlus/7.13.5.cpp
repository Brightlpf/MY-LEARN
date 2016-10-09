#include <iostream>
using namespace std;

long fact(int n);

int main(void)
{
	int n;
	cout << "Enter a number(> 0)：";
	while(1)
	{
		cin >> n;
		while(n < 0)
		{
			cout << "Enter a number(> 0)：";
			cin >> n;
		}
		cout << n << "! = "<< fact(n) << endl;
		cout << "continue: \n";
	}
}

long fact(int n)
{
	if(n == 0 || n == 1)
		return 1;
	return n * fact(n - 1);
}
