#ifndef DATE_UTIL_H
#define DATE_UTIL_H

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>

#include <string>

namespace DateUtil
{
	enum ERRNO
	{
		INVALID_YEAR,
		INVALID_MONTH,
		INVALID_DAY
	};

	const std::string ERR_STR_LIST[] = {"Invalid Year", "Invalid Month", "Invalid Day"};
	static const unsigned int DAY_OF_SEC = 86400;
	static std::string lastErrorStr;
	static int lastErrorNo;
	bool getCurDate(struct tm**);
	bool getPreDay(struct tm* preDate, struct tm* curDate, int termDay);
	int getLastDayOfMonth(int, int);
}

#endif
