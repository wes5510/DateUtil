#include <limits.h>
#include "gtest/gtest.h"
#include "../src/TimeFormat.hxx"

class TimeFormatTest : public ::testing::Test
{
	public:
	protected:
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST_F(TimeFormatTest, verify_test)
{
	DateFormat df;

	std::string timeFormat = "YYYYMM";

	ASSERT_TRUE(df.verify(timeFormat));

	timeFormat = "YDD";
	ASSERT_TRUE(df.verify(timeFormat));

	timeFormat = "YYYYDDMM";
	ASSERT_TRUE(df.verify(timeFormat));

	timeFormat = "YYYYMMDDHHmmSS";
	ASSERT_TRUE(df.verify(timeFormat));

	timeFormat = "YYYYMMDDHHmmSSss";
	ASSERT_TRUE(df.verify(timeFormat));

	timeFormat = "YYYy";
	ASSERT_FALSE(df.verify(timeFormat));

	timeFormat = "YYYyDD";
	ASSERT_FALSE(df.verify(timeFormat));

	timeFormat = "YYYEE";
	ASSERT_FALSE(df.verify(timeFormat));

	timeFormat = "Y@@";
	ASSERT_FALSE(df.verify(timeFormat));

	timeFormat = "2233YYYYY";
	ASSERT_FALSE(df.verify(timeFormat));
}
