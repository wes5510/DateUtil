#include <limits.h>
#include "gtest/gtest.h"
#include "../src/DateUtil.hxx"

#include <ctime>

class DateUtilTest : public ::testing::Test
{
	public:
	protected:
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(DateUtilTest, getCurDateTest)
{
	struct tm date;
	DateUtil::getCurDate(&date);

	ASSERT_EQ(difftime(mktime(&date), time(0)), 0);
}

TEST(DateUtilTest, getPreDayTest)
{
	struct tm date = {0};
	date.tm_year = 2016 - 1900;
	date.tm_mon = 0;
	date.tm_mday = 1;

	struct tm preDate;
	ASSERT_TRUE(DateUtil::getPreDate(&preDate, &date, 1));

	ASSERT_EQ(preDate.tm_year, 115);
	ASSERT_EQ(preDate.tm_mon, 11);
	ASSERT_EQ(preDate.tm_mday, 31);

	ASSERT_TRUE(DateUtil::getPreDate(&preDate, &date, 600));

	ASSERT_EQ(preDate.tm_year, 114);
	ASSERT_EQ(preDate.tm_mon, 4);
	ASSERT_EQ(preDate.tm_mday, 11);

	date.tm_year = 0;
	date.tm_mon = -1;

	ASSERT_FALSE(DateUtil::getPreDate(&preDate, &date, 600));
	std::pair<int, std::string> er;
	DateUtil::ERROR.get(er);
	ASSERT_EQ(er.first, DateUtil::INVALID_YEAR);
}

TEST(DateUtilTest, getLastDayOfMonthTest)
{
	int lastDay = DateUtil::getLastDayOfMonth(2016 - 1900, 0);
	ASSERT_EQ(lastDay, 31);

	lastDay = DateUtil::getLastDayOfMonth(2016 - 1900, 1);
	ASSERT_EQ(lastDay, 29);

	lastDay = DateUtil::getLastDayOfMonth(2200 - 1900, 1);
	ASSERT_EQ(lastDay, 28);

	lastDay = DateUtil::getLastDayOfMonth(-1, 1);
	ASSERT_EQ(lastDay, -1);

	lastDay = DateUtil::getLastDayOfMonth(120, -1);
	ASSERT_EQ(lastDay, -1);

	lastDay = DateUtil::getLastDayOfMonth(120, 12);
	ASSERT_EQ(lastDay, -1);
}

TEST(DateUtilTest, varifyYearTest)
{
	int year = 1;
	ASSERT_TRUE(DateUtil::varifyYear(year));

	year = 116;
	ASSERT_TRUE(DateUtil::varifyYear(year));

	year = -1;
	ASSERT_FALSE(DateUtil::varifyYear(year));
}

TEST(DateUtilTest, varifyMonthTest)
{
	int mon = 0;
	ASSERT_TRUE(DateUtil::varifyMonth(mon));

	mon = 11;
	ASSERT_TRUE(DateUtil::varifyMonth(mon));

	mon = 7;
	ASSERT_TRUE(DateUtil::varifyMonth(mon));

	mon = -1;
	ASSERT_FALSE(DateUtil::varifyMonth(mon));

	mon = 13;
	ASSERT_FALSE(DateUtil::varifyMonth(mon));
}

TEST(DateUtilTest, varifyDayTest)
{
	int day = 1;
	ASSERT_TRUE(DateUtil::varifyDay(day));

	day = 31;
	ASSERT_TRUE(DateUtil::varifyDay(day));

	day = 15;
	ASSERT_TRUE(DateUtil::varifyDay(day));

	day = 0;
	ASSERT_FALSE(DateUtil::varifyDay(day));

	day = 32;
	ASSERT_FALSE(DateUtil::varifyDay(day));
}

TEST(DateUtilTest, varifyHourTest)
{
	int hour = 0;
	ASSERT_TRUE(DateUtil::varifyHour(hour));

	hour = 23;
	ASSERT_TRUE(DateUtil::varifyHour(hour));

	hour = 12;
	ASSERT_TRUE(DateUtil::varifyHour(hour));

	hour = -1;
	ASSERT_FALSE(DateUtil::varifyHour(hour));

	hour = 24;
	ASSERT_FALSE(DateUtil::varifyHour(hour));
}

TEST(DateUtilTest, varifyMinTest)
{
	int min = 0;
	ASSERT_TRUE(DateUtil::varifyMin(min));

	min = 59;
	ASSERT_TRUE(DateUtil::varifyMin(min));

	min = 30;
	ASSERT_TRUE(DateUtil::varifyMin(min));

	min = -1;
	ASSERT_FALSE(DateUtil::varifyMin(min));

	min = 60;
	ASSERT_FALSE(DateUtil::varifyMin(min));
}

TEST(DateUtilTest, varifySecTest)
{
	int sec = 0;
	ASSERT_TRUE(DateUtil::varifySec(sec));

	sec = 61;
	ASSERT_TRUE(DateUtil::varifySec(sec));

	sec = 30;
	ASSERT_TRUE(DateUtil::varifySec(sec));

	sec = -1;
	ASSERT_FALSE(DateUtil::varifySec(sec));

	sec = 62;
	ASSERT_FALSE(DateUtil::varifySec(sec));
}

TEST(DateUtilTest, varifyWdayTest)
{
	int wday = 0;
	ASSERT_TRUE(DateUtil::varifyWday(wday));

	wday = 6;
	ASSERT_TRUE(DateUtil::varifyWday(wday));

	wday = 3;
	ASSERT_TRUE(DateUtil::varifyWday(wday));

	wday = -1;
	ASSERT_FALSE(DateUtil::varifyWday(wday));

	wday = 7;
	ASSERT_FALSE(DateUtil::varifyWday(wday));
}

TEST(DateUtilTest, varifyYdayTest)
{
	int yday = 0;
	ASSERT_TRUE(DateUtil::varifyYday(yday));

	yday = 6;
	ASSERT_TRUE(DateUtil::varifyYday(yday));

	yday = 150;
	ASSERT_TRUE(DateUtil::varifyYday(yday));

	yday = -1;
	ASSERT_FALSE(DateUtil::varifyYday(yday));

	yday = 366;
	ASSERT_FALSE(DateUtil::varifyYday(yday));
}

TEST(DateUtilTest, varifyIsdstTest)
{
	int isdst = 0;
	ASSERT_TRUE(DateUtil::varifyIsdst(isdst));

	isdst = 10;
	ASSERT_TRUE(DateUtil::varifyIsdst(isdst));

	isdst = -1;
	ASSERT_FALSE(DateUtil::varifyIsdst(isdst));

	isdst = -125;
	ASSERT_FALSE(DateUtil::varifyIsdst(isdst));
}

TEST(DateUtilTest,varifyStructTmTest)
{
	struct tm t = {0};
	DateUtil::getCurDate(&t);
	ASSERT_TRUE(DateUtil::varifyStructTm(&t));

	t.tm_year = -1;
	ASSERT_FALSE(DateUtil::varifyStructTm(&t));

	t.tm_mon = -1;
	ASSERT_FALSE(DateUtil::varifyStructTm(&t));
}
