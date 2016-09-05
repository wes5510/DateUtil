#include "MSec.hxx"

const char SYMBOL = 'Y';
const int MAX = 1000;

bool MSec::verify(const int val)
{
	if(val > MSec::MAX)
		return false;
	return true;
}
