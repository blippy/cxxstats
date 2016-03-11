.PHONY : all clean

all : cxxstats


parse.o : parse.cc parse.h
	g++ -ggdb -c $< -o $@

cxxstats : cxxstats.cc parse.o
	g++ -std=gnu++11 -ggdb $^ -o $@ -lreadline

