#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Unique
        {
        public:
        string removeDuplicates(string S)
            {
                int c[1000];
                string ret;
                for(int i = 'a'; i <= 'z'; i++) c[i] = 0;
                for(int i = 0; i < S.size(); i++){
                    if(c[S[i]] == 0){
                        c[S[i]] = 1;
                        ret += S[i];
                    }
                }
                return ret;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "banana"; string Arg1 = "ban"; verify_case(0, Arg1, removeDuplicates(Arg0)); }
	void test_case_1() { string Arg0 = "aardvark"; string Arg1 = "ardvk"; verify_case(1, Arg1, removeDuplicates(Arg0)); }
	void test_case_2() { string Arg0 = "xxxxx"; string Arg1 = "x"; verify_case(2, Arg1, removeDuplicates(Arg0)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "topcder"; verify_case(3, Arg1, removeDuplicates(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        Unique ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
