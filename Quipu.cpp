// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

class Quipu
        {
        public:
        int readKnots(string knots)
            {
                char s[1024];
//                stringstream ss(s);
                int ret = 0;
                int i = 1;
                while(i < knots.size()-1){
                    int j = 0;
                    while(knots[i] == 'X') {
                        i++;
                        j++;
                    }
                    cout<<"j = "<<j<<endl;
                    ret = 10*ret + j;
                    while(i < knots.size()-1 && knots[++i] != 'X')  ret *= 10;
                }
                cout<<"ret = "<<ret<<endl;
                return ret;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-XX-XXXX-XXX-"; int Arg1 = 243; verify_case(0, Arg1, readKnots(Arg0)); }
	void test_case_1() { string Arg0 = "-XX--XXXX---XXX-"; int Arg1 = 204003; verify_case(1, Arg1, readKnots(Arg0)); }
	void test_case_2() { string Arg0 = "-X-"; int Arg1 = 1; verify_case(2, Arg1, readKnots(Arg0)); }
	void test_case_3() { string Arg0 = "-X-------"; int Arg1 = 1000000; verify_case(3, Arg1, readKnots(Arg0)); }
	void test_case_4() { string Arg0 = "-XXXXXXXXX--XXXXXXXXX-XXXXXXXXX-XXXXXXX-XXXXXXXXX-"; int Arg1 = 909979; verify_case(4, Arg1, readKnots(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        Quipu ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
