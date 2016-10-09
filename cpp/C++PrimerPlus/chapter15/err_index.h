#include <string>
#include <stdexcept>

using std::logic_error;
using std::string;

class err_index : public logic_error
{
public:
	err_index(const string & s);
}; 

err_index::err_index(const string & s) : logic_error(s){}
 
