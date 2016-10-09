#ifndef STORE_H_
#define STORE_H_

#include <fstream>
#include <string>

class Store{
private:
	enum{MAX = 80};
	std::ofstream & m_fout; // fstream 不支持拷贝构造
	char m_arr[MAX];
public:
	Store(std::ofstream & fout) : m_fout(fout) {}
	char * data() { return m_arr;}
	void operator()(const std::string & str);
};
#endif


