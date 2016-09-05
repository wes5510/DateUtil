#include "Sec.hxx"

const char SYMBOL = 'S';
const int MAX = 60;

bool Sec::verify(const int val)
{
	if(val > Sec::MAX)
		return false;
	return true;
}
