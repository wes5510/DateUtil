#ifndef DATE_UTIL_H
#define DATE_UTIL_H

#include "Error.hxx"

#include <ctime>
#include <cstdlib>
#include <cstdio>

#include <string>

namespace DateUtil
{
	enum ERRNO
	{
		INVALID_YEAR,
		INVALID_MONTH,
		INVALID_DAY
	};

	static const std::string ERR_STR_LIST[] = {"Invalid Year", "Invalid Month", "Invalid Day"};
	static Error error;
	static const unsigned int DAY_OF_SEC = 86400;
	bool getCurDate(struct tm**);
	bool getPreDay(struct tm*, struct tm*, int);
	int getLastDayOfMonth(int, int);
};

#endif
