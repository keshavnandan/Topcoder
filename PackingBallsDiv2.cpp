#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class PackingBallsDiv2
        {
        public:
        int minPacks(int R, int G, int B)
        {
            int s1 = R/3 + G/3 + B/3;
            int a = R%3, b = G%3, c = B%3;
            int s2 = 0;
            int k = a+b+c;
            if(k < 3) s2 = 1;
            if(k == 3){
                if(a < 2 && b < 2 && c < 2) s2 = 1;
                else s2 = 2;
            }
            if(k > 3) s2 = 2;
            return s1 + s2;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 4; int Arg3 = 4; verify_case(0, Arg3, minPacks(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, minPacks(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 5; int Arg3 = 4; verify_case(2, Arg3, minPacks(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 78; int Arg1 = 53; int Arg2 = 64; int Arg3 = 66; verify_case(3, Arg3, minPacks(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 100; int Arg3 = 100; verify_case(4, Arg3, minPacks(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        PackingBallsDiv2 ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
