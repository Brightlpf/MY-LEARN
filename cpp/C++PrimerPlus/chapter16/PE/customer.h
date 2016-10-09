
class Customer{
private:
	long arrivetime; 
	long processtime;
public:
	Customer(){arrivetime = 0; processtime = 0;}
	void set(long when);
	long when() const { return arrivetime;}
	int ptime() const {return processtime;}
};
