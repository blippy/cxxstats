bin_PROGRAMS = cxxstats testcxxstats
EXTRA_DIST = tests-env.sh

cxxstats_LDADD = -lreadline
cxxstats_SOURCES = cxxstats.cc mcstats.cc parse.cc



testcxxstats_SOURCES = testcxxstats.cc mcstats.cc

AM_TESTS_ENVIRONMENT = . ./tests-env.sh
AM_TESTS_FD_REDIRECT = 9>&2
TESTS = tests-env.sh
#TESTS = testcxxstats
