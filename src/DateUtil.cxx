#include "DateUtil.hxx"

bool DateUtil::getCurDate(struct tm* date)
{
	struct tm* now;
	if(!getLocalTime(&now))
		return false;

	memset(date, 0, sizeof(struct tm));
	memcpy(date, now, sizeof(struct tm));
	return true;
}

bool DateUtil::getLocalTime(struct tm** now)
{
	const time_t t = time(0);
	*now = localtime(&t);
	if(*now == NULL)
	{
		ERROR.set();
		return false;
	}
	return true;
}

bool DateUtil::getPreDate(struct tm* preDate, struct tm* curDate, int termDay)
{
	memset(preDate, 0, sizeof(struct tm));
	if(!varifyStructTm(curDate))
		return false;

	struct tm* now;
	if(!getLocalTime(&now))
		return false;
	
	memcpy(now, curDate, sizeof(struct tm));

	time_t curDateTimeT = mktime(now);
	if(curDateTimeT == -1)
	{
		ERROR.set();
		return false;
	}

	time_t preDateTimeT = curDateTimeT - (termDay * DAY_OF_SEC);

	memcpy(preDate ,localtime(&preDateTimeT),sizeof(struct tm));
	if(preDate == NULL)
	{
		ERROR.set();
		return false;
	}

	return true;
}

int DateUtil::getLastDayOfMonth(int year, int month)
{
	if(!varifyYear(year) || !varifyMon(month))
		return -1;

	if(month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
		return 31;
	else if(month == 3 || month == 5 || month == 8 || month == 10)
		return 30;
	else {
		if(year % 4 == 0) {
			if(year % 100 == 0) {
				if(year % 400 == 0)
					return 29;
				return 28;
			}
			return 29;
		}
		return 28;
	}
	return 31;
}

bool DateUtil::varifyStructTm(struct tm* t)
{
	if(!varifyYear(t->tm_year) 		|| !varifyMon(t->tm_mon) 
		|| !varifyDay(t->tm_mday) 	|| !varifyHour(t->tm_hour) 
		|| !varifyMin(t->tm_min) 	|| !varifySec(t->tm_sec) 
		|| !varifyWday(t->tm_wday) 	|| !varifyYday(t->tm_yday) 
		|| !varifyIsDst(t->tm_isdst))
		return false;

	return true;
}

bool DateUtil::varifyYear(int year)
{
	if(year < 0)
	{
		ERROR.set(INVALID_YEAR, ERR_STR_LIST[INVALID_YEAR]);
		return false;
	}
	return true;
}

bool DateUtil::varifyMon(int mon)
{
	if(mon < 0 || mon > 11)
	{
		ERROR.set(INVALID_MONTH, ERR_STR_LIST[INVALID_MONTH]);
		return false;
	}
	return true;
}

bool DateUtil::varifyDay(int day)
{
	if(day < 1 || day > 31)
	{
		ERROR.set(INVALID_DAY, ERR_STR_LIST[INVALID_DAY]);
		return false;
	}
	return true;
}

bool DateUtil::varifyHour(int hour)
{
	if(hour < 0 || hour > 23)
	{
		ERROR.set(INVALID_HOUR, ERR_STR_LIST[INVALID_HOUR]);
		return false;
	}
	return true;
}

bool DateUtil::varifyMin(int min)
{
	if(min < 0 || min > 59)
	{
		ERROR.set(INVALID_MIN, ERR_STR_LIST[INVALID_MIN]);
		return false;
	}
	return true;
}

bool DateUtil::varifySec(int sec)
{
	if(sec < 0 || sec > 61)
	{
		ERROR.set(INVALID_SEC, ERR_STR_LIST[INVALID_SEC]);
		return false;
	}
	return true;
}

bool DateUtil::varifyWday(int wday)
{
	if(wday < 0 || wday > 6)
	{
		ERROR.set(INVALID_WDAY, ERR_STR_LIST[INVALID_WDAY]);
		return false;
	}
	return true;
}

bool DateUtil::varifyYday(int yday)
{
	if(yday < 0 || yday > 365)
	{
		ERROR.set(INVALID_YDAY, ERR_STR_LIST[INVALID_YDAY]);
		return false;
	}
	return true;
}

bool DateUtil::varifyIsDst(int isdst)
{
	if(isdst < 0)
	{
		ERROR.set(INVALID_ISDST, ERR_STR_LIST[INVALID_ISDST]);
		return false;
	}
	return true;
}
