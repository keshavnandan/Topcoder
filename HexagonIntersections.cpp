#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

typedef signed long long i64;  typedef unsigned long long u64;

i64 cx[6] = {-2, -1, 1, 2, 1, -1};
i64 cy[6] = {0, 2, 2, 0, -2, -2};

class HexagonIntersections {
        public:
        int d ;
        int gcd(int x, int y) { return x == 0 ? abs(y) : gcd(y % x, x); }

        int go(int n) { return ((abs(n)/d-1)/3*2 + 1) * d + 1; }

        int count(int x, int y, int x1, int y1) {

            d = gcd(x=x1-x, y=y-y1);
            return max(go(2*x+y), max(go(x+2*y), go(x-y)));
        }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = -2; int Arg2 = 3; int Arg3 = 1; int Arg4 = 4; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = -2004; int Arg1 = -1002; int Arg2 = -2000; int Arg3 = -1000; int Arg4 = 3; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 54; int Arg1 = 93; int Arg2 = 64; int Arg3 = 95; int Arg4 = 11; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 19; int Arg3 = 20; int Arg4 = 26; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 19; int Arg3 = -20; int Arg4 = 40; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        HexagonIntersections ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
