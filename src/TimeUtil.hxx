#ifndef TIME_UTIL_H
#define TIME_UTIL_H

#include <ctime>
#include <cstdlib>
#include <cstdio>

#include <string>

namespace DateUtil
{
	char getDateFormatSymbol(int dateTypesymbol);

	void getCurTime(struct tm** date);
	void getYesterday(char* date);
	bool verifyDateStr(const std::string& time, const std::string& timeFormat);
}

#endif
