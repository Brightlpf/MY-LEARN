#ifndef WORK0_H_
#define WORK0_H_

class Worker{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker(): fullname("no one"), id(0){}
	Worker(const std::string f, long i) : fullname(f), id(i){}
	virtual ~Worker() = 0;
	virtual void Show() const = 0;
	virtual void Set() = 0;
};

class Waiter : virtual public Worker
{
private:	
	int panache;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Waiter() : Worker(), panache(0){}
	Waiter(const std::string & f, long i, int p) :Worker(f, i), panache(0){}
	Waiter(const Worker & w, int p) : Worker(w), panache(0) {}
	virtual ~Waiter();
	virtual void Show() const;
	virtual void Set();
};

class Singer : virtual public Worker
{
protected:
	enum {other, alto, contralto, soprano, bass, baritone, tenor};
	enum {Vtypes = 7};
	void Data() const;
	void Get();
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

//multiple inherritance
class SingingWaiter : public Singer, public Waiter
{
protected:
	virtual void Data() const;
	virtual void Get();
public:	
	SingingWaiter(){}
	SingingWaiter(const std::string &s, long n, int p = 0, 
		int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, v){}
	SingingWaiter(const Worker &wk, int p = 0, int v = other)
		:Worker(wk), Waiter(wk, p), Singer(wk, v){}
	SingingWaiter(const Waiter &wt, int v = other)
		:Worker(wt), Waiter(wt), Singer(wt, v){}
	SingingWaiter(const Singer &wt, int p =0)
		:Worker(wt), Waiter(wt, p), Singer(wt){}
	void Set();
	void Show() const;
};

#endif
