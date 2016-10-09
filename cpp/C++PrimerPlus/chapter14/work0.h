#ifndef WORK0_H_
#define WORK0_H_

class Worker{
private:
	std::string fullname;
	long id;
public:
	Worker(): fullname("no one"), id(0){}
	Worker(const std::string f, long i) : fullname(f), id(i){}
	virtual ~Worker() = 0;
	virtual void Show() const;
	virtual void Set();
};

class Waiter : public Worker
{
private:	
	int panache;
public:
	Waiter() : Worker(), panache(0){}
	Waiter(const std::string & f, long i, int p) :Worker(f, i), panache(0){}
	Waiter(const Worker & w, int p) : Worker(w), panache(0) {}
	virtual ~Waiter();
	virtual void Show() const;
	virtual void Set();
};

class Singer : public Worker
{
protected:
	enum {other, alto, contralto, soprano, bass, baritone, tenor};
	enum {Vtypes = 7};
private:
	static char *pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const std::string & s, long n, int v = other) 
		: Worker(s, n), voice(v){}
	Singer(const Worker & w, int v) : Worker(w), voice(v){}
	virtual void Set();
	virtual void Show() const;
};
#endif
