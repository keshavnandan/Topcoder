#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
using namespace std;
struct BettingMoney{
	    int moneyMade(vector<int> amounts, vector<int> centsPerDollar, int finalResult){
		int sum = accumulate(amounts.begin(), amounts.end(), -(1 + .01*centsPerDollar[finalResult])*amounts[finalResult]);
		return sum*100;
	}
};
