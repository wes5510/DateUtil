#include "Year.hxx"

const char SYMBOL = 'Y';
const int MAX = 9999;

bool Year::verify(const int val)
{
	if(val > Year::MAX)
		return false;
	return true;
}
