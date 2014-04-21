// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class LittleElephantAndString
        {
        public:

        int getNumber(string A, string B)
            {
                if(A == B) return 0;
                //check if A can be converted to B at all
                if(multiset<char>(A.begin(), A.end()) != multiset<char>(B.begin(), B.end())) return -1;
                int n = A.size();
                //search for i such that B[i+1..n] is a subsequence of A
                int j = n-1, i;
                for(i = n-1; i >=0; i--){
                    while(j >= 0 && A[j] != B[i]) j--;
                    if(j < 0) return i+1;
                    j--;
                }
                //length of string B[0..i] is i+1
                return i+1;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABABABAB"; string Arg1 = "BBAABBAA"; int Arg2 = 3; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "FXTLSGYPSFADPOOEFXZBCOEJUVPVAB"; string Arg1 = "PAFOVEUSCOJBADSELXBGVTFXPZPOFY"; int Arg2 = 28; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABXYZ"; string Arg1 = "BAXYZ"; int Arg2 = 1; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "IAIHHIDIDHBAHDEJGFB"; string Arg1 = "IAIDHJAHHIBDGFIBDHE"; int Arg2 = 16; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "KASVWSR"; string Arg1 = "AVSRSKW"; int Arg2 = 5; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZAAAAAAAAAAAAAAAAAAA"; string Arg1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZ"; int Arg2 = 19; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        LittleElephantAndString ___test;
        ___test.run_test(-1);
        return 0;
        }
    // END CUT HERE
