#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[])
{
	using namespace std;
	
	if(argc != 4)
	{
		cerr << "usage " << argv[0] << "inputfile1 inputfile2 outputfile" << endl;
		exit(1);
	}
	
	ifstream fin1(argv[1]);
	ifstream fin2(argv[2]);
	ofstream fout(argv[3]);
	
	string str1;
	string str2;
	/*
	while(getline(fin1, str1) && getline(fin2, str2))
	{
		cout << "all input file: " << endl;
		str1[str1.size() - 1] = ' ';
		fout << str1 + str2;
	}
	if(!fin1.eof() && !fin2.eof())
	{
		cerr << "read file error." << endl;
		exit(1);
	}
	while(!fin1.eof())
	{
		fout << str1;
		getline(fin1, str1);
	}
	while(!fin2.eof())
	{
		fout << str2;
		getline(fin2, str2);
	}
	*/
	while(getline(fin1, str1))
	{
		if(getline(fin2, str2))
		{
			str1[str1.size() - 1] = ' ';
			fout << str1 + str2;
		}
		else
		{
			fout << str1;
		}
	}
	while(getline(fin2, str2))
	{
		fout << str2;
	}
	fin1.close();
	fin2.close();
	fout.close();
	
	return 0;
}
