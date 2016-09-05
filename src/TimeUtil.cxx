#include "TimeUtil.hxx"

char getDateFormatSymbol(int dateTypesymbol)
{
	if(dateTypesymbol >= DateUtil::YEAR && dateTypesymbol <= DateUtil::MSEC)
		return dateTypeSymbols[dateTypesymbol];

	return NULL;
}

void TimeUtil::getPridate(char* date, int term)
{
	struct tm* now = NULL;
	getCurTime(&now);
	sprintf(date, "%04d%02d%02d", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday - term);
}

void TimeUtil::getCurTime(struct tm** date)
{
	const time_t t = time(0);
	*date = localtime(&t);
}

/*
 * @parm	std::string		time		time string(ex : 20160904111201032)
 * @parm	std::string		timeFormat	time format stirng 
 * 										(Year = Y, Month = M, Day = D, 
 * 										Hour = H, Min = M, Sec = S, mSec = s)
 * @return	bool			verify return value;
 */

bool TimeUtil::verifyDateStr(const std::string& time, const std::string& timeFormat)
{
	if(timeFormat.length() != time.length())
		return false;

	if(!verifyDateType(const std::string& timeFormat))
		return false;

	std::size_t symbolFirstPos = timeFormat.find_first_of(TimeUtil::monthFormatSymbol);
	std::size_t symbolLastPos = timeFormat.find_last_of(TimeUtil::monthFormatSymbol);
	if(symbolFirstPos != std::string::npos && symbolLastPos != std::string::npos)
	{
		if(atoi(time.substr(symbolFirstPos, symbolLastPos).c_str()) > maxMonth)
			return false;
	}

	symbolFirstPos = timeFormat.find_first_of(TimeUtil::dayFormatSymbol);
	symbolLastPos = timeFormat.find_last_of(TimeUtil::dayFormatSymbol);
	if(symbolFirstPos != std::string::npos && symbolLastPos != std::string::npos)
	{
		if(atoi(time.substr(symbolFirstPos, symbolLastPos).c_str()) > maxDay)
			return false;
	}

	symbolFirstPos = timeFormat.find_first_of(TimeUtil::hourFormatSymbol);
	symbolLastPos = timeFormat.find_last_of(TimeUtil::hourFormatSymbol);
	if(symbolFirstPos != std::string::npos && symbolLastPos != std::string::npos)
	{
		if(atoi(time.substr(symbolFirstPos, symbolLastPos).c_str()) > maxHour)
			return false;
	}

	symbolFirstPos = timeFormat.find_first_of(TimeUtil::minFormatSymbol);
	symbolLastPos = timeFormat.find_last_of(TimeUtil::minFormatSymbol);
	if(symbolFirstPos != std::string::npos && symbolLastPos != std::string::npos)
	{
		if(atoi(time.substr(symbolFirstPos, symbolLastPos).c_str()) > maxMin)
			return false;
	}

	symbolFirstPos = timeFormat.find_first_of(TimeUtil::secFormatSymbol);
	symbolLastPos = timeFormat.find_last_of(TimeUtil::secFormatSymbol);
	if(symbolFirstPos != std::string::npos && symbolLastPos != std::string::npos)
	{
		if(atoi(time.substr(symbolFirstPos, symbolLastPos).c_str()) > maxSec)
			return false;
	}

	symbolFirstPos = timeFormat.find_first_of(TimeUtil::mSecFormatSymbol);
	symbolLastPos = timeFormat.find_last_of(TimeUtil::mSecFormatSymbol);
	if(symbolFirstPos != std::string::npos && symbolLastPos != std::string::npos)
	{
		if(atoi(time.substr(symbolFirstPos, symbolLastPos).c_str()) > maxMSec)
			return false;
	}

	return true;
}
