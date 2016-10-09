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
	int ct = 0; //count planet
	// display info in file planet.dat
	fstream frw(file, ios_base::in | ios_base::out);
	if(frw.is_open())
	{
		cout << "Here are the current contents of the planets.dat file:\n";
		frw.read((char *) &pl, sizeof(planet));
		while(frw)
		{
			cout << ct << setw(5) << "# ";
			cout.width(20);
			cout << pl.name << ": " << setprecision(0) << setw(12) <<pl.population
				 << setprecision(2) << setw(6) << pl.gravity << endl;
			frw.read((char *)&pl, sizeof(planet));
			ct++;
		}
		if(frw.eof())
		{
			frw.clear();
			frw.seekg(0);
		}
		else
		{
			cout << "read file error.\n";
			exit(EXIT_FAILURE);
		}
	}
	else{
		cout << "open file failed.\n";
		exit(EXIT_FAILURE);
	}
	
	int seq;
	cout << "Enter the seq of planet need change: ";
	cin >> seq;
	while(cin.get() != '\n')
		continue;
	if(seq < 0 || seq > ct)
	{
		cout << "Sorry, no this planet!" << endl;
	}
	else
	{
		frw.seekg(seq * sizeof(planet));
		if(frw.fail())
		{
			cerr << "Error on attempted seek\n";
			exit(EXIT_FAILURE);
		}
		cout << "Enter planet name (enter a blank line to quit): " << endl;
		if(cin.get(pl.name, 40))
		{
			cout << "Enter planetary population: ";
			cin >> pl.population;
			cout << "Enter planet's acceleration of gravity: ";
			cin >> pl.gravity;
			while(cin.get() != '\n')
				continue;
			frw.write((char *) &pl, sizeof(planet));
			frw.flush();
			
			
			cout << "\nHere are the current contents of the planets.dat file:\n";
			frw.seekg(0);
			ct = 0;
			frw.read((char *) &pl, sizeof(planet));
			while(frw)
			{
				cout << ct << setw(5) << "# ";
				cout.width(20);
				cout << pl.name << ": " << setprecision(0) << setw(12) <<pl.population
					 << setprecision(2) << setw(6) << pl.gravity << endl;
				frw.read((char *)&pl, sizeof(planet));
				ct++;
			}
		}
		else
		{
			cout << "error input.\n";
		}
	}
	cout << "Bye.\n";
	return 0;
	
	
	
	
	
	
	
	
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
	frw.open(file);
	if(!frw.is_open())
	{
		cerr << "open file " << file << "failed!\n";
		exit(EXIT_FAILURE);
	}
	frw.read((char *) &pl, sizeof(planet));
	while(frw)
	{
		cout.width(20);
		cout << pl.name << ": " << setprecision(0) << setw(12) <<pl.population
			 << setprecision(2) << setw(6) << pl.gravity << endl;
		frw.read((char *)&pl, sizeof(planet));
	}
	frw.close();
	
	cout << "Done.\n";
	return 0;
}