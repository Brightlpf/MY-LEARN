#ifndef DMA_H_
#define DMA_H_
#include <iostream>


//class ABC
class DmaABC{
private:
	char * label;
	int rating;
public:
	DmaABC(const char * l = "null", int r = 0);
	DmaABC(const DmaABC & ra);
	virtual ~DmaABC();
	virtual void View() const = 0;
	virtual DmaABC & operator=(const DmaABC & ra);
	friend std::ostream & operator<<(std::ostream &os, const DmaABC & ra);
};

//class baseDMA
class baseDMA : public DmaABC
{	
public:
	baseDMA(const char * l = "null", int r = 0);
	baseDMA(const baseDMA &rs);
	virtual ~baseDMA();
	virtual void View() const;
	virtual baseDMA & operator=(const baseDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const baseDMA & ra);
};

//class lackDMA
class lacksDMA : public DmaABC
{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char *c = "blank", const char * l = "null", 
		int r = 0);
	lacksDMA(const char * c, const baseDMA &rs);
	virtual void View() const;
	friend std::ostream & operator<<(std::ostream &os, const lacksDMA & ra);
};

class hasDMA : public DmaABC
{
private:
	char * style;
public:
	hasDMA(const char *s = "none", const char * l = "null", 
		int r = 0);
	hasDMA(const char *s, const baseDMA & rs);
	hasDMA(const hasDMA & hs);
	virtual ~hasDMA();
	virtual void View() const;
	virtual hasDMA & operator=(const hasDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const hasDMA & ra);
};

#endif


