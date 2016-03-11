#include "mcstats.h"

#include <assert.h>
#include <stdlib.h>
//#include <stdio>
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;

/** read n doubles */
void readnd(std::ifstream &ifs, int n, std::vector<double> &ds){
	std::string str;
	for(int i=0; i<n; i++){
		std::getline(ifs, str);
		double d = stod(str);
		ds.push_back(d);
	}
}

int main()
{
	// test sorting
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
	if(ok) cout << "PASS: "; else cout << "FAIL: ";
	cout << "sort" << endl;
		// cout << ds[i] << endl;
	return EXIT_SUCCESS;
}
