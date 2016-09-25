#ifndef DATE_UTIL_H
#define DATE_UTIL_H

#include <ctime>
#include <cstdlib>
#include <cstdio>

#include <string>

namespace DateUtil
{
	void getCurDate(struct tm** date);
	//bool verifyDateStr(const std::string& time, const TimeFormat& timeFormat);

	class DateFormat
	{
		DateFormat(int yearLen = 4, int monthLen = 2, int dayLen = 2, int hourLen = 2, int minLen = 2, int secLen = 2, int mSecLen = 0, int uSecLen = 0)
		{}
	};
}

#endif
