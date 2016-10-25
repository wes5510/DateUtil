#ifndef DATE_UTIL_H
#define DATE_UTIL_H

#include "Error.hxx"

#include <ctime>
#include <cstdlib>
#include <cstdio>

#include <string>

namespace DateUtil
{
	static const unsigned short MIN_YEAR = 0;
	static const unsigned short MIN_MONTH = 0;
	static const unsigned short MAX_MONTH = 11;
	static const unsigned short MIN_DAY = 1;
	static const unsigned short MAX_DAY = 31;
	static const unsigned short MIN_HOUR = 0;
	static const unsigned short MAX_HOUR = 23;
	static const unsigned short MIN_MIN = 0;
	static const unsigned short MAX_MIN = 59;
	static const unsigned short MIN_SEC = 0;
	static const unsigned short MAX_SEC = 61;
	static const unsigned short MIN_WDAY = 0;
	static const unsigned short MAX_WDAY = 6;
	static const unsigned short MIN_YDAY = 0;
	static const unsigned short MAX_YDAY = 365;
	static const unsigned short MIN_ISDST = 0;

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

	static const std::string ERR_STR_LIST[] = {"Invalid Year", "Invalid Month", "Invalid Day", "Invalid Hour"
												, "Invalid Min", "Invalid Sec", "Invalid Wday", "Invalid Yday"
												, "Invalid Isdst"};
	static Error ERROR;
	static const unsigned int DAY_OF_SEC = 86400;
	bool getCurDate(struct tm*);
	bool getLocalTime(struct tm**);
	bool getPreDate(struct tm*, struct tm*, int);
	int  getLastDayOfMonth(int, int);
	bool tmToStr(std::string tmStr, struct tm& t);
	bool varifyStructTm(struct tm* t);
	bool varifyYear(int);
	bool varifyMonth(int);
	bool varifyDay(int);
	bool varifyHour(int);
	bool varifyMin(int);
	bool varifySec(int);
	bool varifyWday(int);
	bool varifyYday(int);
	bool varifyIsdst(int);
};

#endif
