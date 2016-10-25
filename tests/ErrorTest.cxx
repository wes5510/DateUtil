#include "../src/Error.hxx"
#include "gtest/gtest.h"

#include <cstring>
#include <cerrno>

#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class ErrorTest : public ::testing::Test
{
	public:
	protected:
		virtual void SetUp(){}
		virtual void TearDown(){}
};

void invokeSysError(Error& error)
{
	int fd = open("noname", O_APPEND);
	if(fd == -1)
		error.set();
}

TEST(ErrorTest, setSysErrorTest)
{
	Error error;
	invokeSysError(error);
	ASSERT_EQ(error.get().first, errno);
	ASSERT_STREQ(error.get().second.c_str(), strerror(errno));
}

TEST(ErrorTest, setCustomErrorTest)
{
	Error error;
	error.set(1, "error");
	ASSERT_EQ(error.get().first, 1);
	ASSERT_STREQ(error.get().second.c_str(), "error");
}
