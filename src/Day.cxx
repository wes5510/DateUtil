#include "Day.hxx"

const char SYMBOL = 'D';
const int MAX = 31;

bool Day::verify(const int val)
{
	if(val > Day::MAX)
		return false;
	return true;
}
