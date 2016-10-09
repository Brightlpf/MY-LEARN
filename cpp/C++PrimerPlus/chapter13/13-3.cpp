#include <iostream>
#include <cstring>
#include "13-3.h"
using namespace std;

//class adc
DmaABC::DmaABC(const char * l, int r)
{
	label = new char [strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

DmaABC::DmaABC(const DmaABC &rs)
{
	int len = strlen(rs.label);
	label = new char [len + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

DmaABC::~DmaABC()
{
	delete [] label;
}

void DmaABC::View() const
{
	cout << "label: " << label << endl;
	cout << "rating: " << rating << endl;
}

DmaABC & DmaABC::operator=(const DmaABC &rs)
{
	if(&rs == this)
		return *this;
	delete [] label;
	int len = strlen(rs.label);
	label = new char [len + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
	
	return *this;
}

std::ostream & operator<<(std::ostream &os, const DmaABC & ra)
{
	cout << "label: " << ra.label << endl;
	cout << "rating: " << ra.rating << endl;	
}

//baseDMA method
baseDMA::baseDMA(const char * l , int r) : DmaABC(l, r)
{}

baseDMA::baseDMA(const baseDMA &rs): DmaABC(rs)
{}

baseDMA::~baseDMA()
{}

void baseDMA::View() const
{
	DmaABC::View();
}

baseDMA & baseDMA::operator=(const baseDMA &rs)
{
	if(&rs == this)
		return *this;
	DmaABC::operator=(rs);
	
	return *this;
}

std::ostream & operator<<(std::ostream &os, const baseDMA & ra)
{
	os <<(const DmaABC & )ra;
	return os;
}

//lacksDMA method
lacksDMA::lacksDMA(const char *c, const char * l, int r) : DmaABC(l, r)
{	
	strncpy(color, c, COL_LEN -1);
	color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA &rs) : DmaABC(rs)
{
	strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const
{
	DmaABC::View();
	cout << "color: " << color << endl;
}

std::ostream & operator<<(std::ostream &os, const lacksDMA & ra)
{
	os << (const DmaABC &)ra;
	os << "color: " << ra.color << endl;
}
//hasDMA method
hasDMA::hasDMA(const char *s , const char * l , 
		int r) : DmaABC(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA & rs): DmaABC(rs)
{
	style = new char [strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs): DmaABC(hs)
{
	//baseDMA::baseDMA((baseDMA)hs); // 强制转换为基类对象？??
	style = new char [strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

void hasDMA::View() const
{
	DmaABC::View();
	cout << "style: " << style << endl;
}

hasDMA & hasDMA::operator=(const hasDMA &rs)
{
	if(&rs == this)
		return *this;
	DmaABC::operator=(rs);
	delete [] style;
	style = new char [strlen(rs.style) + 1];
	strcpy(style, rs.style);
	
	return *this;
}

std::ostream & operator<<(std::ostream &os, const hasDMA & ra)
{
	os << (const DmaABC &)ra;
	os << "style: " << ra.style << endl;
}

