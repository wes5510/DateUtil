include ../config.mak

LFLAGS	= $(BOOST_LIB) 

EXEC 	= main

OBJS 	= main.o Year.o Month.o Day.o Hour.o Min.o Sec.o MSec.o DateFormat.o

.SUFFIXES: .cxx .o .hxx

.cxx.o:
	$(CXX) $(CFLAGS) $<

all: $(EXEC)

$(EXEC) : $(OBJS)
	$(CXX) $(LFLAGS) $(OFLAGS) $@ $(OBJS)

clean:
	$(RM) $(EXEC) *.o core.*
