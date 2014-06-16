#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class BuildingHeightsEasy {
        public:
        int minimum(int N, vector <int> heights)
        {
            sort(heights.rbegin(), heights.rend());
            int sol = 1000000000;
            int n = heights.size();
            for(int i = 0; i <= n-N; i++){
                int sum = 0;
                int rh = heights[i];
                for(int j = i; j - i < N && j < n; j++) sum += (rh - heights[j]);
                sol = min(sol, sum);
//                cout<<i<<" "<<sol<<endl;
            }
            return sol;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 2, 1, 4, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, minimum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1, 3, 5, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, minimum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {43, 19, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {19, 23, 9, 12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(3, Arg2, minimum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; int Arr1[] = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; verify_case(4, Arg2, minimum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        BuildingHeightsEasy ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
