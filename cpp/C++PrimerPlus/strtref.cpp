#include <iostream>
using namespace std;

struct free_throw{
	string name;
	int made;
	int attemps;
	float percent;
};

void set_ft(free_throw & ft);
void display_ft(const free_throw & ft);
free_throw & accumulate(free_throw & target, const free_throw & source);

int main()
{
	free_throw one = {"Ifelsa Branch", 13, 14};
	free_throw two = {"Andor Knott", 10, 16};
	free_throw three = {"Minnie Max", 7, 9};
	free_throw four = {"Whily Looper", 5, 9};
	free_throw five = {"Long Long", 6, 14};
	free_throw team = {"Throwgroup", 0, 0};
	
	free_throw dup;
	
	set_ft(one);
	display_ft(one);
	accumulate(team, one);
	display_ft(team);
	display_ft(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display_ft(team);
	
	dup = accumulate(team, five);
	
	cout << "Displaying team: \n";
	display_ft(team);
	cout << "Displaying dup atfer assignment.\n";
	display_ft(dup);
	set_ft(four);
	
	accumulate(dup, five) = four;
	cout << "Displaying dup after ill-advise assignment:"  << endl;
	display_ft(dup);
	return 0;
}

void set_ft(free_throw & ft)
{
	if(ft.attemps != 0)
		ft.percent = ft.made / ft.attemps;
	else
		ft.percent = 0;
}

void display_ft(const free_throw & ft)
{
	cout << "Name: " << ft.name << endl;
	cout << "Made: " << ft.made;
	cout << "\tAttemps: " << ft.attemps;
	cout << "\tpercent: " << ft.percent << endl;
}

free_throw & accumulate(free_throw & target, const free_throw & source)
{
	target.made += source.made;
	target.attemps += source.attemps;
	
	target.percent = target.made / target.attemps;
	return target;
}
