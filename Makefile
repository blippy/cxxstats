CXX = g++
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

cxxstats : cxxstats.cc $(LIB)
	$(CXX) $(AMFLAGS)  $^ -o $@ -lreadline

test_cxxstats : test_cxxstats.cc mcstats.o
	$(CXX) $(AMFLAGS) $^ -o $@ -lm
