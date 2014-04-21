#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class BridgeCrossing
        {
        public:
        int minTime(vector <int> times)
        {
            if(times.size() == 1) return times[0];
            if(times.size() == 2) return max(times[0], times[1]);
            sort(times.begin(), times.end());
            if(times.size() == 3) return times[0] + times[1] + times[2];
            int n = times.size();
            int a = times[0], b = times[1], c = times[n-2], d = times[n-1];
            times.pop_back(); times.pop_back();
            if(b+b > a+c) return minTime(times) + 2*a + c + d;
            else          return minTime(times) + 2*b + a + d;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 5, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = { 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 50, 99, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 162; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        BridgeCrossing ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
