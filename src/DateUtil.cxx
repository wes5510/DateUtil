#include "DateUtil.hxx"

void SetError()
{
	DateUtil::lastErrorNo = errno;
	DateUtil::lastErrorStr = strerror(errno);
}

template<typename T>
void SetError(DateUtil::ERRNO errno, T value)
{
	DateUtil::lastErrorNo = errno;
	DateUtil::lastErrorStr = DateUtil::ERR_STR_LIST[errno] + "(" + value + ")";
}

bool DateUtil::getCurDate(struct tm** date)
{
	const time_t t = time(0);
	*date = localtime(&t);
	if(*date == NULL)
	{
		SetError();
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
		SetError();
		return false;
	}

	time_t preDateTimeT = curDateTimeT - (termDay * DAY_OF_SEC);

	preDate = localtime(&preDateTimeT);
	if(preDate == NULL)
	{
		SetError();
		return false;
	}

	return true;
}

int DateUtil::getLastDayOfMonth(int year, int month)
{
	if(year < 1)
	{
		//SetError(INVALID_YEAR, year);
		return -1;
	}

	if(month < 1 || month > 13)
	{
		SetError(INVALID_MONTH, month);
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
