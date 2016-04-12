// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FoxAndClassroom
        {
        public:
        int gcd(int a, int b)
        {
            for (;;)
            {
                if (a == 0) return b;
                b %= a;
                if (b == 0) return a;
                a %= b;
            }
        }

        string ableTo(int n, int m)
            {
                if(gcd(n,m) != 1)
                return "Impossible";
                return "Possible";
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "Impossible"; verify_case(1, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 6; string Arg2 = "Impossible"; verify_case(2, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 6; string Arg2 = "Impossible"; verify_case(3, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 7; string Arg2 = "Possible"; verify_case(4, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 10; string Arg2 = "Impossible"; verify_case(5, Arg2, ableTo(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        FoxAndClassroom ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
