#include "Min.hxx"

const char SYMBOL = 'm';
const int MAX = 60;

bool Min::verify(const int val)
{
	if(val > Min::MAX)
		return false;
	return true;
}
