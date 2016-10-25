#ifndef ERROR_H
#define ERROR_H

#include <string>

#include <cstring>
#include <cerrno>

class Error
{
	private:
		std::pair<int, std::string> errorVal_;
	public:
		void set();
		void set(const int errno_, const std::string& errStr);
		std::pair<int, std::string>& get();
		void get(std::pair<int, std::string>& errorVal);
};

#endif
