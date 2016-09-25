include ../config.mak

LFLAGS 		= $(GTEST_LIB)

EXEC 		= test

SRC_OBJS 	= ../src/DateUtil.o
OBJS 		= $(SRC_OBJS) DateUtilTest.o

.SUFFIXES: .cxx .o .hxx .pc

.cxx.o:
	$(CXX) $(INCLUDE) $(CFLAGS) $<

all: $(EXEC)

$(EXEC) : $(OBJS)
	$(CXX) $(LFLAGS) $(OFLAGS) $@ $(OBJS) 

clean:
	$(RM) $(EXEC) *.o core.*
