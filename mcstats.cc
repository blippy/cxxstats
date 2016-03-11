#include <math.h>
#include "mcstats.h"


/** sort doubles in place */
void sortd (std::vector<double> &xs)
{
	//vecvec_t rows = read_registered_dsv(etransa);
	//vector<double> res;


	// cubie seems to have problems with sorting, so I'll write my own algo: insertion sort
	//                         // https://en.wikipedia.org/wiki/Insertion_sort

	for(int i=0; i< xs.size(); i++) {

		double x = xs[i];
		int j = i-1;
		while(j>=0 && xs[j] > x) {
			xs[j+1] = xs[j];
			j -= 1;
		}
		xs[j+1] = x;
	}



	//for(auto &e : res) { std::cout << e.sym << "\t" << e.dstamp << std::endl; }

	//return res;
}

/** 
 calculates quantiles according to Excel interpolation formula
 https://en.wikipedia.org/wiki/Quantile
 assumes array is sorted
*/
double quantile(std::vector<double> arr, double q)
{
	double res;
	int len = arr.size();
	double hd = (len-1) * q ; //+ 1;
	int hi = floor(hd);	
	if(q == 1) res = arr[len-1];
	else res = arr[hi] + (hd - hi) * (arr[hi+1] - arr[hi]);
	return res;

}				
