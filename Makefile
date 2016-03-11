BINS = cxxstats test_cxxstats

.PHONY : all clean

all : $(BINS)


parse.o : parse.cc parse.h
	g++ -ggdb -c $< -o $@

cxxstats : cxxstats.cc parse.o
	g++ -std=gnu++11 -ggdb $^ -o $@ -lreadline

test_cxxstats : test_cxxstats.cc mcstats.o
	g++ -std=gnu++11 -ggdb $^ -o $@ -lm
