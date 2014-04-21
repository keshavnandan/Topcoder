#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class YahtzeeScore{
	public:
	 int maxPoints(vector<int> toss){
		int x[7];
		fill(x, x+7, 0);
		for(int i = 0; i < 5; i++)
			x[toss[i]] += toss[i];
		return *max_element(x, x+7);
	}
};
