CXX = g++

ifdef ARM
CXX = arm-linux-gnueabihf-gcc
ARM_INC = -I$(HOME)/cubie/usr/include
ARM_LIB = -L$(HOME)/cubie/usr/lib/arm-linux-gnueabihf  -L/usr/arm-linux-gnueabihf/lib
endif

AMFLAGS = -std=gnu++11 -ggdb
BINS = cxxstats test_cxxstats
LIB = libcxxstats.a

.PHONY : all clean

all : $(BINS)

clean : 
	rm -f *.o $(BINS) $(LIB)

$(LIB): parse.o mcstats.o
	ar rcs $(LIB) $^

parse.o : parse.cc parse.h
	$(CXX) $(AMFLAGS) -c $< -o $@

mcstats.o : mcstats.cc mcstats.h
	$(CXX) $(AMFLAGS) -c $< -o $@

cxxstats.o : cxxstats.cc 
	$(CXX) $(AMFLAGS) $(ARM_INC) -c $< -o $@

cxxstats : cxxstats.o $(LIB)
	$(CXX) $(AMFLAGS)  $^ $(ARM_LIB) -lreadline -o $@

test_cxxstats : test_cxxstats.cc mcstats.o
	$(CXX) $(AMFLAGS) $^ -o $@ -lm
