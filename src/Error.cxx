#include "Error.hxx"

void Error::set()
{
	errorVal_.first = errno;
	errorVal_.second = strerror(errno);
}

void Error::set(const int errno_, const std::string& errStr)
{
	errorVal_.first = errno_;
	errorVal_.second = errStr;
}

std::pair<int, std::string>& Error::get()
{
	return errorVal_;
}

void Error::get(std::pair<int, std::string>& errorVal)
{
	errorVal = errorVal_;
}
