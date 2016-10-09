#include <iostream>
#include "13-3.h"

void show(const DmaABC & ra);

int main()
{
	using std::cout;
	using std::endl;
	
	
	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	
	
	cout << "test operator<<: \n\n";
	cout << "Displaying baseDMA object: \n";
	cout << shirt << endl;
	
	cout << "Displaying lacksDMA object: \n";
	cout << balloon << endl;
	
	cout << "Displaying hasDMA object: \n";
	cout << map << endl;
	
	lacksDMA balloon2(balloon);
	cout << "Result of lacksDMA copy: \n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "Result of hasDMA assignment: \n";
	cout << map2 << endl;
	
	cout << "test ABC: \n\n";
	cout << "Displaying baseDMA object: \n";
	show(shirt);
	
	cout << "Displaying lacksDMA object: \n";
	show(balloon);
	
	cout << "Displaying hasDMA object: \n";
	show(map);
	
	
	return 0;
}

void show(const DmaABC & ra)
{
	ra.View();
}