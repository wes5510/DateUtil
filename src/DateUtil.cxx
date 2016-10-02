#include "DateUtil.hxx"

bool DateUtil::getCurDate(struct tm** date)
{
	const time_t t = time(0);
	*date = localtime(&t);
	if(*date == NULL)
	{
		error.set();
		return false;
	}

	return true;
}

bool DateUtil::getPreDay(struct tm* preDate, struct tm* curDate, int termDay)
{
	memset(preDate, 0, sizeof(struct tm));
	time_t curDateTimeT = mktime(curDate);
	if(curDateTimeT == -1)
	{
		error.set();
		return false;
	}

	time_t preDateTimeT = curDateTimeT - (termDay * DAY_OF_SEC);

	preDate = localtime(&preDateTimeT);
	if(preDate == NULL)
	{
		error.set();
		return false;
	}

	return true;
}

int DateUtil::getLastDayOfMonth(int year, int month)
{
	if(year < 1)
	{
		error.set(INVALID_YEAR, ERR_STR_LIST[INVALID_YEAR]);
		return -1;
	}

	if(month < 1 || month > 12)
	{
		error.set(INVALID_MONTH, ERR_STR_LIST[INVALID_MONTH]);
		return -1;
	}

	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if(month == 4 || month == 6 || month == 9 || month == 11)
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
