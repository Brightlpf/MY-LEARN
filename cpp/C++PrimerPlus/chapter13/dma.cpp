#include "dma.h"
#include <iostream>
#include <cstring>
using namespace std;
/*
class baseDMA{
private:
	char * label;
	int rating;
	
public:
	baseDMA(const char * l = "null", int r = 0);
	baseDMA(const baseDMA &rs);
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, 
		const baseDMA &rs);
};


class lacksDMA : public baseDMA
{
private:
	enum {COL_LEN = 40};
	char color{COL_LEN};
public:
	lacksDMA{const char *c = "blank", const char * l = "null", 
		int r = 0};
	lacksDMA(const char * c, const baseDMA &rs);
	friend std::ostream & operator<<(std::ostream & os, 
			const lacksDMA &rs);
}

class hasDMA : public baseDMA
{
private:
	char * style;
public:
	hasDMA(const char *s = "none", const char * l = "null", 
		int r = 0);
	hasDMA(const char *s, const baseDMA & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator=(const hasDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, 
		const hasDMA &rs);
}
*/

//baseDMA method

baseDMA::baseDMA(const char * l , int r)
{
	label = new char [strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA &rs)
{
	int len = strlen(rs.label);
	label = new char [len + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA &rs)
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

std::ostream & operator<<(std::ostream &os, 
	const baseDMA &rs)
{
	os << "Label: " << rs.label << endl;
	os << "Rating: " << rs.rating << endl;
	return os;
}


//lacksDMA method
lacksDMA::lacksDMA(const char *c, const char * l, int r) : baseDMA(l, r)
{
	//int len = strlen(c) < COL_LEN ? strlen(c):(COL_LEN - 1);
	
	strncpy(color, c, COL_LEN -1);
	color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA &rs) : baseDMA(rs)
{
	//int len = strlen(c) < COL_LEN ? strlen(c):(COL_LEN - 1);
	
	strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
//how to use fried in derive???
std::ostream & operator<<(std::ostream & os, 
			const lacksDMA &rs)
{
	os << (const baseDMA &)rs;
	os << "Color: " << rs.color << endl;
	return os;
}

//hasDMA method
hasDMA::hasDMA(const char *s , const char * l , 
		int r) : baseDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA & rs): baseDMA(rs)
{
	style = new char [strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs): baseDMA(hs)
{
	//baseDMA::baseDMA((baseDMA)hs); // 强制转换为基类对象？??
	style = new char [strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA &rs)
{
	if(&rs == this)
		return *this;
	baseDMA::operator=(rs);
	delete [] style;
	style = new char [strlen(rs.style) + 1];
	strcpy(style, rs.style);
	
	return *this;
}

std::ostream & operator<<(std::ostream &os, 
	const hasDMA &hs)
{
	os << (const baseDMA &) hs;
	os << "Style: " << hs.style << endl;
	return os;
}


