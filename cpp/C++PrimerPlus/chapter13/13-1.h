#ifndef __13_1_h__
#define __13_1_h__

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	virtual Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
	char favourite[50];

public:
	Classic(const char * s3, const char *s1, const char *s2, int n, double x);
	Classic(const Classic & c);
	Classic();
	//virtual ~Classic();
	virtual void Report() const;
	virtual Classic & operator=(const Classic & c);
};

#endif
