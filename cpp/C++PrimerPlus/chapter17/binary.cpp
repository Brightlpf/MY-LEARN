#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

struct planet{
	char name[40];
	double population;
	double gravity;
};

const char * file = "planets.dat";
	
int main()
{
	using namespace std;
	
	cout << fixed << left;
	planet pl;
	// display info in file planet.dat
	ifstream fin(file, ios_base::in | ios_base::binary);
	if(fin.is_open())
	{
		cout << "Here are the current contents of the planets.dat file:\n";
		fin.read((char *) &pl, sizeof(planet));
		while(fin)
		{
			cout.width(20);
			cout << pl.name << ": " << setprecision(0) << setw(12) <<pl.population
				 << setprecision(2) << setw(6) << pl.gravity << endl;
			fin.read((char *)&pl, sizeof(planet));
		}
		fin.close();
	}
	
	//get new planets info
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if(!fout.is_open())
	{
		cerr << "Creat file " << file << "failed!\n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter planet name (enter a blank line to quit): " << endl;
	while(cin.get(pl.name, 40))
	{
		cout << "Enter planetary population: ";
		cin >> pl.population;
		cout << "Enter planet's acceleration of gravity: ";
		cin >> pl.gravity;
		while(cin.get() != '\n')
			continue;
		fout.write((char *) &pl, sizeof(planet));
		cout << "Enter planet name (enter a blank line to quit): " << endl;
	}
	fout.close();
	
	//display
	cout << "\nHere are the current contents of the planets.dat file:\n";
	fin.open(file);
	if(!fin.is_open())
	{
		cerr << "open file " << file << "failed!\n";
		exit(EXIT_FAILURE);
	}
	fin.read((char *) &pl, sizeof(planet));
	while(fin)
	{
		cout.width(20);
		cout << pl.name << ": " << setprecision(0) << setw(12) <<pl.population
			 << setprecision(2) << setw(6) << pl.gravity << endl;
		fin.read((char *)&pl, sizeof(planet));
	}
	fin.close();
	
	cout << "Done.\n";
	return 0;
}