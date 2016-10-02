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
	DateUtil::getPreDate(&preDate, &date, 1);

	ASSERT_EQ(preDate.tm_year, 115);
	ASSERT_EQ(preDate.tm_mon, 11);
	ASSERT_EQ(preDate.tm_mday, 31);

	DateUtil::getPreDate(&preDate, &date, 600);

	ASSERT_EQ(preDate.tm_year, 114);
	ASSERT_EQ(preDate.tm_mon, 4);
	ASSERT_EQ(preDate.tm_mday, 11);
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
