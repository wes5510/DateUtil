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
	struct tm* date;
	DateUtil::getCurDate(&date);

	ASSERT_EQ(difftime(mktime(date), time(0)), 0);
}

TEST(DateUtilTest, getLastDayOfMonthTest)
{
	int lastDay = DateUtil::getLastDayOfMonth(2016, 1);
	ASSERT_EQ(lastDay, 31);

	lastDay = DateUtil::getLastDayOfMonth(2016, 2);
	ASSERT_EQ(lastDay, 29);

	lastDay = DateUtil::getLastDayOfMonth(2200, 2);
	ASSERT_EQ(lastDay, 28);

	lastDay = DateUtil::getLastDayOfMonth(-1, 2);
	ASSERT_EQ(lastDay, -1);

	lastDay = DateUtil::getLastDayOfMonth(0, 2);
	ASSERT_EQ(lastDay, -1);

	lastDay = DateUtil::getLastDayOfMonth(120, 0);
	ASSERT_EQ(lastDay, -1);

	lastDay = DateUtil::getLastDayOfMonth(120, -1);
	ASSERT_EQ(lastDay, -1);

	lastDay = DateUtil::getLastDayOfMonth(120, 13);
	ASSERT_EQ(lastDay, -1);
}
