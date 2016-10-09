#include <iostream>
using namespace std;

struct CandyBar {
	char brand[20];
	float weight;
	int cll;
};

int main(void)
{
	CandyBar snack = {"Mocha Munch", 2.3, 350};
	
	cout << snack.brand << ", "<< snack.weight <<", "<< snack.cll << endl;
	return 0;
}
