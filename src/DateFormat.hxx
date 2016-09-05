#ifndef TIME_FORMAT_H
#define TIME_FORMAT_H

#include "DateType.hxx"
#include "Year.hxx"
#include "Month.hxx"
#include "Day.hxx"
#include "Hour.hxx"
#include "Min.hxx"
#include "Sec.hxx"
#include "MSec.hxx"

#include <cstring>

#include <string>

class DateFormat
{
	private:
		static enum DateType
		{
			YEAR,
			MONTH,
			DAY,
			HOUR,
			MIN,
			SEC,
			MSEC
		} DateType;

		static const unsigned short DateTypeCount;
		static const DateType* dateTypes[7];

	public:
		~DateFormat();
		static bool verify(std::string& dateFormat);
};

#endif
