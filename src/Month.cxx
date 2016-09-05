#include "Month.hxx"

const char SYMBOL = 'M';
const int MAX = 12;

bool Month::verify(const int val)
{
	if(val > Month::MAX)
		return false;
	return true;
}
