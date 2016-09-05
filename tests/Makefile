include ../config.mak

LFLAGS 		= $(GTEST_LIB)

EXEC 		= test

SRC_OBJS 	= ../src/TimeUtil.o
OBJS 		= $(SRC_OBJS) TimeUtilTest.o

.SUFFIXES: .cxx .o .hxx .pc

.cxx.o:
	$(CXX) $(INCLUDE) $(CFLAGS) $<

all: $(EXEC)

$(EXEC) : $(OBJS)
	$(CXX) $(LFLAGS) $(OFLAGS) $@ $(OBJS) 

clean:
	$(RM) $(EXEC) *.o core.*
