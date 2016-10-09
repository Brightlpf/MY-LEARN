#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 40;
struct CandyBar{
	char brand[MAX];
	double weight;
	int heat;
};
void fillcb(CandyBar & cb, const char * pb = "Millenium Munch", double w = 2.85, int h = 350);
void showcb(const CandyBar & cb);

int main()
{
	CandyBar cb1;
	
	cout << "default cb: "<< endl;
	fillcb(cb1);
	showcb(cb1);
	cout << "seted cb: "<< endl;
	fillcb(cb1, "apple", 5.2, 20);
	showcb(cb1);
	return 0;
}

void fillcb(CandyBar & cb, const char * pb, double w, int h)
{
	if (NULL == pb)
	{
		exit(1);
	}
	int i;
	for(i = 0; pb[i] != '\0' && i < MAX -1; i++)
	{
		cb.brand[i] = pb[i];
	}
	cb.brand[i] = '\0';
	cb.weight = w;
	cb.heat = h;
}
void showcb(const CandyBar & cb)
{
	cout << cb.brand << "\t";
	cout << cb.weight << "\t";
	cout << cb.heat << endl;
}
