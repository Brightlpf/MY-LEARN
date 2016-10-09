typedef unsigned long Item;

class List{
private:
	static const int MAX = 10;
	Item items[MAX];
	int index;
public:
	List();
	bool add(const Item & item);
	bool isempty() const;
	bool isfull() const;
	void visit(void (*pf)(Item &));
};
