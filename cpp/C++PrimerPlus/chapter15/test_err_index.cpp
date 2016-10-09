#include <iostream>
#include <cstdlib>
#include "err_index.h"

using namespace std;

int main()
{
	int arr[10];
	
	try{
		for(int i = 0; i <= 10; i++)
		{
			if(i >= 10)
				throw err_index("main: bad arr_index\n");
			arr[i] = 10;
		}
	}
	catch (err_index &e){
		cout << e.what();
		cout << "forget it!\n";
	}
	for(int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
