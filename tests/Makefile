include ../config.mak

LFLAGS 		= $(GTEST_LIB)
LFLAGS 		+= -lpthread

EXEC 		= test

SRC_OBJS 	= ../src/Error.o ../src/DateUtil.o
OBJS 		= $(SRC_OBJS) ErrorTest.o DateUtilTest.o 

.SUFFIXES: .cxx .o .hxx .pc

.cxx.o:
	$(CXX) $(INCLUDE) $(CFLAGS) $<

all: $(EXEC)

$(EXEC) : $(OBJS)
	$(CXX) $(OFLAGS) $@ $(OBJS) $(LFLAGS)

clean:
	$(RM) $(EXEC) *.o core.*
