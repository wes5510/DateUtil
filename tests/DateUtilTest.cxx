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
