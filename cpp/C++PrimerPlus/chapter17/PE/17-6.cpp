#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "store.h"

using namespace std;
void ShowStrs(const string & str);
void GetStrs(ifstream & finput, vector<string> & vs);
int main()
{
	
	vector<string> vostr;
	string temp;
	
	//acquire stringstream
	cout << "Enter strings(empty line to quit): \n";
	while(getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStrs);
	
	//store in a file
	ofstream fout("string.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	
	//recover file contents
	vector<string> vistr;
	ifstream fin("string.dat", ios_base::in | ios_base::binary);
	if(!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file: \n";
	for_each(vistr.begin(), vistr.end(), ShowStrs);
	
	return 0;
}


void ShowStrs(const string & str)
{
	cout << str << endl;
}

void Store::operator()(const string & str)
{
	int len = str.size() > MAX ? MAX : str.size();
	int i;
	for(i = 0; i < str.size(); i++)
		m_arr[i] = str[i];
	m_arr[i] = '\0';
	m_fout.write((char *)&len, sizeof(int));
	m_fout.write(m_arr, len);
}

void GetStrs(ifstream & finput, vector<string> & vs)
{
	string temp;
	int len;
	char arr[80];
	while(finput)
	{
		finput.read((char *)&len, sizeof(int));
		cout << "Debug********** len = " << len << "**********Debug\n";
		if(finput.eof())
		{
			cout << "read file eof" << endl;
			break;
		}
		finput.read(arr, len);
		cout << "Debug********** arr = " << arr << "**********Debug\n";
		temp = arr;
	
		vs.push_back(temp);
	}
	
}
