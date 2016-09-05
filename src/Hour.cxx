#include "Hour.hxx"

const char SYMBOL = 'H';
const int MAX = 24;

bool Hour::verify(const int val)
{
	if(val >= Hour::MAX)
		return false;
	return true;
}
