#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class FizzBuzzTurbo
        {
        public:
        vector<long long> counts(long long A, long long B)
            {
                long long a = B/3 - A/3;
                long long b = B/5 - A/5;
                long long c = B/15 - A/15;
                if(A%3 == 0) a++;
                if(A%5 == 0) b++;
                if(A%15 == 0) c++;
                long long fb = c, fz = a - c, bz = b - c;
                vector<long long> v;
                v.push_back(fz);
                v.push_back(bz);
                v.push_back(fb);
                return v;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 4LL; long Arr2[] = {1, 0, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, counts(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 2LL; long long Arg1 = 6LL; long Arr2[] = {2, 1, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, counts(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 150LL; long long Arg1 = 165LL; long Arr2[] = {4, 2, 2 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, counts(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 474747LL; long long Arg1 = 747474LL; long Arr2[] = {72728, 36363, 18182 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, counts(Arg0, Arg1)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        FizzBuzzTurbo ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
