#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class MagicalStringDiv2
        {
        public:
        int minimalMoves(string S)
            {
                int n = S.size();
                int c1 = 0, c2 = 0;
                for(int i = 0; i < n/2; i++) if(S[i] == '<') c1++;
                for(int i = n/2; i < n; i++) if(S[i] == '>') c1++;
                return c1+c2;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ">><<><"; int Arg1 = 2; verify_case(0, Arg1, minimalMoves(Arg0)); }
	void test_case_1() { string Arg0 = ">>>><<<<"; int Arg1 = 0; verify_case(1, Arg1, minimalMoves(Arg0)); }
	void test_case_2() { string Arg0 = "<<>>"; int Arg1 = 4; verify_case(2, Arg1, minimalMoves(Arg0)); }
	void test_case_3() { string Arg0 = "<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><"; int Arg1 = 20; verify_case(3, Arg1, minimalMoves(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        MagicalStringDiv2 ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
