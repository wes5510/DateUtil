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
		INVALID_DAY,
		INVALID_HOUR,
		INVALID_MIN,
		INVALID_SEC,
		INVALID_WDAY,
		INVALID_YDAY,
		INVALID_ISDST,
	};

	static const std::string ERR_STR_LIST[] = {"Invalid Year", "Invalid Month", "Invalid Day", "Invalid Hour", "Invalid Min", "Invalid Sec", "Invalid Wday", "Invalid Yday", "Invalid Isdst"};
	static Error ERROR;
	static const unsigned int DAY_OF_SEC = 86400;
	bool getCurDate(struct tm*);
	bool getLocalTime(struct tm**);
	bool getPreDate(struct tm*, struct tm*, int);
	int getLastDayOfMonth(int, int);
	bool varifyStructTm(struct tm* t);
	bool varifyYear(int);
	bool varifyMon(int);
	bool varifyDay(int);
	bool varifyHour(int);
	bool varifyMin(int);
	bool varifySec(int);
	bool varifyWday(int);
	bool varifyYday(int);
	bool varifyIsDst(int);
};

#endif
