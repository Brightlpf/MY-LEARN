#include <string>
using std::string;

class Bankaccount{
	private:
		string m_name;
		string m_actnum;
		double m_saving;
	public:
		Bankaccount(string name = "test", string actnum = "123456789012345678", double saving = 100000000);
		void show() const;
		bool save(const double money);
		bool get(const double money);
};
