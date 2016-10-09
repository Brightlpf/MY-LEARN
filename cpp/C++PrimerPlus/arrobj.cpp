#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Season = 4;
const array<string, Season> Snum = {"Spring", "Summer", "Fall", "Winter"};
void fill(array<double, Season> * parr);
void show(array<double, Season> arr);

int main()
{
	array<double, Season> arr;
	
	fill(&arr);
	show(arr);
	return 0;
}

void fill(array<double, Season> * parr)
{
	for(int i = 0; i < Season; i++)
	{
		cout << "Enter " << Snum[i] << " expenses: ";
		cin >> (*parr)[i];
	}

}

void show(array<double , Season> arr)
{
	double sum = 0.0;
	
	cout << "EXPENSES: " << endl;
	for(int i = 0; i < Season; i++)
	{
		cout << Snum[i] << " : "<< arr[i] << endl;
		sum += arr[i];
	}
	cout << endl << "Total: " << sum << endl;
}
