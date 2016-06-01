#include "mcstats.h"

#include <assert.h>
#include <stdlib.h>
#include <math.h>
//#include <stdio>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;

doubles rs1, rs2 ; // random numbers

bool near4(double a, double b) { return abs(a-b) < pow(10, -4) ;}


void report(bool ok, const char *s)
{
	cout << (ok ? "PASS" : "FAIL") << ": " << s << endl;
}

/** read n doubles */
void readnd(std::ifstream &ifs, int n, std::vector<double> &ds){
	std::string str;
	for(int i=0; i<n; i++){
		std::getline(ifs, str);
		double d = stod(str);
		ds.push_back(d);
	}
}

void test_sort()
{
	std::ifstream ifs;
	ifs.open("../maff/xlsm/sort.txt");
	std::string str;
	std::getline(ifs, str);
	//cout << str << endl;
	int n = stoi(str);
	std::vector<double> ds, ress;
	assert(n>0);
	readnd(ifs, n, ds); // read inputs
	readnd(ifs, n, ress); // read good results
	ifs.close();

	sortd(ds);
	bool ok = true;
	for(int i=0; i<n; i++){ if(ds[i] != ress[i]) ok = false; }
	//if(ok) cout << "PASS: "; else cout << "FAIL: ";
	//cout << "sort" << endl;
	report(ok, "sortd");
}

void read_pairs(char *filename, std::vector<double> &vs1, std::vector<double> &vs2)
{
	std::ifstream ifs;
	ifs.open(filename);
	std::string s;
	std::getline(ifs, s);
	int n = stoi(s);
	assert(n>0);
	for(int i=0; i<n; i++) {
		//std::getline(ifs, s);
		double d1, d2;
		ifs >> d1  >> d2;
		//sscanf(s.c_str(), "%f %f", &d1, &d2);
		/*
		double d = stod(s);
		vs1.push_back(d);
		std::getline(ifs, s);
		d = stod(s);
		vs2.push_back(d);
		*/
		//cout << d2 << endl;
		vs1.push_back(d1);
		vs2.push_back(d2);
	}

}
void test_quantile1()
{

	doubles xs = rs1;
	sortd(xs);

	doubles qs1, qs2;
	read_pairs((char *)"../maff/xlsm/quantile1.txt", qs1, qs2);
	bool ok = true;
	for(int i=0; i< qs1.size(); i++) {
		double qt = quantile(xs, qs1[i]);
		if(! near4(qt, qs2[i])) ok = false;
		//cout << qs1[i] << "\t" << qs2[i] << "\t" <<  qt - qs2[i] << endl;
	}

	report(ok, "quantile");
	//if(ok) cout << "PASS: "; else cout << "FAIL: " ;
	//cout << "quantile" << endl;
}

void test_basic_stats()
{
	std::ifstream ifs;
	ifs.open("../maff/xlsm/stats.txt");
	double dummy, mean, stdev;
	ifs >> dummy >> mean >> stdev ;
	ifs.close();

	stats s;
	basic_stats(rs1, s);
	bool ok = near4(s.mean, mean ) && near4(s.stdev , stdev);
	//cout << s.n << " " << s.mean << " " << s.stdev;
	report(ok, "basic stats");
}


void test_frank()
{
	//auto arr = std::vector<double> { 1.0, 1.0, 2.0, 3.0, 3.0, 4.0, 5.0, 5.0, 5.0 };
	auto arr = std::vector<double> { 2.0, 5.0, 1.0, 3.0, 4.0, 5.0, 5.0, 1.0, 3.0 };
	auto res = frank(arr);
	auto expected = std::vector<double> { 3.0, 8.0, 1.5, 4.5, 6.0, 8.0, 8.0, 1.5, 4.5 };
	report(res == expected, "fractional rank");
	//for(auto r:res) { cout << r << "\n" ; }
}


int main()
{
	test_sort();

	read_pairs((char *)"../maff/xlsm/random1.txt", rs1, rs2);
	
	test_quantile1();
	test_basic_stats();
	test_frank();

	return EXIT_SUCCESS;
}
